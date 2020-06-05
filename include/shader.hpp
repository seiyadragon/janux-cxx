#pragma once
#include <core.hpp>
#include <glbinding/gl46core/gl.h>
#include <vector.hpp>
#include <matrix.hpp>
#include <file.hpp>
#include <vertex.hpp>

namespace jnx
{
    namespace gl46core = gl;

    struct ShaderSource
    {
        u32 id;
    };

    struct VertexShader: public ShaderSource
    {
        VertexShader(const str& source);
    };

    struct FragmentShader: public ShaderSource
    {
        FragmentShader(const str& source);
    };

    struct GeometryShader: public ShaderSource
    {
        GeometryShader(const str& source);
    };

    struct ShaderProgram
    {
        u32 id;
        str matrixUniform;

        ShaderProgram();
        ShaderProgram(ShaderSource* shaderArray, u32 count);

        void bind() const;

        void uniform1f(const str& name, f32 value) const;
        void uniform2f(const str& name, const Vec2f& value) const;
        void uniform3f(const str& name, const Vec3f& value) const;
        void uniform4f(const str& name, const Vec4f& value) const;
        void uniformMat4f(const str& name, const Mat4f& value) const;

        void uniform1i(const str& name, i32 value) const;
        void uniform2i(const str& name, const Vec2i& value) const;
        void uniform3i(const str& name, const Vec3i& value) const;
        void uniform4i(const str& name, const Vec4i& value) const;
    };
}