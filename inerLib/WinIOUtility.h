#pragma once
#include <windows.h>

class CWinIOUtility
{
protected:
    CWinIOUtility() {}

public:
    ~CWinIOUtility() {}

    static bool InitWinIO( int nMaxRetry = 10 );
    static void FinalizeWinIO();
    static bool IsInitialized();

    static DWORD ReadECData( DWORD dwIndex, unsigned int uByte );
    static void WriteECData( DWORD dwIndex, BYTE uData );
	static void FastWriteECData(DWORD dwIndex, BYTE uData);
	static void SendECCommand( DWORD dwIndex );

    static void WriteCMOS0Data( int nIndex, unsigned char uData );
    static DWORD ReadCMOS0Data( int nIndex );
    static void WriteCMOS1Data( int nIndex, unsigned char uData );
    static DWORD ReadCMOS1Data( int nIndex );


    static bool ReadPortValue( WORD wPortAddr, DWORD& dwPortVal, unsigned int uByte );
    static bool WritePortValue( WORD wPortAddr, DWORD dwPortVal, unsigned int uByte );

	static DWORD getCPUTemperature();

protected:
    static bool m_bIsWinIoInitialized;
};

