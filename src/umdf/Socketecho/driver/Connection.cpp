/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    Connection.cpp

Abstract:

    Module for the socket connection specfic routines in the driver. 
    Makes Connection to the server given server host and port address.  
    
Environment:

    User mode only


--*/

#include "internal.h"
#include "connection.tmh"


CConnection::CConnection()
/*++

Routine Description:

  Constructor for connection object     
    
Arguments:
    
 None

Return Value:

    VOID

--*/    
{

  // Initialize the socket member as Invalid 
    Trace(
        TRACE_LEVEL_INFORMATION, 
        "%!FUNC!"
        );
    m_Socket = INVALID_SOCKET;

}

HRESULT 
CConnection::Connect(
    __in   LPSTR  hostStr ,
    __in LPSTR portStr 
    )
/*++

Routine Description:

   This routine is for the initialization of the connection object associated 
   with the File Object . It is invoked from the dispatch OnCreateFile on the 
   default queue callback of the driver.       
       
Arguments:
    
  pDevice = Wdf Device Object 

Return Value:

    S_OK if success , error HRESULT otherwise 

--*/      
{
        
   Trace(
        TRACE_LEVEL_INFORMATION, 
        "%!FUNC!"
        );
   
    HRESULT hr = S_OK;

    addrinfo* info = NULL ;
       
      //
      // lookup hostname with addrinfo  hints;
      //
    
    addrinfo hints;

    ZeroMemory(&hints,sizeof(hints));
    
    hints.ai_family = AF_INET;
    
    hints.ai_socktype = SOCK_STREAM;
    
    hints.ai_protocol = IPPROTO_TCP;
    
   
    int n = getaddrinfo(hostStr,portStr,const_cast<struct addrinfo*>(&hints),&info);


    if (n != 0)
    {
        DWORD err = WSAGetLastError();
        Trace(
            TRACE_LEVEL_ERROR,
            L"ERROR: Unable to find address/port of host %!winerr!",
            err
            );
        hr = HRESULT_FROM_WIN32(err);
        goto Clean0;
    }

       //
       // Create a socket with this infomation recvd in getaddrinfo
       //
     
    m_Socket = socket(info->ai_family,info->ai_socktype,info->ai_protocol);

    
    if (m_Socket == INVALID_SOCKET) 
    {
        DWORD err = WSAGetLastError();

        Trace(
            TRACE_LEVEL_ERROR,
            L"ERROR: Unable to create socket %!winerr!",
            err
            );

        hr = HRESULT_FROM_WIN32(err);

        goto Clean0;
    }

    //
    // If that succeeds , proceed to connect to the socket 
    //

    
    ATLASSERT(info->ai_addrlen <= 0x7fffffff);

    int nret = connect(m_Socket,info->ai_addr,(int)info->ai_addrlen);

    if (nret == SOCKET_ERROR)
    {
        DWORD err = WSAGetLastError();
        Trace(
            TRACE_LEVEL_ERROR,
            L"ERROR: Unable to connect to host %!winerr!",
            err
            );
        hr = HRESULT_FROM_WIN32(err);

        goto Clean0;
    }

 

Clean0:
 
    if (info != NULL)
    {
        freeaddrinfo(info);

    }

    if (FAILED(hr) && m_Socket != INVALID_SOCKET)
    {
        closesocket(m_Socket);
        m_Socket = INVALID_SOCKET;
    }
      
    return hr;
    
}

HANDLE 
CConnection::GetSocketHandle(
    )
/*++

Routine Description:

  Function returns the socket handle associated with this connection object    
    
Arguments:
    
 None

Return Value:

    Socket handle if valid socket 
    INVALID_HANDLE_VALUE otherwise 

--*/        
{
    Trace(
        TRACE_LEVEL_INFORMATION, 
        "%!FUNC!"
        );
    if ( INVALID_SOCKET != m_Socket ) 
    {
        return (HANDLE)m_Socket ;
    }
    else 
    {
        return INVALID_HANDLE_VALUE;
     }
        
}


VOID
CConnection::Close()
/*++

Routine Description:

  Closes the socket connection to the server associated with this connection object 
    
Arguments:
    
 None

Return Value:

    None
--*/        
{
    Trace(
        TRACE_LEVEL_INFORMATION, 
        "%!FUNC!"
        );
    if (m_Socket != INVALID_SOCKET)
    {
        closesocket(m_Socket);
        m_Socket = INVALID_SOCKET;
    }
  

}


