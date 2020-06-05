#include <texture.hpp>

namespace jnx
{
    Image::Image(u32 width, u32 height, const Color& color): width(width), height(height)
    {
        pixels = (Color*)malloc(sizeof(Color) * (width * height));

        for (i32 i = 0; i < width * height; i++)
            pixels[i] = color;
    }

    Image::Image(u32 width, u32 height, const Color* array): width(width), height(height)
    {
        pixels = (Color*)malloc(sizeof(Color) * (width * height));

        for (i32 i = 0; i < width * height; i++)
            pixels[i] = array[i];
    }

    Image::Image(u32 width, u32 height, const str& path): width(width), height(height)
    {
        pixels = (Color*)malloc(sizeof(Color) * (width * height));

        auto image = ilGenImage();
        ilBindImage(image);
        ilLoadImage(path.c_str());

        if (ilGetInteger(IL_IMAGE_FORMAT) == IL_RGB)
            for (i32 i = 0; i < width * height; i++)
                pixels[i] = Color(ilGetData()[i * 3 + 0], ilGetData()[i * 3 + 1], ilGetData()[i * 3 + 2]);

        if (ilGetInteger(IL_IMAGE_FORMAT) == IL_RGBA)
            for (i32 i = 0; i < width * height; i++)
                pixels[i] = Color(ilGetData()[i * 3 + 0], ilGetData()[i * 3 + 1], ilGetData()[i * 3 + 2], ilGetData()[i * 3 + 3]);

        ilBindImage(0);
        ilDeleteImage(image);
    }

    Image::Image(const Texture& texture): width(texture.width), height(texture.height)
    {
        gl::glTextureSubImage2D(texture.id, 0, 0, 0, width, height, gl::GL_RGBA, gl::GL_UNSIGNED_BYTE, pixels);
    }

    Image::~Image()
    {
        delete[] pixels;
    }

    void Image::invert()
    {
        for (i32 i = 0; i < width * height; i++)
            pixels[i] = pixels[i].invert();
    }

    Image Image::getSub(u32 x, u32 y, u32 width, u32 height) const
    {
        Color* result = (Color*)alloca(sizeof(Color) * (width * height));

        for (i32 i = 0; i < width; i++)
            for (i32 j = 0; j < height; j++)
                result[i + j * width] = pixels[(i + x) + (j + y) * this->width];

        return Image(width, height, result);
    }

    Texture::Texture(const Image& image): width(image.width), height(image.height)
    {
        gl::glGenTextures(1, &id);
        bind(0);
        gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_WRAP_S, gl::GL_CLAMP_TO_EDGE);
        gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_WRAP_T, gl::GL_CLAMP_TO_EDGE);
        gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MIN_FILTER, gl::GL_LINEAR);
        gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MAG_FILTER, gl::GL_LINEAR);
        gl::glTexImage2D(gl::GL_TEXTURE_2D, 0, gl::GL_RGBA, width, height, 0, gl::GL_RGBA, gl::GL_UNSIGNED_BYTE, image.pixels);
        gl::glGenerateMipmap(gl::GL_TEXTURE_2D);
    }

    Texture::~Texture()
    {
        dispose();
    }

    void Texture::dispose()
    {
        bind(0);
        gl::glDeleteTextures(1, &id);
        id = 0;
    }

    void Texture::bind(u32 slot) const
    {
        gl::glActiveTexture(gl::GL_TEXTURE0 + slot);
        gl::glBindTexture(gl::GL_TEXTURE_2D, id);
    }

    Texture Texture::getSub(u32 x, u32 y, u32 width, u32 height) const
    {
        auto pixels = (Color*)alloca(sizeof(Color) * (width * height));
        gl::glTextureSubImage2D(id, 0, x, y, width, height, gl::GL_RGBA, gl::GL_UNSIGNED_BYTE, pixels);
        delete[] pixels;

        return Texture(width, height, pixels);
    }
}