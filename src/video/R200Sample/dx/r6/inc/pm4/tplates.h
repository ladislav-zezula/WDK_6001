

//    
//  $Workfile: tplates.h $
//  $Revision: 16 $
//
//  Description:
//
//  
//  Trade secret of ATI Technologies, Inc.
//  Copyright 1999-2001, ATI Technologies, Inc., (unpublished)
//
//  All rights reserved.
//  The year included in the foregoing notice is the year of creation of the work.
//
//

 
#ifndef     TEMPLATES_H_

#define     TEMPLATES_H_

#include    "atidxinc.h"
#include    "ipt.h"

#define NO_SHIFT 0                       // used with SetRegBits

// Following registers are temprorally defined for the emulator
#define  t_mmSURF_BPP                    0x0822
#define  t_mmDST_WIDTH_HEIGHT            0x0823
#define  t_mmSceneRegID                  0x0824



//This header file will include all the Promo4 templates
// and definitions!

//PROMO4 can accept types of information, each information packet has
// a unique ID associated with it (used by PROMO4 for recognition). These
//ID's are defined below. 

#define RegConsecTag    0               //Indicates to PROMO4 that we are using 
                                        // the write N consecutive addresses  

#define AutoIncOffTag   0x00008000      //Indicates to PROMO4 that we dont want
                                        // auto - increment, ie we want to write
                                        // to the same register, N amount of times

#define ONE_REG_WR      0x80000000      // Indicates to PROMO4 that we want to keep 
                                        // the destination address the same 
                                        // after each transfer (used in INDX_BUFFER 
                                        // packet)

#define RegAddrPairTag  0x40000000      //Indicates to PROMO4 that we are using the reg:addr pairs
#define RegAddrTriTag   0x80000000      //Indicates to PROMO4 that we are using the reg:addr triplets
#define TemplateTag     0xc0000000      //Indicates to PROMO4 that we are using a pre-defined TEMPLATE


#define TemplateIDMask  ~TemplateTag


//With the introduction of the flexible vertex formats,
//our hardware accounts for this by requiring a header 
//that describes what type of vertex is being used!. It also means that we 
//will have to attach this header to the old TLVertices!. The definition 
//for type TLVERTEX is found below!. PLease NOTE that the FLEXIBLE structure 
//will always hold XYZ

//Definitions for what the flexible vertex structure holds!
#define FLEXIBLE_FAN            0x80000000
#define FLEXIBLE_STRIP          0x40000000
#define FLEXIBLE_TRI_LIST       0x00008000
#define FLEXIBLE_LINE_LIST      0x10000000
#define FLEXIBLE_POINT_LIST     0x20000000


#define FLEXIBLE_RHW            0x00000001        //Flexible structure holds RHW
#define FLEXIBLE_FLOAT_DIFF_RGB 0x00000002
#define FLEXIBLE_FLOAT_DIFF_A   0x00000004
#define FLEXIBLE_FLOAT_DIFFUSE  (FLEXIBLE_FLOAT_DIFF_RGB | FLEXIBLE_FLOAT_DIFF_A)
#define FLEXIBLE_FLOAT_SPEC_RGB 0x00000010
#define FLEXIBLE_FLOAT_SPEC_A   0x00000020
#define FLEXIBLE_FLOAT_SPECULAR (FLEXIBLE_FLOAT_SPEC_RGB | FLEXIBLE_FLOAT_SPEC_A)
#define FLEXIBLE_DIFFUSE        0x00000008        //Flexible structure holds a diffuse colour
#define FLEXIBLE_SPECULAR       0x00000040        //Flexible structure holds a specular colour
#define FLEXIBLE_TL_TEX1        0x00000080        //only applies to old TLVERTICES. it
#define FLEXIBLE_HAS_W1         0x00004000
#define FLEXIBLE_TL_TEX2        0x00000100        //only applies to old TLVERTICES,
#define FLEXIBLE_HAS_W2         0x00000200        //only applies to old TLVERTICES, 
#define FLEXIBLE_TL_TEX3        0x00000400
#define FLEXIBLE_HAS_W3         0x00000800 
#define FLEXIBLE_Z              0x80000000 

