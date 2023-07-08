# (C) Copyright 1999-2003 Microsoft Corporation

package DISPLAY;

    use strict;                # Keep the code clean
    no strict 'refs';          # no strict references

    sub FALSE { return(0); }     # Utility subs
    sub TRUE  { return(1); }

    #---------------------------------------------------#
    # Module level variables
    #---------------------------------------------------#
    my $Version  = "5.1.2250.0"; # Version of this file
    my $DEBUG    = 0;            # Set to 1 for debugging output

    my $Current_INF_File;       # Stores name of the current INF file.
    my $Current_HTM_File;       # Name of the output file to use.

    my @Device_Class_Options;   # Array to store device specific options.

    my %AllModels;              # Array of all models present in INF (Model) = (Type)
    my %DisplayErrorTable  = (6001 => ["Directive %s invalid in this section."],
                              6002 => ["%s takes a single numeric parameter."],
                              6003 => ["The only values %s allows are 0 and 1."],
                              6004 => ["Applet extensions should be installed to HKLM,".
                                       "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Controls Folder\\Display."],
                              6005 => [" Section %s does not contain InstalledDisplayDrivers directive."],
                              6006 => [" CapablilityOverride should contain value of 0x8 but contains value %s"],
                              6007 =>["UseXPModel should not be set"],
                              6008 =>["UseVSConverter should not be set"],
                              6009 =>["UsePSConverter should not be set"],
                              6010 =>["CapabilityOverride is not defined."],
                              6011 =>["%s should not be greater than 16"],
                              6012 =>["StartType value should be set as 3 (SERVICE_DEMAND_START) for Vista display adapter inf's"],
                              6013 =>["Device name used here (%s) should be updated. For Vista inbox display inf's: %s needs to be appended to the Device Name"],
                              6014 =>["FeatureScore Directive's value should be F8 for inbox WDDM drivers"],
                              6015 =>["Install section should have FeatureScore Directive"],
                              6016 =>["Copy Flags value (0x00004000) should be specified for WDDM user mode binaries"],
                              6017 =>["Inbox display INF's should not reference LayoutFile "],
                              6018 =>["Inbox display INF's should not reference CatalogFile"],
                              6019 =>["All inbox Vista inf's should have '3426=windows cd' entry in SourceDisksNames"],
                              6020 =>["All inbox Vista inf's should use 3426 entry in SourceDisksFiles"],
  				  6021 =>["Install section should have RegisterDlls Directive for WDDM drivers "],
  				  6022 =>["32 bit cloneviewhelper dll should be registered for 32 bit OS and 64 bit for 64 bit OS"],
  				  6023 =>["CapabilityOverride directive is only applicable for XDDM inf's"],
  				  6024 =>["FeatureScore Directive's value should be FD for inbox XDDM drivers"],
  				  6025 =>["FeatureScore Directive's value should be FC for 3rd party XDDM drivers"],
  				  6026 =>["FeatureScore Directive's value should be F6 for 3rd party WDDM drivers"],
  				  6027 =>["Inbox Vista inf's date for DriverVer in Version section should not be greater than 08\\21\\2006"], 	
  				  6028 =>["Running on Pre Vista OS, should not have Feature Score directive"],
  				  6029 =>["Running on Vista or later, should have Feature Score directive"], 
                            );
    my %DisplayWarningTable =();

    #array indicating whether the inf being parsed is XDDM or WDDM
    my @DriverModelList;

    #Variable indicating whether Vista or legacy inf is being parsed
    my $IsVistaInf = TRUE;

    #Variable indicating the OS version
    my $OSVer;

    #Variable indicating whether or not to log error 
    my $LogErr = 0;

    #array conatining user mode dll names
    my @UserModeDlls;

    #RegisterDllSectionName
    my $RegisterDllSection;

#---------------------------------------------------#
# Routine for checking device class specific
# directives that occur in common sections verified
# by ChkINF.  Return 0 if directive is unknown or
# 1 if the directive is known (you should also verify
# it and write any appropriate warnings/errors.
#---------------------------------------------------#
sub DCDirective {
    return(0); # return 1 on success
}

