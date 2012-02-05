#ifndef NDISAPI_QT_H
#define NDISAPI_QT_H

#include "ndisapi_qt_global.h"
#include "windows.h"
#include "common.h"
#include "winioctl.h"
#include<TChar.h>

#define _WINDOWS
#ifndef UPFIRE_DLL_COFF_H
 #define WCHAR_CHAR WCHAR *
#else
 #define WCHAR_CHAR CHAR *
#endif

#if defined(NDISAPI_QT_LIBRARY)
#  define NDISAPI_API Q_DECL_EXPORT
#else
#  define NDISAPI_API Q_DECL_EXPORT
#endif

#ifndef _T
  #define _T (TCHAR*)
#endif

class NDISAPI_QTSHARED_EXPORT Ndisapi_qt {
public:
    Ndisapi_qt();
};

enum
{
        FILE_NAME_SIZE = 1000
};

typedef bool (__stdcall *IsWow64ProcessPtr)(HANDLE hProcess, PBOOL Wow64Process);

// This class is exported from the ndisapi.dll
class NDISAPI_API CNdisApi
{
public:
        CNdisApi (const TCHAR* pszFileName = (TCHAR*)_T(DRIVER_NAME_A))
        {
                TCHAR pszFullName [ FILE_NAME_SIZE ];

                // Format full file name
                _tcscpy ( (char*)pszFullName, _T("\\\\.\\") );
                _tcscat ( (char*)pszFullName, (char*)pszFileName );

                m_bIsLoadSuccessfully = FALSE;

                // We open driver for overlapped I/O, though none of current driver services are processed asynchronously
                m_hFileHandle = ::CreateFile ( pszFullName, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0 );

                // If driver is opened succesfully we initialize our OVERLAPPED structure
                if   ( m_hFileHandle == INVALID_HANDLE_VALUE )
                {
                        m_ovlp.hEvent = 0;
                }
                else
                {
                        m_ovlp.hEvent = CreateEvent ( 0, TRUE, FALSE, NULL );
                        if ( m_ovlp.hEvent )
                        {
                                m_bIsLoadSuccessfully = TRUE;
                        }
                }

                m_BytesReturned = 0;

                //
                // Check if we are running in WOW64
                //
                m_bIsWow64Process = FALSE;
                m_Version.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
                ::GetVersionEx(&m_Version);
                if (((m_Version.dwMajorVersion == 5)&&(m_Version.dwMinorVersion >= 1))/*Windows XP/2003*/ || (m_Version.dwMajorVersion > 5)/*Windows Vista or later*/)
                {
                         HMODULE hKernel32 = ::GetModuleHandle(TEXT((WCHAR_CHAR)"kernel32.dll"));
                         if (hKernel32)
                         {
                                m_pfnIsWow64Process = (IsWow64ProcessPtr)::GetProcAddress(hKernel32, "IsWow64Process");
                                if (m_pfnIsWow64Process)
                                {
                                        m_pfnIsWow64Process ( GetCurrentProcess(), &m_bIsWow64Process );
                                }
                         }
                }
        }
        virtual ~CNdisApi ()
        {
                if ( m_hFileHandle != INVALID_HANDLE_VALUE )
                {
                        ::CloseHandle ( m_hFileHandle );
                }

            if ( m_ovlp.hEvent )
                {
                        ::CloseHandle ( m_ovlp.hEvent );
                }
        }


        // Public member functions
        BOOL	DeviceIoControl (DWORD dwService, void *BuffIn, int SizeIn, void *BuffOut, int SizeOut, unsigned long *SizeRet = NULL, LPOVERLAPPED povlp = NULL);