#define FLEXIBLE_NORMAL         0x00040000
#define FLEXIBLE_B1             0x00008000
#define FLEXIBLE_B2             0x00010000
#define FLEXIBLE_B3             0x00018000
#define FLEXIBLE_B4             0x00020000

#define FLEXIBLE_XY1            0x08000000         // These are only used for vertex tweening
#define FLEXIBLE_Z1             0x10000000
#define FLEXIBLE_RHW1           0x20000000
#define FLEXIBLE_N1             0x40000000

#define FLEXIBLE_TL_VERTEX (FLEXIBLE_SPECULAR | FLEXIBLE_DIFFUSE | \
                            FLEXIBLE_TL_TEX1 | FLEXIBLE_RHW | FLEXIBLE_Z )



// This a TL Vertex with 2 sets of texture cordinates
#define FLEXIBLE_MTL_VERTEX     (FLEXIBLE_TL_VERTEX | FLEXIBLE_TL_TEX2)

// These defines are only used by DDraw
#define VC_PRIM_TYPE_NONE           0x00000000
#define VC_PRIM_TYPE_POINT_LIST     0x00000001
#define VC_PRIM_TYPE_LINE_LIST      0x00000002
#define VC_PRIM_TYPE_LINE_STRIP     0x00000003
#define VC_PRIM_TYPE_TRIANGLE_LIST  0x00000004
#define VC_PRIM_TYPE_TRIANGLE_FAN   0x00000005
#define VC_PRIM_TYPE_TRIANGLE_STRIP 0x00000006
#define VC_PRIM_TYPE_TRIANGLE_TYPE_2 0x00000007
#define VC_PRIM_TYPE_RECTANGLE      0x00000008

#define VC_PRIM_WALK_VERTEX_INDEXS  0x00000010
#define VC_PRIM_WALK_VERTEX_LIST    0x00000020
#define VC_PRIM_WALK_VERTEX_DATA    0x00000030

//This vertex is used to describe a TL vertex with two set's of texture 
//co-ords. This was introduce in DX5, but, with the introduction of
//DX6's flexible formats, we will probably never see this type!!
// This is not used anywhere.
#define FLEXIBLE_TL2_VERTEX (FLEXIBLE_TL_TEX1 | FLEXIBLE_TL_TEX2 |  \
                             FLEXIBLE_HAS_W2)


//PROMO4 now uses a DP_SET_GUI_CNTL register
//to describe the defaults of a packet.
//If bit 15 of the header is set, then this means the first
//DWORD of the packet will contain the DP_SET_GUI_CNTL register.

#define NoOverrides                 0
#define UseStdSrcs                  0
#define GM_SRC_OFF_PITCH            1
#define GM_DST_OFF_PITCH            2
#define GM_SRC_EQU_DST_PW           0x3000 //Indicates that he SRC pixel width is 
                                           //the same as the DST's
                                           
#define GM_SRC_PW_NOUPDATE          0x2000 //Indicates that the SRC pixel width
                                           // has been set and that it shouldn't
                                           //be changed when GuiMasteCntl is written


#define SRC0_OFF_PTCH               1   //Source 0 offset and pitch has been changed
#define SRC0_1_OFF_PTCH             2   //Source 0 and source 1 offset,pitch has changed 
#define SRC0_1_2_OFF_PTCH           3   //Source 0,1 and 2 offset,pitch has been changed
#define DEST_OFF_PTCH               4   //We are using a non-standard dest offset,pitch
#define CONTAINER_TPLT              8   //This is a container template for multiple IT-bodies
#define HAS_ANCHOR                  16  //This template has a anchor (X,Y,Z) for the destination
#define HAS_DP_PIX_WIDTH            32  //This template modifies the DP_PIX_WIDTH reg.
#define HAS_SCISSORS                64  //Template containes SCISSORS in 2 DWORDS 
                                        //(TOP_LEFT,BOTTOM_RIGHT).