#-------------------------------------------------------------------------------------------------#
# Main Entry Point to Device Specific Module. REQUIRED!                                           #
#-- InfCheck() -----------------------------------------------------------------------------------#
sub InfCheck {
    my($Item);
	my $DeviceID;
	my $Section;
    my $SkipUndecorated = 0;

    print(STDERR "\tInvoking Display::InfCheck...\n") if ($DEBUG);

    # Propagate a list of all models found in the INF
    %AllModels  = LearnModels();

    if ( $Current_INF_File->sectionDefined("GeneralConfigData") ) {
        # We should work with this && .NTALPHA if exists
        VerifyGCData("GeneralConfigData");
    }

    # Create an array for each model.
    # Array name is uc(Model) and first element is Model
    foreach $DeviceID (keys(%AllModels)) {
        $Section      = $AllModels{uc $DeviceID}{"DDINSTALL"};
        CheckModel($Section);
    }

	#Need to add OS version check to find issues with Server 2008 inf's
	#This change would mean that the inf will be tested for the OS version the test is running on and not necessarily the OS it was intended for
	# Clean way of doing this would be to get a flag from main chkinf.pm module for logo testing
	# We won't get that flag till late; hence limit this code check to only Server 2008 branch 

       my($MajVer,$MinVer,$Build);
       my @tokens;
       
	# Get the OS version 
	# Pipe the output of the 'ver' command to OSVER
	open (OSVER, "ver |");

	# The first line contains garbage
	my $t = <OSVER>;

	# This is the actual output text from 'ver'. Chop the newline character.
	my $osver = <OSVER>;
	chomp($osver);
	close (OSVER);

	# Retrieve the version from the text
	@tokens = split(/ /, $osver);

	my $ver1 = pop(@tokens);

	($MajVer,$MinVer,$Build) = split(/\./,$ver1);

	$OSVer = $MajVer;

	#Check for the Feature Score directive; if present we assume Vista inf is being parsed
	ChkFeatureScore(); #sets the global variable $IsVistaInf


	#Following tests are only applicable to Vista inf's 
	if($IsVistaInf)
	{
		ChkUserModeDllFlag(); #This function provides a hint as to whether XDDM/WDDM inf is being parsed.

		#Type of inf is determined; Start testing and logging errors
		$LogErr = 1;

		ChkFeatureScore(); #Check the new feature score directive	(XDDM/WDDM)
		ChkStartType(); #Check to see if StartType is set to 3 (Vista inf, both XDDM/WDDM)	
		ChkInstalledDisplayDriver(); #check to see if InstalledDisplayDriver exists (both XDDM/WDDM)
		ChkRegKeys(); #verifies debug related registry keys are not set (both XDDM/WDDM)		
		ChkCapabilityOverride(); #check to see if CapabilityOverride exists (only XDDM)

		#Tests for inbox display INF's
		if(ChkInf::GetGlobalValue("MS_INTERNAL"))
		{
		ChkDeviceNamingScheme(); # Checks the device naming scheme on Vista (both XDDM/LDDM)
		ChkVersionSection();
		ChkSourceDisksNames();
		ChkSourceDisksFiles();
		}	

		if(IsWDDMInf())
		{
			#Call the function again to generate error in inf
			ChkUserModeDllFlag(); #Check the new Copy Flags to Support PNPStop Directive (WDDM)

			#Always call this sub after ChkUserModeDllFlag since it uses global array filled by that function
			ChkTMMDlls();
		}


	}		

#    foreach $DeviceID (keys %AllModels) {
#        $Section      = $AllModels{uc $DeviceID}{"DDINSTALL"};
#        # Check all existing NT/2000 sections
#        if ( $Current_INF_File->sectionDefined("$Section.NT") ) {
#            ProcessDeviceID($DeviceID,"NT",$AllModels{$DeviceID});
#            $SkipUndecorated++;
#        }
#        if ( $Current_INF_File->sectionDefined("$Section.NTX86") ) {
#            ProcessDeviceID($DeviceID,"NTX86",$AllModels{$DeviceID});
#            $SkipUndecorated++;
#        }
#        if ( $Current_INF_File->sectionDefined("$Section.NTIA64") ) {
#            ProcessDeviceID($DeviceID,"NTIA64",$AllModels{$DeviceID});
#            $SkipUndecorated++;
#        }
#        # Only check default if no NT/2000 section is defined
#        if ( $Current_INF_File->sectionDefined("$Section") and (! $SkipUndecorated) ){
#            ProcessDeviceID($DeviceID,"",$AllModels{$DeviceID});
#        }
#    }

}

#---------------------------------------------------#
# Checks whether the inf being parsed is XDDM or WDDM inf
#---------------------------------------------------#
sub IsWDDMInf
{
	my $i;	
	for($i = 0; $i < scalar(@DriverModelList); $i++)
	{
		#print "$DriverModelList[$i]\n";
		if($DriverModelList[$i] eq "WDDM")
		{
			#if one of the new driver model directive is present we assume WDDM inf is being parsed
			return 1;
		}
	}

	return 0;
}

#---------------------------------------------------#
#Verifies the driver does not set following registry keys:
#HKLM\CurrentControlSet\Control\GraphicsDrivers\UseXPModel
#HKLM\Software\Microsoft\Direct3D\UseVSConverter
#HKLM\Software\Microsoft\Direct3D\UsePSConverter
#---------------------------------------------------#

sub ChkRegKeys {
    my %sections = $Current_INF_File->getSections();
    my $section;
    my $count=0;
    my @lines;
    my $line;
    my($RegRoot, $SubKey, $Name, $Flags, $Value);

        foreach $section (%sections) {
		       next if(!defined($section));  #skip null sections
			$count = 0;
			@lines = $Current_INF_File->getSection($section);	
			foreach $line (@lines)
			{
				$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
				
				($RegRoot, $SubKey, $Name, $Flags, $Value) = ChkInf::GetList($line,$Current_INF_File->getIndex($section ,$count));
				
				if ((uc $RegRoot eq "HKLM")&& ($SubKey =~ /SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers/i) && ($Name eq "UseXPModel"))
				{
					if($Value == 1)
					{
						AddDisplayError(6007, $Current_INF_File->getIndex($section ,$count),$section );		
					}
				}

				if ((uc $RegRoot eq "HKLM")&& ($SubKey =~ /Software\\Microsoft\\Direct3D/i))
				{
					if(($Name eq "UseVSConverter")&&($Value == 1))
					{
						AddDisplayError(6008, $Current_INF_File->getIndex($section ,$count),$section );		
					}
					if(($Name eq "UsePSConverter")&&($Value == 1))
					{
						AddDisplayError(6009, $Current_INF_File->getIndex($section,$count),$section );		
					}
				 }
				$count++;
			}
	    }
}

#---------------------------------------------------#
# Verifies that the module contains a "CapabilityOverride" 
# directive in each SoftwareDeviceSettings section.
#---------------------------------------------------#
sub ChkCapabilityOverride {

    my %sections = $Current_INF_File->getSections();
    my $LastValidSection;
    my $section;
    my $count = 0;
    my $find = 0;
    my @lines;
    my $line;
    my ($RegRoot, $SubKey, $Name, $Flags, $Value);

	foreach $section (%sections) {
		next if($section !~ /SoftwareDeviceSettings/i);
			$LastValidSection = $section;
			$count = 0;
			$find = 0;
			@lines = $Current_INF_File->getSection($section);	
			foreach $line (@lines) {
				$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
				 if($line =~ /CapabilityOverride/i) {				 	
				 	$find++;
				 	if(IsWDDMInf())
				 	{
				 		#This directive is only applicable in XDDM
				 		AddDisplayError(6023, $Current_INF_File->getIndex($section,$count),$Value);					 		
				 	}elsif(ChkInf::GetGlobalValue("MS_INTERNAL"))
				 	{				 		
						($RegRoot, $SubKey, $Name, $Flags, $Value) = ChkInf::GetList($line,$Current_INF_File->getIndex($section ,$count));
						if(($Value ne "0x8") && ($Value != 8))
						{
							AddDisplayError(6006, $Current_INF_File->getIndex($section,$count),$Value);					
						}						
					}
				}
				$count++;				
			}	
			if(($find == 0) && (!IsWDDMInf()) && (ChkInf::GetGlobalValue("MS_INTERNAL"))) {
				AddDisplayError(6010, $Current_INF_File->getIndex($LastValidSection,$count-2));				
			}
	}

}

