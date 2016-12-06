#pragma once

#ifndef _DEFINES_H
#define	_DEFINES_H

// #ifdef __WIN32__
// #include <crtdbg.h>
// #endif

//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW

#define DEF_SQLS 20
#define DEF_MAXSERVERS 200

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <list>
#include <map>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <memory.h>
#include <time.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;


#ifdef UINT64_MAX
#undef UINT64_MAX
#endif

#ifdef INT64_MAX
#undef INT64_MAX
#endif

#ifdef UINT32_MAX
#undef UINT32_MAX
#endif

#ifdef INT32_MAX
#undef INT32_MAX
#endif

#ifdef UINT16_MAX
#undef UINT16_MAX
#endif

#ifdef INT16_MAX
#undef INT16_MAX
#endif

#ifdef UINT8_MAX
#undef UINT8_MAX
#endif

#ifdef INT8_MAX
#undef INT8_MAX
#endif


#ifndef UINT64_MAX
#define UINT64_MAX ((uint64_t_)(0xffffffffffffffffULL))
#endif

#ifndef INT64_MAX
#define INT64_MAX  ((int64_t)(0x7fffffffffffffffLL))
#endif

#ifndef INT64_MIN
#define INT64_MIN  ((int64_t)(0x8000000000000000LL))
#endif

#ifndef UINT32_MAX
#define UINT32_MAX ((uint32_t_)(0xffffffffUL))
#endif

#ifndef INT32_MAX
#define INT32_MAX  ((int32_t)(0x7fffffffL))
#endif

#ifndef INT32_MIN
#define INT32_MIN  ((int32_t)(0x80000000L))
#endif

#ifndef UINT16_MAX
#define UINT16_MAX ((uint16_t_)(0xffff))
#endif

#ifndef INT16_MAX
#define INT16_MAX  ((int16_t_)(0x7fff))
#endif

#ifndef INT16_MIN
#define INT16_MIN  ((int16_t_)(0x8000))
#endif

#ifndef UINT8_MAX
#define UINT8_MAX  ((uint8_t_)(0xff))
#endif

#ifndef INT8_MAX
#define INT8_MAX   ((int8_t_)(0x7f))
#endif

#ifndef INT8_MIN
#define INT8_MIN   ((int8_t_)(0x80))
#endif

enum Amf3TypeCode
{
	Undefined = 0,
	Null = 1,
	False = 2,
	True = 3,
	Integer = 4,
	Number = 5,
	String = 6,
	LegacyXmlDocument = 7,
	Date = 8,
	Array = 9,
	Object = 10,
	Xml = 11,
	ByteArray = 12
};
enum Flags
{
	Inline = 1,
	InlineClassDef = 2,
	Externalizable = 4,
	Dynamic = 8
};

#endif	/* _DEFINES_H */