#define FETCH_BODY                  128 //Fetch the remainder of the IT-body from the pointer
                                        //in the curren IT-body.

#define SURF_REG_WRITES             5   // # of DWORDS written to ring when rendersurface changes


//These are just some standard DP_GUI_MSTR_CNTL's that are commonly used

#define DP_GUI_MSTR_PAINT       (0x72f030D0 | GM_DST_OFF_PITCH | DP_GUI_MASTER_CNTL__GMC_DST_CLIPPING )
#define DP_GUI_MSTR_PAINT_CURRENT_WRITE_MASK \
                                (0x32f030D0 | GM_DST_OFF_PITCH | DP_GUI_MASTER_CNTL__GMC_DST_CLIPPING )
//NOTE: The src/dst datatype will be set up inside the BLT function
#define DP_GUI_MSTR_BLT         (0x72CC30F0 | GM_SRC_OFF_PITCH | GM_DST_OFF_PITCH )

#define DP_GUI_MSTR_SRCBLT      (DP_GUI_MSTR_BLT | DP_GUI_MASTER_CNTL__GMC_SRC_CLIPPING | DP_GUI_MASTER_CNTL__GMC_DST_CLIPPING)

#define DP_GUI_MSTR_HOSTBLT     (0x73CC30F0 | GM_DST_OFF_PITCH | DP_GUI_MASTER_CNTL__GMC_DST_CLIPPING)

#define DEFAULT_PRIM_TEX_CNTL   0x02180840
#define DEFAULT_3D_STATE_CNTL   0x500
                                                                                
//For more information on the above ID's and states, please read the BORG:Software Architecture Spec.

#define MakeTemplateHdr( SizeOfTemplate, TemplateID, Overrides) ( \
                         (DWORD) ( ((SizeOfTemplate -2) << 16) | TemplateTag) | Overrides \
                                                          | TemplateID )


#define MakeRegAddrDble( Reg1,Reg2) ((DWORD) ((Reg2 << 11) | Reg1) | RegAddrPairTag)

#define MakeRegAddrTriple( Reg1,Reg2,Reg3) ((DWORD) ((Reg3 << 20) | (Reg2 << 10) | Reg1) \
                                                                    | RegAddrPairTriTag)
#define MakeRegWriteConsec(Reg1,NWrites)   (((((DWORD) NWrites -1) << 16) | Reg1) | RegConsecTag)

#define MakeRegWriteNonConsec(Reg1,NWrites)   (((((DWORD) NWrites -1) << 16) | Reg1) | AutoIncOffTag)




//PrimitiveFlags
//These flags instruct the hardware what type of primitive to render
//and how to render it!.

#define PrimitiveFlagsPointList    0x00000041      
#define PrimitiveFlagsLineList     0x00000042      
#define PrimitiveFlagsLineStrip    0x00000043      
#define PrimitiveFlagsTriList      0x00000044      
#define PrimitiveFlagsTriStrip     0x00000045      
#define PrimitiveFlagsTriFan       0x00000046      
#define PrimitiveFlagsTri2         0x00000067      
#define PrimitiveFlagsTri2       0x00000067      
#define PrimitiveFlagsLineLst    0x00000062
#define PrimitiveFlagsPointsList 0x00000061


//Current PROMO4 OP-codes
#define OpNOP               0x1000
#define	PaintSurfaceID	    0x9100
#define SrcCopyID           0x9200
#define ScaleBltID          0x9600
#define TransScaleBltID     0x9700
#define TransSrcCopyID      0x9C00


//#define RenderPrimitiveID   0x2500                  //This is the only render



/*
** TEMPLATES
*/

//Load palette
typedef         struct
{
 DWORD          Header;
 DWORD          SCALE_DATATYPE;
}LOADPALETTETMPLT, *LPLOADPALETTETMPLT;


