#pragma once
#include <core.hpp>
#include <fstream>
#include <sstream>

namespace jnx
{
    struct File
    {
        str path;
        str source;

        File(const str& path);
    };
}