#---------------------------------------------------#
# Verifies that the module contains a "InstalledDisplayDrivers" 
# directive in each SoftwareDeviceSettings section.
#---------------------------------------------------#
sub ChkInstalledDisplayDriver {

    my %sections = $Current_INF_File->getSections();
    my $section;
    my $LastValidSection;

    my $count = 0;
    my $find = 0;
    my @lines;
    my $line;
    my $value;

	foreach $section (%sections) {
		 next if($section !~ /SoftwareDeviceSettings/i);
			$LastValidSection = $section;
			$count = 0;
			@lines = $Current_INF_File->getSection($LastValidSection);	
			foreach $line (@lines) {
				$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
				 if($line =~ /InstalledDisplayDrivers/i) {
				 	$find++;	
				}
				$count++;				
			}	
	}
	#If this directive is present even in one SoftwareDeviceSection we assume inf is correct
	if($find < 1) {
		AddDisplayError(6005, $Current_INF_File->getIndex($LastValidSection,$count-1),$LastValidSection);					
	}
}

#-------------------------------------------------------------------------------------------------------#
# ChkStartType and ChkStartTypeValue verifies that StartType is set to 3 (in ServiceInstall section) for LH display adapter inf's
# They do not print any error if the AddService/StartType directive is not defined since chkinf.pm module already does that.
#-------------------------------------------------------------------------------------------------------#

sub ChkStartTypeValue{

	my $SISection      = shift;              # The Service Install Section 
	my $count        = 0;
	my $line;
	my($Directive, $Value);
	my @lines = $Current_INF_File->getSection($SISection);

	foreach $line (@lines)
	{
		$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
		if($line =~ /StartType/i){
			($Directive, $Value) = ChkInf::SplitLine($SISection,$count,$line);
			if($Value != 3)
			{
				AddDisplayError(6012, $Current_INF_File->getIndex($SISection,$count),$Value);					
			}
		}
		$count++;
	}    
}

sub ChkStartType {

	my %sections = $Current_INF_File->getSections();
	my $section;
	my $count=0;
	my @lines;
	my $line;

	foreach $section (%sections) {
		next if($section !~ /Services$/i);  #skip sections other than ones which contain Services
		$count = 0;
		@lines = $Current_INF_File->getSection($section);			
		foreach $line (@lines)
		{
			$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
			if($line =~ /AddService/i)
			{				
				# AddService=ServiceName,[flags],service-install-section[,event-log-install-section[,[EventLogType][,EventName]]]
				my($ServiceName, $Flags, $SISec, $ELSec, $ELType, $EName) =
				ChkInf::GetList($line,$Current_INF_File->getIndex($section,$count));

				if (defined($Flags)) {
				# Handle the blank case
				if ($Flags =~ /^[\s\t]*$/) {
					$Flags=0;
				}

				if ($Flags=~/^\d*$/) {
				# Force numeric strings to numeric context
				#(When a scalar contains just a number, there exists abiguity:
				#is it a string of characters (that happen to be numbers) or is it a number);
				#The addition operator forces its operands into numeric context
				
					$Flags+=0;
				}

				if ($Flags =~ /^0x/i) {
					$Flags =~ s/^0x//i;
					#Covert the string to hex
					$Flags = hex($Flags);
				} elsif ($Flags =~ /^0/) {
					$Flags =~ s/^0//i;
					#Convert string to Octal number 
					$Flags = oct($Flags);
				} # Otherwise, assume it's already in decimal

				if (!(ChkInf::is_numeric($Flags)) ) {
					$Flags=0;
				}

				if(defined($SISec) && ($SISec !~ /^$/))
				{
					if($Current_INF_File->sectionDefined($SISec))
					{	
						#Flags specifies one or more (ORed) system-defined flags
						if (($Flags & 0x2)== 0x2)
						{
							#PNP drivers have flag value set to 0x00000002 and  StartType check only needs to be done for PnP
							ChkStartTypeValue($SISec);
						}
					}
				}				
			}
			}
			$count++;
		}

	}
}


#---------------------------------------------------------------------#
# Verifies that the WDDM inf contains new copy flag to Support PNPStop Directive
# This flag (0x00004000) is only required for user mode binaries
#---------------------------------------------------------------------#
sub ChkUserModeDllFlag
{
	#Check the DestinationDirs section to get the file-list-section:
	#[DestinationDirs]
	#[DefaultDestDir=dirid[,subdir]] 
	#[file-list-section=dirid[,subdir]] 

       my %sections = $Current_INF_File->getSections();	      
	my $section;
	my $count=0;
	my @lines;
	my $line;
	my @Values;
	my $Value;
	my $Directive;
	
	#print "in Check user mode dll";

	foreach $section (%sections)
	{
		next if($section !~ /DestinationDirs/i);  #skip sections other than ones which contain DestinationDirs
		$count = 0;
		@lines = $Current_INF_File->getSection($section);			
		foreach $line (@lines)
		{
			$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
			($Directive, $Value) = ChkInf::SplitLine($section,$count,$line);

			#$Directive contains the file-list-section and $Value contains dirid,[,subdir]] 
			@Values = ChkInf::GetList($Value,$Current_INF_File->getIndex($section, $count));

			#Get the dirid
			$Value  = shift(@Values);	

			#Check the file section only for user mode copy file section (dirid == 11 for system32 or dirid==10 for syswow)
			if ( $Current_INF_File->sectionDefined($Directive) && (($Value == 11) || ($Value == 10)))
			{
				#Check the file-list-section for CopyFlag
				ChkFileSection($Directive, $Value);
			}
		$count++;
		}
	}

}

sub ChkFileSection
{
	my $section = $_[0]; #Name of section
	my $dirid = $_[1]; 
	my $count=0;	
	my $line;
       my @lines = $Current_INF_File->getSection($section);
       my $Value;
       my @Values;
		foreach $line (@lines)
		{
			$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
			if($line =~ /.dll/i)
			{
				#11 is equivalent to %windir%\system32 for NT-based systems, and to %windir%\system for Windows 9x/Me; 
				#We only want to add the dll's in System32 folder
				if($dirid == 11)
				{
					# Add the user mode dll names to our global array
					@Values = split(/,/,$line);
					$Value = shift(@Values);
					push(@UserModeDlls,$Value);
				}

				if($line =~ /4000/)
				{
					#The inf contains new Copy File flag for user mode WDDM binary. It is WDDM inf
					push(@DriverModelList,"WDDM");
				}else
				{
					if($LogErr)
					{
						#All other heuristics indicate this is WDDM inf; generate an error since line doesn't have the copy flag	
						AddDisplayError(6016, $Current_INF_File->getIndex($section,$count),$line);	
					}else
					{
						#Called for first time;could be XDDM inf
						push(@DriverModelList,"XDDM");

					}
				}
				
			}			
			$count++;			
	        }
	
}