//Set vertex list template, must be setup before draw triangle/line list is used!
typedef         struct
{
 DWORD          Header;            //Header info used by PROMO4 to determine information type!
 LPD3DTLVERTEX  SrcVListAddr;      //Address of Vertex List!
 DWORD          SrcVListCnt;       //Amount of vertices!
}SETVLISTTMPLT, *LPSETVLISTTMPLT;


//Surface colour fill template
typedef         struct
{
 DWORD          Header;            //Header info used by PROMO4 to determine information type!
 DWORD          DP_GUI_MCNTL;    //Gui master cntl.
 DWORD          DST_OFF_PTCH;      //Offset and pitch of destination surface
 DWORD          DST_SC_TOP_LEFT;	 //Destination clipping windows(top, left)
 DWORD          DST_SC_BOTTOM_RIGHT; //Destination clipping windows(bottom, right)
 DWORD          Colour;            //Colour to use when doing fill
 DWORD          Start_X_Y;         //Start co-ordinates of colour fill  
 DWORD          BLT_WDTH_HGHT;     //End co-ordinates of colour fill 
}PAINTSURFACETMPLT, *LPPAINTSURFACETMPLT;

//HOST BLT (used to copy textures from Sys->framebuffer)
typedef         struct
{
 DWORD          Header;
 DWORD          DP_GUI_MCNTL;
 DWORD          DST_OFF_PTCH;
 DWORD          DST_SC_TOP_LEFT;
 DWORD          DST_SC_BOTTOM_RIGHT;
 DWORD          FRGND_COLOUR;
 DWORD          BCKGND_COLOUR;
 DWORD          DST_X_Y;
 DWORD          BLT_WDTH_HGHT;           
 DWORD          NUMBER_OF_PIXELS;
 }HOSTBLTTMPLT, *LPHOSTBLTTMPLT;

//Source copy (BitBlt)
typedef         struct
{
 DWORD          Header;            //Header info used by PROMO4 to determine information type! 
 DWORD          DP_GUI_MCNTL;    //Gui master cntl.
 DWORD          SRC_OFF_PTCH;
 DWORD          DST_OFF_PTCH;
 DWORD          SRC_SC_BOTTOM_RIGHT;  //Source clipping windows(bottom, right)
 DWORD          DST_SC_TOP_LEFT;
 DWORD          DST_SC_BOTTOM_RIGHT;
 DWORD          SRC_X_Y;
 DWORD          DST_X_Y;
 DWORD          BLT_WDTH_HGHT;
}SRCCOPYTMPLT, *LPSRCCOPYTMPLT;

//Transparent Source copy (BitBlt)
typedef         struct
{
 DWORD          Header;          //Header info used by PROMO4 to determine information type! 
 DWORD          DP_GUI_MCNTL;    
 DWORD          SRC_OFF_PTCH;
 DWORD          DST_OFF_PTCH;
 DWORD          SRC_SC_BOTTOM_RIGHT;  //Source clipping windows(bottom, right)
 DWORD          DST_SC_TOP_LEFT;
 DWORD          DST_SC_BOTTOM_RIGHT;
 DWORD          CLR_CMP_CNTL;    //Determines type of colourkeying to be done!
 DWORD          SRC_CMP_CLR;     //Colour to be used when SRC colourkeying is enabled
 DWORD          DST_CMP_CLR;     //Colour to be used when DST colourkeying is enabled
 DWORD          SRC_X_Y;         
 DWORD          DST_X_Y;
 DWORD          BLT_WDTH_HGHT;
}TRANSSRCCOPYTMPLT, *LPTRANSSRCCOPYTMPLT;