        // Driver services
        ULONG	GetVersion ();
        BOOL	GetTcpipBoundAdaptersInfo ( PTCP_AdapterList pAdapters );
        BOOL	SendPacketToMstcp ( PETH_REQUEST pPacket );
        BOOL	SendPacketToAdapter ( PETH_REQUEST pPacket );
        BOOL	ReadPacket ( PETH_REQUEST pPacket );
        BOOL	SendPacketsToMstcp (PETH_M_REQUEST pPackets);
        BOOL	SendPacketsToAdapter(PETH_M_REQUEST pPackets);
        BOOL	ReadPackets(PETH_M_REQUEST pPackets);
        BOOL	SetAdapterMode ( PADAPTER_MODE pMode );
        BOOL	GetAdapterMode ( PADAPTER_MODE pMode );
        BOOL	FlushAdapterPacketQueue ( HANDLE hAdapter );
        BOOL	GetAdapterPacketQueueSize ( HANDLE hAdapter, PDWORD pdwSize );
        BOOL	SetPacketEvent ( HANDLE hAdapter, HANDLE hWin32Event );
        BOOL	SetWANEvent ( HANDLE hWin32Event );
        BOOL	SetAdapterListChangeEvent ( HANDLE hWin32Event );
        BOOL	NdisrdRequest ( PPACKET_OID_DATA OidData, BOOL Set );
        BOOL	GetRasLinks (HANDLE hAdapter, PRAS_LINKS pLinks);
        BOOL	SetHwPacketFilter ( HANDLE hAdapter, DWORD Filter );
        BOOL	GetHwPacketFilter ( HANDLE hAdapter, PDWORD pFilter );
        BOOL	SetPacketFilterTable (PSTATIC_FILTER_TABLE pFilterList );
        BOOL	ResetPacketFilterTable ();
        BOOL	GetPacketFilterTableSize ( PDWORD pdwTableSize );
        BOOL	GetPacketFilterTable ( PSTATIC_FILTER_TABLE pFilterList );
        BOOL	GetPacketFilterTableResetStats ( PSTATIC_FILTER_TABLE pFilterList );

        static BOOL		SetMTUDecrement ( DWORD dwMTUDecrement );
        static DWORD	GetMTUDecrement ();

        static BOOL		SetAdaptersStartupMode ( DWORD dwStartupMode );
        static DWORD	GetAdaptersStartupMode ();

        BOOL	IsDriverLoaded ();
        DWORD	GetBytesReturned ();

        // Helper routines
        static BOOL
                ConvertWindowsNTAdapterName (
                        LPCSTR szAdapterName,
                        LPSTR szUserFriendlyName,
                        DWORD dwUserFriendlyNameLength
                        );

        static BOOL
                ConvertWindows2000AdapterName (
                        LPCSTR szAdapterName,
                        LPSTR szUserFriendlyName,
                        DWORD dwUserFriendlyNameLength
                        );

        static BOOL
                ConvertWindows9xAdapterName (
                        LPCSTR szAdapterName,
                        LPSTR szUserFriendlyName,
                        DWORD dwUserFriendlyNameLength
                        );

private:
        // Private member variables
        OVERLAPPED				m_ovlp;
        HANDLE					m_hFileHandle;
        DWORD					m_BytesReturned;
        BOOL					m_bIsLoadSuccessfully;
        OSVERSIONINFO			m_Version;
        IsWow64ProcessPtr		m_pfnIsWow64Process;
        BOOL					m_bIsWow64Process;
        TCP_AdapterList_WOW64	m_AdaptersList;
};