#------------------------------------------------------------------------#
# Verifies that the WDDM inf contains "FeatureScore" Directive in general install section. 
# This value (FeatureScore=F8) is required for all ASIC install sections.
#------------------------------------------------------------------------#

sub ChkFeatureScore
{
	my $Var = "FeatureScore";
	ChkManuSection($Var);
}

#------------------------------------------------------------------------#
# Verifies that Vista MS internal inf's date for driverVersion in Version section is less than 08\21\2006
#------------------------------------------------------------------------#

sub ChkDriverVerDate
{
    my %sections = $Current_INF_File->getSections();
    my $section;

    my $count = 0;
    my @lines;
    my $line;
    my $value;
    my $Directive;
    my $Value;

	foreach $section (%sections) {
		 next if($section !~ /Version/i);
			$count = 0;
			@lines = $Current_INF_File->getSection($section);	
			foreach $line (@lines) {
				$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
				 if($line =~ /DriverVer/i) {
	 			($Directive, $Value) = ChkInf::SplitLine($section,$count,$line);
				#$Value is of form (Month)/(Day)/(Year,Version)
				#Main ckinf module checks for most invalid date scenarios (i.e. if date is two digit and is > 31, month > 12 and so on
				#So simply check for 08\21\2006

				my(@Values)  = split(/\//, $Value);

				#$Values[2] is of form (Year,Version)
				my(@Values1) = split(/,/, $Values[2]);

				# Make sure the date is not greater than 08\21\2006
				if ($Values1[0]  > 2006)
				{
					AddDisplayError(6027, $Current_INF_File->getIndex($section,$count),$line);	
				} elsif ($Values1[0]  == 2006)
				{
					if ($Values[0] > 8) 
					{
						AddDisplayError(6027, $Current_INF_File->getIndex($section,$count),$line);
					}elsif ($Values[0] == 8) 
					{
						if ($Values[1] > 21) 
						{
							AddDisplayError(6027, $Current_INF_File->getIndex($section,$count),$line);	
						}
					}
				}				 
				}
				$count++;				
			}	
	}

}

#-----------------------------------------------------------------#
# Verifies that all inbox display inf's follow the MS internal device naming scheme
#-----------------------------------------------------------------#
sub ChkDeviceNamingScheme
{
	my $Var = "DeviceName";
	ChkManuSection($Var);
}

sub ChkInstallSection
{	my $section = $_[0]; # Section to check
	my $Var = $_[1]; #Feature to check
	my $count=0;	
	my $line;
       my @lines = $Current_INF_File->getSection($section);
	my $Value;
	my $Directive;
	my $found =0;
	my $FinalCount =0;

		foreach $line (@lines)
		{			
			$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line

			#Skip the blank lines at end of section and dipslay error at right place
			$FinalCount = $count;			
			($Directive, $Value) = ChkInf::SplitLine($section,$count,$line);
			if($Var eq "RegisterDlls")
			{
				if($Directive =~ /RegisterDlls/i)
				{
					$found++;
					$RegisterDllSection = $Value;
					
				}

			}elsif($Var eq "FeatureScore")
			{
				if($Directive =~ /FeatureScore/i)
				{
					$found++;
					if($LogErr)
					{
						if(IsWDDMInf())
						{							
							if(ChkInf::GetGlobalValue("MS_INTERNAL"))
							{
								if($Value eq "F8")
								{
									#For MS internal inf's date for driverVersion in Version section should not be greater than 08\21\2006
									ChkDriverVerDate();
								}else
								{
									#FeatureScore Directive's value should be F8 for inbox WDDM drivers
									AddDisplayError(6014, $Current_INF_File->getIndex($section,$count),$Value);	
								}
									
							}else
							{
								if($Value ne "F6")
								{
									#FeatureScore Directive's value should be F6 for 3rd party WDDM drivers
									AddDisplayError(6026, $Current_INF_File->getIndex($section,$count),$Value);		
								}
							}	
														
						}else
						{	
							#XDDM inf
							if(ChkInf::GetGlobalValue("MS_INTERNAL"))
							{
								if($Value eq "FD")
								{
									#For MS internal inf's date for driverVersion in Version section should not be greater than 08\21\2006
									ChkDriverVerDate();
								}else
								{
									#XDDM inf should have FD for inbox drivers. 
									AddDisplayError(6024, $Current_INF_File->getIndex($section,$count),$Value);	
								}
									
							}else
							{
								if($Value ne "FC")
								{
									#XDDM should have FC for 3rd party drivers 
									AddDisplayError(6025, $Current_INF_File->getIndex($section,$count),$Value);		
								}
							}	
						}
					}
				}
			}
			 $count++;
	        }
	       
		if($found == 0 )
		{
			if($Var eq "FeatureScore")
			{
				#All our tests are based on presence of Feature Score directive
				#If FS directive is not found don't run any tests
				#Could not find Feature Score directive; assume non-Vista (legacy) inf is being parsed
				$IsVistaInf = FALSE;
				if ($OSVer >= 6)
				{
					# OSVer >= 6 applies Vista or later; hence critical error if FS is not present
					AddDisplayError(6029, $Current_INF_File->getIndex($section,$FinalCount),$Directive);						
				}
				
			}elsif($Var eq "RegisterDlls")
			{
				AddDisplayError(6021, $Current_INF_File->getIndex($section,$FinalCount),$Directive);	
			}
		}else
		{
			if($Var eq "FeatureScore")
			{
				#FS directive found
				if ($OSVer < 6)
				{
					#print "Running on Pre Vista OS; should not have Feature Score directive";
					AddDisplayError(6028,$Current_INF_File->getIndex($section,$FinalCount),$Directive);
					#Don't need to run Vista inf tests on pre-vista
					$IsVistaInf = FALSE;

				}
			}
		}

}

sub ChkModelSection
{
    my $section =  $_[0];	#Name of the section
    my $Var = $_[1]; #Feature to check
    my $count   =     0;
    my $line;
    my @lines = $Current_INF_File->getSection($section);
    my $Directive;
    my $Value;
    my @Values;
    my @ErrorArgs;

    foreach $line (@lines) 
    {
        $count++, next if ($line =~ /^[\s\t]*$/);# Skip if it's a blank line

        #[device-description=install-section-name,hw-id[,compatible-id]...] ...
	 #device-description identifies a device to be installed, expressed as any unique combination of visible characters 
	 #or as a %strkey% token defined in STRINGS section

        ($Directive, $Value) = ChkInf::SplitLine($section,$count,$line);  
        @Values     = ChkInf::GetList($Value,$Current_INF_File->getIndex($section,$count));
        
        if(($Var eq "FeatureScore") || ($Var eq "RegisterDlls") )
        {
	        if (defined($Values[0])) 
	        {
	            if ( $Current_INF_File->sectionDefined( $Values[0] ) ) 
	            {
	            	#Check the install section for the directive
	            	ChkInstallSection($Values[0], $Var);
	            }
	         }
        }elsif($Var eq "DeviceName")
        {
	              #Search for the device name

	              #$Directive =device-description
	              $ErrorArgs[0] = $Directive;
	              
	        	if( (!IsWDDMInf()) && (($Directive !~ /Microsoft[\s|\t]*Corporation/i) || ($Directive !~ /XDDM/)))
	        	{
	        		$ErrorArgs[1] = "'XDDM (Microsoft Corporation)'";
	  			AddDisplayError(6013, $Current_INF_File->getIndex($section,$count), @ErrorArgs);		
	        	}

	           
	        	if( (IsWDDMInf()) && (($Directive !~ /Microsoft[\s|\t]*Corporation/i) || ($Directive !~ /WDDM/)))
	        	{
	        		$ErrorArgs[1] = "'(Microsoft Corporation - WDDM)'";
	  			AddDisplayError(6013, $Current_INF_File->getIndex($section,$count), @ErrorArgs);		
	        	}

	        	if($Directive =~ /WDDM/)
			{
				push(@DriverModelList,"WDDM");
			}	        	
        }
        $count++;
     }
}

sub ChkManuSection
{
	my %sections = $Current_INF_File->getSections();
	my $Var = $_[0]; # Feature to check
	my $section;
	my $count=0;
	my @lines;
	my $line;
	my @Values;
	my $Value;
	my $Directive;
	my ($NTARCH,$OSMaj,$OSMin,$OSType,$Suite);

	foreach $section (%sections)
	{
		next if($section !~ /Manufacturer/i);  #skip sections other than ones which contain Manufacturer
		$count = 0;
		@lines = $Current_INF_File->getSection($section);			
		foreach $line (@lines)
		{
			$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line

			#manufacturer-name |
			#%strkey%=models-section-name |
			#%strkey%=models-section-name [,TargetOSVersion] [,TargetOSVersion] ...  
			
			($Directive, $Value) = ChkInf::SplitLine($section,$count,$line);

			# Whistler allows new TargetDecorations.
			@Values = ChkInf::GetList($Value,$Current_INF_File->getIndex($section, $count));
			# Value holds the undecorated section, @Values holds TargetDecorations.
			$Value  = shift(@Values);
		       #print "$Value";

                     # [Manufacturers] may not have both a directive & a value
			if ((! defined $Value) or ($Value eq "")) 
			{
	                     # It's just a model, not a manufacturer
				$Value = $Directive;
			}
			
			if ( $Current_INF_File->sectionDefined($Value) )
			{	
				#Check the asic/model section 
				ChkModelSection($Value, $Var);				
				
			}
			foreach (@Values) 
			{		
				($NTARCH,$OSMaj,$OSMin,$OSType,$Suite) = split(/\./,$_);
				if ( $Current_INF_File->sectionDefined("$Value.$_") )
				{
					ChkModelSection("$Value.$_", $Var);
			       }
			}

		$count++;
		}
	}
}


#--------------------------------------------------------------------#
# Verifies that inbox display inf's do not reference LayoutFile or CatalogFile
#--------------------------------------------------------------------#
sub ChkVersionSection()
{
    my %sections = $Current_INF_File->getSections();
    my $section;

    my $count = 0;
    my @lines;
    my $line;
    my $value;

	foreach $section (%sections) {
		 next if($section !~ /Version/i);
			$count = 0;
			@lines = $Current_INF_File->getSection($section);	
			foreach $line (@lines) {
				$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
				 if($line =~ /LayoutFile/i) {
				 	AddDisplayError(6017, $Current_INF_File->getIndex($section,$count-1),$section);					

				}elsif($line =~ /CatalogFile/i)
				{
					AddDisplayError(6018, $Current_INF_File->getIndex($section,$count-1),$section);					
				}
				$count++;				
			}	
	}
}

#---------------------------------------------------------------------------------#
# Verifies that Vista inbox display inf's contain '3426=windows cd' entry in SourceDiskNamesSection
#---------------------------------------------------------------------------------#
sub ChkSourceDisksNames()
{
    my %sections = $Current_INF_File->getSections();
    my $section;

    my $count = 0;
    my @lines;
    my $line;
    my $value;
    my ($Directive, $Value);

	foreach $section (%sections) {
		next if($section !~ /SourceDisksNames/i);
			$count = 0;
			@lines = $Current_INF_File->getSection($section);	
			foreach $line (@lines) {
				$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
				($Directive, $Value) = ChkInf::SplitLine($section,$count,$line);  

				if(($Directive != 3426) || ($Value !~ /windows[\s|\t]*cd/i))
				{
				 	AddDisplayError(6019, $Current_INF_File->getIndex($section,$count-1),$section);					

				}
				$count++;				
			}	
	}
	         
		
}

sub ChkSourceDisksFiles()
{
    my %sections = $Current_INF_File->getSections();
    my $section;

    my $count = 0;
    my @lines;
    my $line;
    my $value;
    my ($Directive, $Value);

	foreach $section (%sections) {
		 next if($section !~ /SourceDisksFiles/i);
			$count = 0;
			@lines = $Current_INF_File->getSection($section);	
			foreach $line (@lines) {
				$count++ , next if ($line =~ /^\s*$/); # Skip if it's a blank line
				($Directive, $Value) = ChkInf::SplitLine($section,$count,$line);  

				if($Value != 3426) 
				{
				 	AddDisplayError(6020, $Current_INF_File->getIndex($section,$count-1),$section);	
				}
				$count++;				
			}	
	}

}

#---------------------------------------------------#
# Verifies that native CloneViewHelper dll is registered
#---------------------------------------------------#
sub ChkTMMDlls
{	
	my $count;
	my $line;
	my @Values;
	my $Value;
	my $found =0;
	my $FinalCount =0;
	

	# This sub uses a global array filled by ChkUserModeDllFlag sub
	if(scalar(@UserModeDlls) == 0)
	{
		return;
	}

	#Get the section name being used for registering the cloneviewhelper dll (Store it in global var $RegisterDllSection)
	my $Var = "RegisterDlls";
	ChkManuSection($Var);

	#Return if RegisterDllSection is null
	if(!defined($RegisterDllSection))
	{
		return;
	}

	my @lines = $Current_INF_File->getSection($RegisterDllSection);
	foreach $line (@lines) 
	{
		$count++, next if ($line =~ /^[\s\t]*$/);# Skip if it's a blank line

		#Skip the blank lines at end of section and dipslay error at right place
		$FinalCount = $count;	
		@Values     = ChkInf::GetList($line,$Current_INF_File->getIndex($RegisterDllSection,$count));
		foreach $Value(@Values)
		{
			if($Value =~ /.dll/i)
			{
				#Check if this dll is in list of UseMode dlls copied to system32 folder
				my $i;	
				for($i = 0; $i < scalar(@UserModeDlls); $i++)
				{
					if($UserModeDlls[$i] eq $Value)
					{
						$found++;
					}
				}

			}
		}
		$count++;
	}	

	if($found < 1)
	{
		AddDisplayError(6022, $Current_INF_File->getIndex($RegisterDllSection,$FinalCount),$RegisterDllSection);	
	}

}



#---------------------------------------------------#
# Verifies that the module loaded correctly.  Be sure
# to change the string to the name of your module.
#---------------------------------------------------#
sub Exists {
    print(STDERR "Module \"DISPLAY\" Loaded\n");
    return(1); # return 1 on success
}


#---------------------------------------------------#
# Is called when module is first included.
# Use it to set your per-inf variables.
#---------------------------------------------------#
sub InitGlobals {
    # First parameter is the INF object
    $Current_INF_File=$_[1];

    # Output file = htm subdir + ((INF Name - .inf) + .htm)
    $Current_HTM_File = $Current_INF_File->{inffile};
    $Current_HTM_File = substr($Current_HTM_File, rindex($Current_HTM_File,"\\")+1);
    $Current_HTM_File =~ s/\.inf$/\.htm/i;
    $Current_HTM_File = "htm\\" . $Current_HTM_File;

    # Second parameter is a list of Device Specific options.
    my($DC_Specific_Options) = $_[2];

    # $DC_Specific_Options is a string that contains all device
    #   class options delimited by &'s
    if (defined($DC_Specific_Options)) {
        @Device_Class_Options = split(/&/,$DC_Specific_Options);
    } else {
        @Device_Class_Options = ("NULL", "NULL");
    }

    # Array must be shifted since first element also had a & prepended
    shift(@Device_Class_Options);

    return(1); # return 1 on success
}


#---------------------------------------------------#
# Allows to add Device specific information to the
# top of the INF summary page.  The information here
# should be brief and link to detailed summaries
# below. (Which will be written using PrintDetials).
#---------------------------------------------------#
sub PrintHeader {
    return(1); # return 1 on success
}


#---------------------------------------------------#
# Allows addition of device specific results to the
# detail section on the INF summary.
#---------------------------------------------------#
sub PrintDetails {
    return(1); # return 1 on success
}

###################################################################################################
#+-----------------------------------------------------------------------------------------------+#
#|                                    WORK SUBROUTINES                                           |#
#+-----------------------------------------------------------------------------------------------+#
###################################################################################################

#-------------------------------------------------------------------------------------------------#
# CheckModel - Verifies an individual model                                                       #
#-- CheckModel($Model)  --------------------------------------------------------------------------#
sub CheckModel($Model) {
    my($Model) = $_[0];

    print(STDERR "\tInvoking Display::CheckModel...\n") if ($DEBUG);

    if ( $Current_INF_File->sectionDefined($Model.".SOFTWARESETTINGS") ) {
        # We should work with this && .NTALPHA if exists
        VerifySoftwareSettings($Model.".SOFTWARESETTINGS");
    }

    if ( $Current_INF_File->sectionDefined($Model.".OPENGLSOFTWARESETTINGS") ) {
        # We should work with this && .NTALPHA if exists
        VerifySoftwareSettings($Model,".OPENGLSOFTWARESETTINGS");
    }

    if ( $Current_INF_File->sectionDefined($Model.".GENERALCONFIGDATA") ) {
        # We should work with this && .NTALPHA if exists
        VerifyGCData($Model.".GENERALCONFIGDATA");
    }

    my @lines   = $Current_INF_File->getSection($Model);
	my $line;
	my $count = 0;
	my $Directive;
	my $Value;
	my $Section = $Model;
	my @RegLines;

    foreach $line (@lines) {
        $count++, next if ($line =~ /^\s*$/); # Skip if it's a blank line
        ($Directive,$Value) = ChkInf::SplitLine($Section,$count,$line);

        if (uc $Directive eq "ADDREG") {
            foreach ( ChkInf::GetList($Value,$Current_INF_File->getIndex($Section,$count)) ) {
                push(@RegLines, RegLines($_)) if ( $Current_INF_File->sectionDefined($_) );
            }
        }
    }

	my @regvalues;
	foreach (@RegLines) {
		if ($$_[0] =~ /^HKLM\s*,\s*"?SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Controls\sFolder\\Device/i) {
			AddDisplayError(6004,$$_[1]);
		}
	}

    return(TRUE);
}

#-------------------------------------------------------------------------------------------------#
# LearnModels - Returns an array of all models listed in the INF                                  #
#-- LearnModels() --------------------------------------------------------------------------------#
sub LearnModels {
    return(FALSE) if (! $Current_INF_File->sectionDefined("Manufacturer") );
    my $Section = "Manufacturer";
    my $line;
    my @lines   = $Current_INF_File->getSection("Manufacturer");
    my $count   = 0;

    my($Directive, $Value, @Values);
    my(%Models);
    my ($NTARCH,$OSMaj,$OSMin,$OSType,$Suite);


    print(STDERR "\tInvoking Display::ProcManu...\n") if ($DEBUG);

    foreach $line (@lines) {
        $count++, next if ($line =~ /^\s*$/); # Skip if it's a blank line

        ($Directive,$Value) = ChkInf::SplitLine($Section,$count,$line);
        
         # Whistler allows new TargetDecorations.
        @Values = ChkInf::GetList($Value,$Current_INF_File->getIndex($Section, $count));
        # Value holds the undecorated section, @Values holds TargetDecorations.
        $Value  = shift(@Values);

        # [Manufacturers] may not have both a directive & a value
        if ($Value =~ /^\s*$/) {
            $Value     = $Directive;
            $Directive = "";
        } else {
            $Value    =~  s/^\"(.*)\"/$1/;   # And Strip the Quotes!
        }

        if ( $Current_INF_File->sectionDefined($Value) ) {
            # Add the models from $INFSections{$Value} to our running list
            %Models = (%Models, ExpandModelSection($Value));
        }
	foreach (@Values)
	{
		($NTARCH,$OSMaj,$OSMin,$OSType,$Suite) = split(/\./,$_);
		# $NTARCH NT, NTx86, NTIA64, NTAMD64
		# $OSMaj is the OS major version (e.g., for Whistler, it's 5).
		# $OSMin is the OS minor version (e.g., for Whistler, it's 1).
		# $OSType indicates the type of product, and may be one of the following values (as defined in winnt.h):
		#   VER_NT_WORKSTATION              0x0000001
		#   VER_NT_DOMAIN_CONTROLLER        0x0000002
		#   VER_NT_SERVER                   0x0000003
		# If multiple product types are supported (i.e., some subset of all product types, such as domain
		# controllers and servers, but not workstations), then multiple decorations must be specified, one for
		# each applicable product type.
		# $Suite is a combination of the following flags identifying the product suites available on the system
		# (as defined in winnt.h):
		#   VER_SUITE_SMALLBUSINESS             0x00000001
		#   VER_SUITE_ENTERPRISE                0x00000002
		#   VER_SUITE_BACKOFFICE                0x00000004
		#   VER_SUITE_COMMUNICATIONS            0x00000008
		#   VER_SUITE_TERMINAL                  0x00000010
		#   VER_SUITE_SMALLBUSINESS_RESTRICTED  0x00000020
		#   VER_SUITE_EMBEDDEDNT                0x00000040
		#   VER_SUITE_DATACENTER                0x00000080
		#   VER_SUITE_SINGLEUSERTS              0x00000100
		if ( $Current_INF_File->sectionDefined("$Value.$_") ) 
		{
			%Models = (%Models, ExpandModelSection("$Value.$_"));
		}
        }
        
        $count++;
    }

    return(%Models);
}

#-------------------------------------------------------------------------------------------------#
#-- VerifyGCData($line, $Model, $Extension) ------------------------------------------------------#
sub VerifyGCData {
    my $Section     = $_[0];
    my @lines       = $Current_INF_File->getSection($Section);;
    my $count       = 0;
    my $line;

    my($Directive, @Values, $Value);

    my(%SecToCheck) = ("MAXIMUMDEVICEMEMORYCONFIGURATION", TRUE,
                       "MAXIMUMNUMBEROFDEVICES"          , TRUE,
                       "KEEPEXISTINGDRIVERENABLED"       , TRUE,
                       "COPYFILES"						 , TRUE,
                       "SESSIONIMAGESIZE"				 , TRUE);

    my($CurrentLine, $Temp, @LineItems, $SizeOfArray);
	ChkInf::Mark("$Section");

    print(STDERR "\tBeginning VerifyGCData (@_)...\n") if ($DEBUG);
    foreach $line (@lines) {
        $count++, next if ($line =~ /^\s*$/);# Skip if it's a blank line

        ($Directive,$Value) = ChkInf::SplitLine($Section,$count,$line);
        @Values             = ChkInf::GetList($Value,$Current_INF_File->getIndex($Section,$count));

        if (uc($Directive) eq "MAXIMUMDEVICEMEMORYCONFIGURATION") {
            if (defined($Values[0])) {
                if (defined($Values[1])) {
                    AddDisplayError(6002,$Current_INF_File->getIndex($Section,$count),$Directive);
                }
            } else {
                AddDisplayError(6002,$Current_INF_File->getIndex($Section,$count),$Directive);
            }
        } elsif (uc($Directive) eq "MAXIMUMNUMBEROFDEVICES") {
            if (defined($Values[0])) {
                if (defined($Values[1])) {
                    AddDisplayError(6002,$Current_INF_File->getIndex($Section,$count),$Directive);
                }
            } else {
                AddDisplayError(6002,$Current_INF_File->getIndex($Section,$count),$Directive);
            }
        } elsif (uc($Directive) eq "KEEPEXISTINGDRIVERENABLED") {
            if (defined($Values[0])) {
                if (defined($Values[1])) {
                    AddDisplayError(6002,$Current_INF_File->getIndex($Section,$count),$Directive);
                }
                if (($Values[0] != 1) and ($Values[0] != 0)) {
                    AddDisplayError(6003,$Current_INF_File->getIndex($Section,$count),$Directive);
                }
            } else {
                AddDisplayError(6002,$Current_INF_File->getIndex($Section,$count),$Directive);
            }
        } elsif (uc($Directive) eq "SESSIONIMAGESIZE") {
            if (defined($Values[0])) {
                if (defined($Values[1])) {
                    AddDisplayError(6002,$Current_INF_File->getIndex($Section,$count),$Directive);
                }
                if($Values[0] > 16)
                {
                	AddDisplayError(6011,$Current_INF_File->getIndex($Section,$count),$Directive);
                }
            } else {
                AddDisplayError(6002,$Current_INF_File->getIndex($Section,$count),$Directive);
            }
        } else {
            AddDisplayError(6001,$Current_INF_File->getIndex($Section,$count),$Directive)
            	unless (defined $SecToCheck{uc $Directive});
        }
        $count++;

    }

    return(TRUE);
}

#-------------------------------------------------------------------------------------------------#
#-- VerifySoftwareSettings($line, $Model, $Extension) --------------------------------------------#
sub VerifySoftwareSettings {
    my $Section     = $_[0];

    my @lines      = $Current_INF_File->getSection($Section);
    my $count      = 0;
    my $line;

    my($Directive, @Values, $Value);


    my(%SecToCheck) = ("ADDREG",    TRUE,
                       "COPYFILES", TRUE,
                       "NEEDS",     TRUE);

    my($CurrentLine, $Temp, @LineItems, $SizeOfArray);

	ChkInf::Mark("$Section");

    print(STDERR "\tBeginning VerifyModel (@_)...\n") if ($DEBUG);
    foreach $line (@lines) {

        $count++, next if ($line =~ /^\s*$/);# Skip if it's a blank line

        ($Directive,$Value) = ChkInf::SplitLine($Section,$count,$line);
        @Values             = ChkInf::GetList($line,$Current_INF_File->getIndex($Section,$count));

        if (uc($Directive) eq "ADDREG") {
            # ADDREG is valid, so call the ChkInf ADDREG checking routine
            ChkInf::ADDREG($Section, $count, $Value);
        } elsif (uc($Directive) eq "DELREG") {
            # ADDREG is valid, so call the ChkInf ADDREG checking routine
            ChkInf::DELREG($Section, $count, $Value);
        } else {
            AddDisplayError(6001,$Current_INF_File->getIndex($Section,$count),$Directive)
            	unless (defined $SecToCheck{uc $Directive});
        }

        $count++;

    }
    return(TRUE);
}

###################################################################################################
#+-----------------------------------------------------------------------------------------------+#
#|                                   HELPER SUBROUTINES                                          |#
#+-----------------------------------------------------------------------------------------------+#
###################################################################################################

#-------------------------------------------------------------------------------------------------#
# This sub adds a new error to the list of errors for the file.                                   #
#-- AddDisplayError($ErrorNum, $LineNum, @ErrorArgs) ---------------------------------------------#
sub AddDisplayError {
    my($ErrorNum) = $_[0], shift;
    my($LineNum)  = $_[0], shift;
    my(@ErrorArgs)= @_;

    $ErrorArgs[0] = " " if (! defined($ErrorArgs[0]));
    my($str, $this_str, $info_err, $format_err);

    $info_err = $DisplayErrorTable{"$ErrorNum"};

    if ( !defined($info_err) ) {
        $this_str = "Unknown error $ErrorNum.";
    } else {
        $format_err = $$info_err[0];
        $this_str = sprintf($format_err, @ErrorArgs);
    }

    ChkInf::AddDeviceSpecificError($LineNum, $ErrorNum, $this_str);
}

#-------------------------------------------------------------------------------------------------#
# This sub adds a new warning to the list of warnings for the file.                               #
#-- AddDisplayWarning($WarnNum, $LineNum, @ErrorArgs) --------------------------------------------#
sub AddDisplayWarning {
    my($WarnNum)  = $_[0], shift;
    my($LineNum)  = $_[0], shift;
    my(@WarnArgs) = @_;

    $WarnArgs[0] = " " if (! defined($WarnArgs[0]));
    my($str, $this_str, $info_wrn, $format_wrn);

    $info_wrn = $DisplayWarningTable{"$WarnNum"};

    if ( !defined($info_wrn) ) {
        $this_str = "Unknown warning $WarnNum.";
    } else {
        $format_wrn = $$info_wrn[0];
        $this_str = sprintf($format_wrn, @WarnArgs);
    }
    ChkInf::AddDeviceSpecificWarning($LineNum, $WarnNum, $this_str);
}

#-------------------------------------------------------------------------------------------------#
#-- ExpandModelSection($line, $Section) ----------------------------------------------------------#
sub ExpandModelSection {
    my $Section  = shift;
    my $line;
    my @lines    =  $Current_INF_File->getSection($Section);
    my $count    = 0;

    my(%Models)  =  ();
    my($TempVar);

    my($Directive, @Values, $Value, $DevSection, $Provider, $DevDesc, $DevID);

    print(STDERR "\tInvoking Display::ExpandModelSection...\n") if ($DEBUG);

    foreach $line (@lines) {
        $count++, next if ($line =~ /^\s*$/);# Skip if it's a blank line

        ($Directive,$Value) = ChkInf::SplitLine($Section,$count,$line);
        @Values             = ChkInf::GetList($Value,$Current_INF_File->getIndex($Section,$count));

        $Values[0] =~ s/^\s*//i; # Kill leading spaces
        $Values[0] =~ s/\s*$//i; # Kill trailing spaces

        if (defined $Values[0]) {
            $DevSection = $Values[0];
        } else {
            # ERROR
            next;
        }
    
        if (defined $Values[1]) {
            $DevID = $Values[1];
        } else {
            # ERROR
            next;
        }

        if (defined($Values[0])) {
            if (defined $Models{uc $DevID}) {
                # ERROR
            } else {
               $Models{uc $DevID}{"DDINSTALL"}   = $DevSection;
               $Models{uc $DevID}{"DESCRIPTION"} = $DevDesc;
               $Models{uc $DevID}{"PROVIDER"}    = $Provider;
            }
        }
        $count++;
    }

    return(%Models);
}

#-------------------------------------------------------------------------------------------------#
# RegLines - returns all reglines (w/ string tokens removed) from a section.                      #
#-- RegLines() -----------------------------------------------------------------------------------#
sub RegLines {
    my $line;
    my $Section  =  shift;
    my @lines    =  $Current_INF_File->getSection($Section);
    my $count    =  0;
    my @reglines;

    print(STDERR "\tInvoking Media::RegLines...\n") if ($DEBUG);

    foreach $line (@lines) {
        #Skip blank lines even though this should never be true.
        $count++, next if ($line =~ /^[\s\t]*$/);
        # Remove all string tokens
        $line = ChkInf::RemoveStringTokens($Current_INF_File->getIndex($Section,$count),$line);
        # Update our list with [$line, $linenum]
        push(@reglines, [$line,$Current_INF_File->getIndex($Section,$count)]);
        $count++;
    }
    return(@reglines);
}

return(1); # Module must return 1 to let chkinf know it loaded correctly.