//Stretch BLT (with no colourkey)
typedef         struct
{
 DWORD          Header;          //Header info used by PROMO4 to determine information type! 
 DWORD          DP_GUI_MCNTL;    //Gui master cntl.
 DWORD          SRC_OFF_PTCH;    //Note: The SCALER doesn't use the SRC_OFF_PITCH,
                                 //I have put it inside the strucuture, becasue it
                                 //makes the code easier!.    
 DWORD          DST_OFF_PTCH;
 DWORD          SRC_SC_BOTTOM_RIGHT;  //Source clipping windows(bottom, right)
 DWORD          DST_SC_TOP_LEFT;
 DWORD          DST_SC_BOTTOM_RIGHT;
 DWORD          MISC_3D_STATE_CNTL;
 DWORD          TEXT_CNTL_C;
 DWORD          PRIM_TEX_COMBINE_CNTL;
 DWORD          SCALE_3D_DATATYPE;
 DWORD          SCALE_OFFSET_0;
 DWORD          SCALE_PITCH;
 DWORD          MC_SRC1_CNTL;
 DWORD          SCALE_X_INC;
 DWORD          SCALE_Y_INC;
 DWORD          SCALE_DST_X_Y;
 DWORD          SCALE_DST_HEIGHT_WIDTH;
}SCALEBLTTMPLT, *LPSCALEBLTTMPLT;

//Stretch BLT (with no colourkey, with SRC_SC)
typedef         struct
{
 DWORD          Header;          //Header info used by PROMO4 to determine information type! 
 DWORD          DP_GUI_MCNTL;    //Gui master cntl.
 DWORD          SRC_OFF_PTCH;    //Note: The SCALER doesn't use the SRC_OFF_PITCH,
                                 //I have put it inside the strucuture, becasue it
                                 //makes the code easier!.    
 DWORD          DST_OFF_PTCH;
 DWORD          SRC_SC_BOTTOM_RIGHT;  //Source clipping windows(bottom, right)
 DWORD          DST_SC_TOP_LEFT;	 //Destination clipping windows(top, left)
 DWORD          DST_SC_BOTTOM_RIGHT; //Destination clipping windows(bottom, right)
 DWORD          MISC_3D_STATE_CNTL;
 DWORD          TEXT_CNTL_C;
 DWORD          PRIM_TEX_COMBINE_CNTL;
 DWORD          SCALE_3D_DATATYPE;
 DWORD          SCALE_OFFSET_0;
 DWORD          SCALE_PITCH;
 DWORD          MC_SRC1_CNTL;
 DWORD          SCALE_X_INC;
 DWORD          SCALE_Y_INC;
 DWORD          SCALE_DST_X_Y;
 DWORD          SCALE_DST_HEIGHT_WIDTH;
}SCALESCBLTTMPLT, *LPSCALESCBLTTMPLT;


//Stretch BLT (with colourkey)
typedef         struct
{
 DWORD          Header;          //Header info used by PROMO4 to determine information type! 
 DWORD          DP_GUI_MCNTL;    //Gui master cntl.
 DWORD          SRC_OFF_PTCH;    //Note: The SCALER doesn't use the SRC_OFF_PITCH,
                                 //I have put it inside the strucuture, becasue it
                                 //makes the code easier!.    
 DWORD          DST_OFF_PTCH;
 DWORD          SRC_SC_BOTTOM_RIGHT;  //Source clipping windows(bottom, right)
 DWORD          DST_SC_TOP_LEFT;
 DWORD          DST_SC_BOTTOM_RIGHT;
 DWORD          CLR_CMP_CNTL;
 DWORD          SRC_CMP_CLR;
 DWORD          DST_CMP_CLR;
 DWORD          MISC_3D_STATE_CNTL;
 DWORD          TEXT_CNTL_C;
 DWORD          PRIM_TEX_COMBINE_CNTL;
 DWORD          SCALE_3D_DATATYPE;
 DWORD          SCALE_OFFSET_0;
 DWORD          SCALE_PITCH;
 DWORD          MC_SRC1_CNTL;
 DWORD          SCALE_X_INC;
 DWORD          SCALE_Y_INC;
 DWORD          SCALE_DST_X_Y;
 DWORD          SCALE_DST_HEIGHT_WIDTH;
}TRANSSCALEBLTTMPLT, *LPTRANSSCALEBLTTMPLT;


