#include <vertex.hpp>

namespace jnx
{
    namespace gl46core = gl;

    ArrayBuffer::ArrayBuffer()
    {
        gl::glGenBuffers(1, &id);
        bind();
    }

    ArrayBuffer::ArrayBuffer(const VertexVector& array)
    {
        gl::glGenBuffers(1, &id);
        bind();
        data(array);
    }

    void ArrayBuffer::bind() const
    {
        gl::glBindBuffer(gl::GL_ARRAY_BUFFER, id);
    }

    void ArrayBuffer::data(const VertexVector& array) const
    {
        bind();
        gl::glBufferData(gl::GL_ARRAY_BUFFER, sizeof(Vertex) * array.size(), &array[0], gl::GL_STATIC_DRAW);
    }

    void ArrayBuffer::attrib(u32 location, u32 components)
    {
        gl::glEnableVertexAttribArray(location);
        gl::glVertexAttribPointer(location, components, gl::GL_FLOAT, gl::GL_FALSE, sizeof(Vertex), (void*)(sizeof(f32) * attribComps));
        attribComps += components;
    }

    IndexBuffer::IndexBuffer()
    {
        gl::glGenBuffers(1, &id);
        bind();
    }

    IndexBuffer::IndexBuffer(const IndexVector& array)
    {
        gl::glGenBuffers(1, &id);
        bind();
        data(array);
    }

    void IndexBuffer::bind() const
    {
        gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, id);
    }

    void IndexBuffer::data(const IndexVector& array) const
    {
        bind();
        gl::glBufferData(gl::GL_ELEMENT_ARRAY_BUFFER, sizeof(u32) * array.size(), &array[0], gl::GL_STATIC_DRAW);
    }

    VertexArray::VertexArray()
    {
        gl::glGenVertexArrays(1, &id);
        bind();
    }

    void VertexArray::bind() const
    {
        gl::glBindVertexArray(id);
    }
}