#ifndef _UTILITYLIB_H_        
#define _UTILITYLIB_H_

#ifdef __cplusplus
#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS
#define __STDC_FORMAT_MACROS
#endif
#define EAPI_BUILDING_LIB

#include <stdlib.h>
//#include "FIC-EAPI.h"

#define EAPI_PLATFORM_COM0 1
#define EAPI_PLATFORM_ETX  2
#define EAPI_PLATFORM_Q7   3
#define EAPI_PLATFORM_TCA  4
extern int StatusCode;
#if !defined EAPI_PLATFORM
#  define EAPI_PLATFORM EAPI_PLATFORM_COM0
#endif 



#ifndef EAPI_EMUL_DELAY_NS
#   define EAPI_EMUL_DELAY_NS(x)
#endif

#ifndef EAPI_LIB_MSG_OUT
#  include <stdio.h>
#  if 0
#    define EAPI_LIB_MSG_OUT(...) printf("E " ## __VA_ARGS__)
#  else
#    define EAPI_LIB_MSG_OUT(x)  printf x 
#  endif
#endif

#ifndef EAPI_LIB_ERR_OUT
#  include <stdio.h>
#  if 0
#    define EAPI_LIB_ERR_OUT(...) printf("O " ## __VA_ARGS__)
#  else
#    define EAPI_LIB_ERR_OUT(x)   printf x 
#  endif
#endif


#if (STRICT_VALIDATION>1)
#define EAPI_FORMATED_MES1(type, func, err, desc) \
	siFormattedMessage_M2(type, __FILE__, #func, __LINE__, \
	err, "%s\n", desc);
#else
#define EAPI_FORMATED_MES1(type, func, err, desc)
#endif

#if (STRICT_VALIDATION>1)
#define EAPI_FORMATED_MES(type, func, err, desc) \
	siFormattedMessage_SC(type, __FILE__, #func, __LINE__, \
	(EApiStatus_t)(((uintptr_t)err)&UINT32_MAX), "%s\n", desc);

#else
#define EAPI_FORMATED_MES(type, func, err, desc)
#endif

#define EAPI_LIB_RETURN_SUCCESS(func, desc)  EAPI_FORMATED_MES('L', func, EAPI_STATUS_SUCCESS, desc); 

#define EAPI_LIB_RETURN_ERROR(func, err, desc) EAPI_FORMATED_MES('E', func, err, desc); 


#define EAPI_LIB_RETURN_ERROR_IF(func, exp, err, desc)  EAPI_LIB_RETURN_ERROR(func, err, desc);

#define EAPI_LIB_RETURN_ERROR_IF_S(func, exp, err)  EAPI_LIB_RETURN_ERROR(func, err, TEXT(#exp));

#if (STRICT_VALIDATION>1)
#  define EAPI_LIB_ASSERT_PARAMATER_CHECK(func, exp, desc)  \
	EAPI_LIB_RETURN_ERROR_IF(func, exp, EAPI_STATUS_INVALID_PARAMETER, desc)
#else
#  define EAPI_LIB_ASSERT_PARAMATER_CHECK(func, exp, desc)
#endif

#define EAPI_LIB_ASSERT_PARAMATER_CHECK_S(func, exp)  \
	EAPI_LIB_ASSERT_PARAMATER_CHECK(func, exp, #exp)

#define EAPI_LIB_ASSERT_PARAMATER_ZERO(func, val)  \
	EAPI_LIB_ASSERT_PARAMATER_CHECK_S(func, (val == 0))

#define EAPI_LIB_ASSERT_PARAMATER_NULL(func, val)  \
	EAPI_LIB_ASSERT_PARAMATER_CHECK_S(func, (val == NULL))


#define EAPI_LIB_PREVENT_BUF_OVERFLOW(func, x, y)  \
if (x > y)\
{\
	EAPI_FORMATED_MES('E', func, EAPI_STATUS_MORE_DATA, \
	" pBuffer Overflow Prevented" #x ">" #y); \
	x = y; \
	StatusCode = EAPI_STATUS_MORE_DATA; \
}

//#define // :


#endif /* _EAPILIB_H_ */