typedef         struct
{
 DWORD          Header;                   //Header info used by PROMO4 to determine information type! 
 DWORD          dwOffsetPitch;            // OffsetPitch of render surface
 DWORD          DP_GUI_MASTER_CNTL_C_Reg; // Pixel Format of Surafce set in DP_GUI_MASTER_CNTL format
 DWORD          SC_TOP_LEFT_C_Reg;
 DWORD          dwWdthHght;               // Width and Height of surface(Height top 16bits)
 DWORD          dwZOffset;
 DWORD          dwZPitch;
}SETRENDERSURFTMPLT, *LPSETRENDERSURFTMPLT;

//Below is the header info. for each template used by PROMO4
//#define OpSetVertListHdr      (MakeTemplateHdr((sizeof(SETVLISTTMPLT)  / \


#define OpPaintSurfaceHdr     (MakeTemplateHdr( (sizeof(PAINTSURFACETMPLT) /   \
                              (sizeof(DWORD)) ),PaintSurfaceID,NoOverrides))  


//This is a general source copy template, it will use 
//overrides for both the source and destination surfaces

#define OpSrcCopy          (MakeTemplateHdr( (sizeof(SRCCOPYTMPLT) /   \
                              (sizeof(DWORD)) ),SrcCopyID,NoOverrides)) 
#define OpTransSrcCopy      (MakeTemplateHdr( (sizeof(TRANSSRCCOPYTMPLT) /   \
                            (sizeof(DWORD)) ),TransSrcCopyID,NoOverrides)) 
#define OpScaleBLT         (MakeTemplateHdr( (sizeof(SCALEBLTTMPLT) /   \
                            (sizeof(DWORD)) ),ScaleBltID,NoOverrides)) 

#define OpScaleSCBLT         (MakeTemplateHdr( (sizeof(SCALESCBLTTMPLT) /   \
                            (sizeof(DWORD)) ),ScaleBltID,NoOverrides)) 

#define OpTransScaleBLT     (MakeTemplateHdr( (sizeof(TRANSSCALEBLTTMPLT) /   \
                            (sizeof(DWORD)) ),TransScaleBltID,NoOverrides)) 
                            
#define OpHostBlt(N)        (MakeTemplateHdr( (sizeof(HOSTBLTTMPLT) /   \
                            (sizeof(DWORD)) ) + N,PM4_PACKET3_HOSTDATA_BLT,NoOverrides)) 

#define OpLoadPalette(N)    (MakeTemplateHdr( (sizeof(LOADPALETTETMPLT) /   \
                            (sizeof(DWORD)) ) + N,PM4_PACKET3_LOAD_PALETTE,NoOverrides)) 

//For emulator only!!!
#define SetSceneHdr           MakeTemplateHdr( (sizeof(SCENETMPLT) /   \
                              sizeof(DWORD)) +2, SetSceneID,NoOverrides)  
//
#define SetRenderSurfHdr     (MakeRegWriteConsec(mmDST_PITCH_OFFSET_C,SURF_REG_WRITES-1))

#define OpRenderPrimitives( n )    ( (DWORD)( (n-2) << 16 | NoOverrides | PM4_PACKET3_3D_RNDR_GEN_PRIM) )   
#define OpRndrIndexPrimitives( n ) ( (DWORD)( (n-2) << 16 | NoOverrides | PM4_PACKET3_3D_RNDR_GEN_INDX_PRIM ) )   

