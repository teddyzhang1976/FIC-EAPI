#pragma once
#include "IEAPIStorage.h"
#include "FIC-EAPI.h"
class EAPIStorageECImpl :
	public IEAPIStorage
{
private:
	static EAPIStorageECImpl* storageImpl;
	EAPIStorageECImpl();
public:
	static EAPIStorageECImpl* getInstance();
	static void delInstance();
	void test();
	/*
	*
	*      S T O R A G E
	*
	*/
	/* IDs */
	/*
	* EApiStorageCap
	*
	* Condition                                    | Return Values
	* ---------------------------------------------+------------------------------
	* Library Uninitialized                        | EAPI_STATUS_NOT_INITIALIZED
	* ((pStorageSize==NULL)&&(pBlockLength==NULL)) | EAPI_STATUS_INVALID_PARAMETER
	* Unsupported Id                               | EAPI_STATUS_UNSUPPORTED
	* Common Error                                 | Common Error Code
	* Else                                         | EAPI_STATUS_SUCCESS
	*/
		UINT32 EApiStorageCap(
		UINT32  Id, /* Storage Area Id */
		UINT32  *pStorageSize, /* Total */
		UINT32 *pBlockLength   /* Write Block Length
							   * & Alignment
							   */
							   );
	/*
	* EApiStorageAreaRead
	*
	* Condition                              | Return Values
	* ---------------------------------------+------------------------------
	* Library Uninitialized                  | EAPI_STATUS_NOT_INITIALIZED
	* pBuffer==NULL                          | EAPI_STATUS_INVALID_PARAMETER
	* ByteCnt==0                             | EAPI_STATUS_INVALID_PARAMETER
	* BufLen==0                              | EAPI_STATUS_INVALID_PARAMETER
	* unknown Id                             | EAPI_STATUS_UNSUPPORTED
	* Offset+ByteCnt>pStorageSize            | EAPI_STATUS_INVALID_BLOCK_LENGTH
	* Read Error                             | EAPI_STATUS_READ_ERROR
	* ByteCnt>BufLen                         | EAPI_STATUS_MORE_DATA
	* Common Error                           | Common Error Code
	* Else                                   | EAPI_STATUS_SUCCESS
	*/
UINT32 EApiStorageAreaRead(
		UINT32 Id, /* Storage Area Id */
		UINT32  Offset, /* Byte Offset */
		void *pBuffer, /* Pointer to Data pBuffer */
		UINT32  BufLen, /* Data pBuffer Size in
						* bytes
						*/
						UINT32  ByteCnt   /* Number of bytes to read */
						);
	/*
	* EApiStorageAreaWrite
	*
	* Condition                              | Return Values
	* ---------------------------------------+------------------------------
	* Library Uninitialized                  | EAPI_STATUS_NOT_INITIALIZED
	* pBuffer==NULL                          | EAPI_STATUS_INVALID_PARAMETER
	* ByteCnt==0                             | EAPI_STATUS_INVALID_PARAMETER
	* unknown Id                             | EAPI_STATUS_UNSUPPORTED
	* Offset%pBlockLength                    | EAPI_STATUS_INVALID_BLOCK_ALIGNMENT
	* ByteCnt%pBlockLength                   | EAPI_STATUS_INVALID_BLOCK_ALIGNMENT
	* Offset+ByteCnt>pStorageSize            | EAPI_STATUS_INVALID_BLOCK_LENGTH
	* Write Error                            | EAPI_STATUS_WRITE_ERROR
	* Common Error                           | Common Error Code
	* Else                                   | EAPI_STATUS_SUCCESS
	*/
		UINT32 EApiStorageAreaWrite(
		UINT32  Id, /* Storage Area Id */
		UINT32  Offset, /* Byte Offset */
		void *pBuffer, /* Pointer to Data pBuffer */
		UINT32 ByteCnt   /* Number of bytes to write */
		);
};

