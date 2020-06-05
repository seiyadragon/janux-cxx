#pragma once
#include <core.hpp>
#include <vector.hpp>
#include <IL/il.h>
#include <glbinding/gl46core/gl.h>

namespace jnx
{
    namespace gl = gl46core;

    struct Color
    {
        u8 r;
        u8 g;
        u8 b;
        u8 a;

        Color(): r(0), g(0), b(0), a(0) {}

        Color(u8 r, u8 g, u8 b, u8 a): r(r), g(g), b(b), a(a) {}
        Color(u8 r, u8 g, u8 b): r(r), g(g), b(b), a(255) {}

        Color(const Vec4f& color): r(color.x * 255), g(color.y * 255), b(color.z * 255), a(color.w * 255) {}
        Color(i32 hex): a((hex >> 24) & 0xFF), r((hex >> 16) & 0xFF), g((hex >> 8) & 0xFF), b((hex >> 0) & 0xFF) {}

        inline Vec4f toFloat() const { return Vec4f(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f); }

        Color invert() { return Color(255 - r, 255 - g, 255 - b); }

        bool operator==(const Color& color) { return r == color.r && g == color.g && b == color.b && a == color.a; }
    };

    struct Texture;
    struct Image;

    struct Image
    {
        Color* pixels;
        u32 width;
        u32 height;

        Image(u32 width, u32 height, const Color& color);
        Image(u32 width, u32 height, const Color* array);
        Image(u32 width, u32 height, const str& path);
        Image(const Texture& texture);

        virtual ~Image();

        void invert();

        Image getSub(u32 x, u32 y, u32 width, u32 height) const;
    };

    struct Texture
    {
        u32 id;
        u32 width;
        u32 height;
        
        Texture(u32 width, u32 height, const Color& color): Texture(Image(width, height, color)) {}
        Texture(u32 width, u32 height, const Color* pixels): Texture(Image(width, height, pixels)) {}
        Texture(u32 width, u32 height, const str& path): Texture(Image(width, height, path)) {}
        Texture(const Image& image);
        
        virtual ~Texture();
        void dispose();

        void bind(u32 slot) const;
        Texture getSub(u32 x, u32 y, u32 width, u32 height) const;
    };
}