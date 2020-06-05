#pragma once
#include <iostream>

namespace jnx
{
    typedef std::int8_t     i8;
    typedef std::int16_t    i16;
    typedef std::int32_t    i32;
    typedef std::int64_t    i64;

    typedef std::uint8_t    u8;
    typedef std::uint16_t   u16;
    typedef std::uint32_t   u32;
    typedef std::uint64_t   u64;

    typedef float           f32;
    typedef double          f64;

    typedef std::string     str;
}

#if defined(_WIN32)
#define JNX_PLATFORM_WINDOWS
#endif

#if defined(__linux__)
#define JNX_PLATFORM_LINUX
#endif

#if defined(__MACH__)
#define JNX_PLATFORM_MAC
#endif

#if defined(__FreeBSD__)
#define JNX_PLATFORM_BSD
#endif

#if defined(__unix__)
#define JNX_PLATFORM_UNIX
#endif

#define jnx_print(message) std::cout << message << std::endl