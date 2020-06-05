#include <file.hpp>

namespace jnx
{
    File::File(const str& path): path(path)
    {
        std::ifstream ifstream(path);
        std::stringstream buffer;
        buffer << ifstream.rdbuf();
        source = buffer.str();
    }
}