// New in Rage6
#define OpRender3DDrawIMMD( n ) ( (DWORD)( ((n-2) << 16) | NoOverrides | PM4_PACKET3_3D_DRAW_IMMD) )   
#define OpRender3DDrawINDX( n ) ( (DWORD)( ((n-2) << 16) | NoOverrides | PM4_PACKET3_3D_DRAW_INDX) )   
#define OpRender3DDrawVBUF( n ) ( (DWORD)( ((n-2) << 16) | NoOverrides | PM4_PACKET3_3D_DRAW_VBUF) )   
#define OpRender3DLoadVBPNTR(n) ( (DWORD)( ((n-2) << 16) | NoOverrides | PM4_PACKET3_3D_LOAD_VBPNTR) )   
#define OpRenderVBBaseAddr      (1 << 16 | NoOverrides | PM4_PACKET3_VB_BASE_ADDR)
#define OpRenderVBOffset        (3 << 16 | NoOverrides | PM4_PACKET3_VB_OFFSET)

#define Op3DClearZMask(n) (  ((n-2) << 16) | NoOverrides | PM4_PACKET3_3D_CLEAR_ZMASK)
// New in Chaplin 
#define OpRenderIndxBuffer( n )  ( (DWORD)( ((n-2) << 16) | NoOverrides | PM4_PACKET3_INDX_BUFFER) )   
#define OpRender3DDrawIMMD2( n ) ( (DWORD)( ((n-2) << 16) | NoOverrides | PM4_PACKET3_3D_DRAW_IMMD_2) )   
#define OpRender3DDrawVBUF2( n ) ( (DWORD)( ((n-2) << 16) | NoOverrides | PM4_PACKET3_3D_DRAW_VBUF_2) )   
#define OpRender3DDrawINDX2( n ) ( (DWORD)( ((n-2) << 16) | NoOverrides | PM4_PACKET3_3D_DRAW_INDX_2) )   
#define OpRender3DClearHIZ( n )  ( (DWORD)( ((n-2) << 16) | NoOverrides | PM4_PACKET3_3D_CLEAR_HIZ) )   

//Amount of free Promo4 entries neede for each Template
#define PaintSurfaceEntries  (sizeof(PAINTSURFACETMPLT) / (sizeof(DWORD)))
#define SrcCopyEntries       (sizeof(SRCCOPYTMPLT) / (sizeof(DWORD)))
#define TransSrcCopyEntries  (sizeof(TRANSSRCCOPYTMPLT) / (sizeof(DWORD)))
#define ScaleBltEntries      (sizeof(SCALEBLTTMPLT) / (sizeof(DWORD)))
#define ScaleSCBltEntries      (sizeof(SCALESCBLTTMPLT) / (sizeof(DWORD)))
#define TransScaleBltEntries (sizeof(TRANSSCALEBLTTMPLT) / (sizeof(DWORD)))

#define CRTCWriteEntries     2

#define RegWriteOffset           (MakeRegWriteConsec(mmCRTC_OFFSET, 1))
#define RegWriteClrCmpMsk        (MakeRegWriteConsec(mmCLR_CMP_MSK,1))
#define RegWriteCLR_CMP_CNTL     (MakeRegWriteConsec(mmCLR_CMP_CNTL,1))
#define RegWriteSRCPixWdth       (MakeRegWriteConsec(mmDP_DATATYPE,1))
#define RegWriteWAIT_UNTIL       (MakeRegWriteConsec(mmWAIT_UNTIL,1))
#define RegWriteDPWrteMsk        (MakeRegWriteConsec(mmDP_WRITE_MSK,1))
#define RegWriteGUICNTLStat      (MakeRegWriteConsec(mmPC_GUI_CTLSTAT,1))


// ColourFill:
// This macro is used to set up the the required registers
// to perform a colourfill of a given memory region.
// There is a similar inline function for DDraw in blt.c
#define ColourFill(dwFillColour) \
      {\
      ((LPPAINTSURFACETMPLT) PM4Entries)->Header = OpPaintSurfaceHdr; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->DP_GUI_MCNTL= (DP_GUI_MSTR_PAINT |   \
                                                                dwDstPixWidth); \
      ((LPPAINTSURFACETMPLT) PM4Entries)->DST_OFF_PTCH = dwDstOffPtch; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->DST_SC_TOP_LEFT = dwPAINT_TOP_LEFT; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->DST_SC_BOTTOM_RIGHT =dwPAINT_BOT_RIGHT ; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->Colour = dwFillColour; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->Start_X_Y = dwPAINT_TOP_LEFT; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->BLT_WDTH_HGHT = dwPAINT_BOT_RIGHT; \
      }