extern "C"
{

HANDLE	__stdcall		OpenFilterDriver ( const TCHAR* pszFileName = (TCHAR*)_T(DRIVER_NAME_A) );
VOID	__stdcall		CloseFilterDriver ( HANDLE hOpen );
DWORD	__stdcall		GetDriverVersion ( HANDLE hOpen );
BOOL	__stdcall		GetTcpipBoundAdaptersInfo ( HANDLE hOpen, PTCP_AdapterList pAdapters );
BOOL	__stdcall		SendPacketToMstcp ( HANDLE hOpen, PETH_REQUEST pPacket );
BOOL	__stdcall		SendPacketToAdapter ( HANDLE hOpen, PETH_REQUEST pPacket );
BOOL	__stdcall		ReadPacket ( HANDLE hOpen, PETH_REQUEST pPacket );
BOOL	__stdcall		SendPacketsToMstcp ( HANDLE hOpen, PETH_M_REQUEST pPackets );
BOOL	__stdcall		SendPacketsToAdapter ( HANDLE hOpen, PETH_M_REQUEST pPackets );
BOOL	__stdcall		ReadPackets ( HANDLE hOpen, PETH_M_REQUEST pPackets );
BOOL	__stdcall		SetAdapterMode ( HANDLE hOpen, PADAPTER_MODE pMode );
BOOL	__stdcall		GetAdapterMode ( HANDLE hOpen, PADAPTER_MODE pMode );
BOOL	__stdcall		FlushAdapterPacketQueue ( HANDLE hOpen, HANDLE hAdapter );
BOOL	__stdcall 		GetAdapterPacketQueueSize ( HANDLE hOpen, HANDLE hAdapter , PDWORD pdwSize);
BOOL	__stdcall		SetPacketEvent ( HANDLE hOpen, HANDLE hAdapter, HANDLE hWin32Event );
BOOL	__stdcall		SetWANEvent ( HANDLE hOpen, HANDLE hWin32Event );
BOOL	__stdcall		SetAdapterListChangeEvent ( HANDLE hOpen, HANDLE hWin32Event );
BOOL	__stdcall		NdisrdRequest ( HANDLE hOpen, PPACKET_OID_DATA OidData, BOOL Set );
BOOL	__stdcall		GetRasLinks ( HANDLE hOpen, HANDLE hAdapter, PRAS_LINKS pLinks);
BOOL	__stdcall		SetHwPacketFilter ( HANDLE hOpen, HANDLE hAdapter, DWORD Filter );
BOOL	__stdcall		GetHwPacketFilter ( HANDLE hOpen, HANDLE hAdapter, PDWORD pFilter );
BOOL	__stdcall		SetPacketFilterTable ( HANDLE hOpen, PSTATIC_FILTER_TABLE pFilterList );
BOOL	__stdcall		ResetPacketFilterTable ( HANDLE hOpen );
BOOL	__stdcall		GetPacketFilterTableSize ( HANDLE hOpen, PDWORD pdwTableSize );
BOOL	__stdcall		GetPacketFilterTable ( HANDLE hOpen, PSTATIC_FILTER_TABLE pFilterList );
BOOL	__stdcall		GetPacketFilterTableResetStats ( HANDLE hOpen, PSTATIC_FILTER_TABLE pFilterList );
BOOL	__stdcall		SetMTUDecrement ( DWORD dwMTUDecrement );
DWORD	__stdcall		GetMTUDecrement ();
BOOL	__stdcall		SetAdaptersStartupMode ( DWORD dwStartupMode );
DWORD	__stdcall		GetAdaptersStartupMode ();
BOOL	__stdcall		IsDriverLoaded ( HANDLE hOpen );
DWORD	__stdcall		GetBytesReturned ( HANDLE hOpen );

// Helper routines
BOOL __stdcall
                ConvertWindowsNTAdapterName (
                        LPCSTR szAdapterName,
                        LPSTR szUserFriendlyName,
                        DWORD dwUserFriendlyNameLength
                        );

BOOL __stdcall
                ConvertWindows2000AdapterName (
                        LPCSTR szAdapterName,
                        LPSTR szUserFriendlyName,
                        DWORD dwUserFriendlyNameLength
                        );

BOOL __stdcall
                ConvertWindows9xAdapterName (
                        LPCSTR szAdapterName,
                        LPSTR szUserFriendlyName,
                        DWORD dwUserFriendlyNameLength
                        );
}
#endif // NDISAPI_QT_H
