#include <shader.hpp>

namespace jnx
{
    VertexShader::VertexShader(const str& source)
    {
        id = gl::glCreateShader(gl::GL_VERTEX_SHADER);
        const gl::GLchar* source_c = (const gl::GLchar*)source.c_str();

        gl::glShaderSource(id, 1, &source_c, nullptr);
        gl::glCompileShader(id);

        i32 success = 0;
        gl::glGetShaderiv(id, gl::GL_COMPILE_STATUS, &success);

        if (success == (i32)gl::GL_FALSE)
            jnx_print("Vertex shader failed to compile!");
    }

    FragmentShader::FragmentShader(const str& source)
    {
        id = gl::glCreateShader(gl::GL_FRAGMENT_SHADER);
        const gl::GLchar* source_c = (const gl::GLchar*)source.c_str();

        gl::glShaderSource(id, 1, &source_c, nullptr);
        gl::glCompileShader(id);

        i32 success = 0;
        gl::glGetShaderiv(id, gl::GL_COMPILE_STATUS, &success);

        if (success == (i32)gl::GL_FALSE)
            jnx_print("Fragment shader failed to compile!");
    }

    GeometryShader::GeometryShader(const str& source)
    {
        id = gl::glCreateShader(gl::GL_GEOMETRY_SHADER);
        const gl::GLchar* source_c = (const gl::GLchar*)source.c_str();

        gl::glShaderSource(id, 1, &source_c, nullptr);
        gl::glCompileShader(id);

        i32 success = 0;
        gl::glGetShaderiv(id, gl::GL_COMPILE_STATUS, &success);

        if (success == (i32)gl::GL_FALSE)
            jnx_print("Geometry shader failed to compile!");
    }

    ShaderProgram::ShaderProgram()
    {
        id = gl::glCreateProgram();
        ShaderSource shaderArray[2] =
        {
            VertexShader(File("default.vs").source),
            FragmentShader(File("default.fs").source)
        };

        for (i32 i = 0; i < 2; i++)
            gl::glAttachShader(id, shaderArray[i].id);

        gl::glLinkProgram(id);

        for (i32 i = 0; i < 2; i++)
        {
            gl::glDetachShader(id, shaderArray[i].id);
            gl::glDeleteShader(shaderArray[i].id);
        }

        bind();
    }

    ShaderProgram::ShaderProgram(ShaderSource* shaderArray, u32 count)
    {
        id = gl::glCreateProgram();

        for (i32 i = 0; i < count; i++)
            gl::glAttachShader(id, shaderArray[i].id);

        gl::glLinkProgram(id);

        for (i32 i = 0; i < count; i++)
        {
            gl::glDetachShader(id, shaderArray[i].id);
            gl::glDeleteShader(shaderArray[i].id);
        }

        bind();
    }

    void ShaderProgram::bind() const
    {
        gl::glUseProgram(id);
    }

    void ShaderProgram::uniform1f(const str& name, f32 value) const
    {
        gl::glUniform1f(gl::glGetUniformLocation(id, name.c_str()), value);
    }

    void ShaderProgram::uniform2f(const str& name, const Vec2f& value) const
    {
        gl::glUniform2f(gl::glGetUniformLocation(id, name.c_str()), value.x, value.y);
    }

    void ShaderProgram::uniform3f(const str& name, const Vec3f& value) const
    {
        gl::glUniform3f(gl::glGetUniformLocation(id, name.c_str()), value.x, value.y, value.z);
    }

    void ShaderProgram::uniform4f(const str& name, const Vec4f& value) const
    {
        gl::glUniform4f(gl::glGetUniformLocation(id, name.c_str()), value.x, value.y, value.z, value.w);
    }

    void ShaderProgram::uniformMat4f(const str& name, const Mat4f& value) const
    {
        gl::glUniformMatrix4fv(gl::glGetUniformLocation(id, name.c_str()), 1, gl::GL_FALSE, &value[0][0]);
    }

    void ShaderProgram::uniform1i(const str& name, i32 value) const
    {
        gl::glUniform1i(gl::glGetUniformLocation(id, name.c_str()), value);
    }

    void ShaderProgram::uniform2i(const str& name, const Vec2i& value) const
    {
        gl::glUniform2i(gl::glGetUniformLocation(id, name.c_str()), value.x, value.y);
    }

    void ShaderProgram::uniform3i(const str& name, const Vec3i& value) const
    {
        gl::glUniform3i(gl::glGetUniformLocation(id, name.c_str()), value.x, value.y, value.z);
    }

    void ShaderProgram::uniform4i(const str& name, const Vec4i& value) const
    {
        gl::glUniform4i(gl::glGetUniformLocation(id, name.c_str()), value.x, value.y, value.z, value.w);
    }
}