// StencilFill:
// This macro is used to set up the the required registers
// to perform a colourfill of a given memory region.
// There is a similar inline function for DDraw in blt.c
#define ColourFillCurrentWriteMask(dwFillColour) \
      {\
      ((LPPAINTSURFACETMPLT) PM4Entries)->Header = OpPaintSurfaceHdr; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->DP_GUI_MCNTL= (DP_GUI_MSTR_PAINT_CURRENT_WRITE_MASK |   \
                                                                dwDstPixWidth); \
      ((LPPAINTSURFACETMPLT) PM4Entries)->DST_OFF_PTCH = dwDstOffPtch; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->DST_SC_TOP_LEFT = dwPAINT_TOP_LEFT; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->DST_SC_BOTTOM_RIGHT =dwPAINT_BOT_RIGHT ; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->Colour = dwFillColour; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->Start_X_Y = dwPAINT_TOP_LEFT; \
      ((LPPAINTSURFACETMPLT) PM4Entries)->BLT_WDTH_HGHT = dwPAINT_BOT_RIGHT; \
      }


#endif                           


//
// $Archive: /3D/D3D/d3drage5/Rage5Direct3D/inc/common/tplates.h $
// $Author: Xwu $
// $Revision: 16 $
// $Date: 7/10/99 9:18p $
// $Modtime: 7/10/99 4:47p $
// $History: tplates.h $
// 
// *****************  Version 16  *****************
// User: Xwu          Date: 7/10/99    Time: 9:18p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Moved all windows and dxddk related include files to a new file
// atidxinc.h.
// 
// *****************  Version 15  *****************
// User: Merwin       Date: 6/17/99    Time: 2:52p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// fixed blits using 8bpp palettized source
// 
// *****************  Version 14  *****************
// User: Xwu          Date: 6/02/99    Time: 6:32p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Removed SUPPORT_RAGE5.
// 
// *****************  Version 13  *****************
// User: Cjiang       Date: 5/26/99    Time: 5:38p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Removed lots of #define RegWritexxxx which are not used anywhere.
// 
// *****************  Version 12  *****************
// User: Merwin       Date: 5/25/99    Time: 11:48a
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Changes to scaled blit code to work with emulator.
// 
// *****************  Version 11  *****************
// User: Cjiang       Date: 5/24/99    Time: 1:45p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Added Op3DClearZMask macro.
// 
// *****************  Version 10  *****************
// User: Billw        Date: 5/20/99    Time: 12:36p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// 
// *****************  Version 9  *****************
// User: Billw        Date: 5/03/99    Time: 5:25p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// 
// *****************  Version 8  *****************
// User: Cjiang       Date: 4/23/99    Time: 3:42p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Modified a comment.
// 
// *****************  Version 7  *****************
// User: Cjiang       Date: 4/22/99    Time: 5:25p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Removed code under #ifdef 0. Added defines for the third texture and Z.
// 
// *****************  Version 6  *****************
// User: Merwin       Date: 4/15/99    Time: 10:23a
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Scaling blt changes
// 
// *****************  Version 5  *****************
// User: Merwin       Date: 4/09/99    Time: 2:23p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// Rage 128 merge - added DST scissors to blt packets
// 
// *****************  Version 4  *****************
// User: Cjiang       Date: 3/03/99    Time: 11:27a
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// If SUPPORT_RAGE5 is defined, include r5enm.h.
// 
// *****************  Version 3  *****************
// User: Jweyman      Date: 2/16/99    Time: 5:17p
// Updated in $/3D/D3D/d3drage5/Rage5Direct3D/inc/common
// added header/footer
//

