#pragma once
#include <core.hpp>
#include <vector.hpp>
#include <glbinding/gl46core/gl.h>
#include <vector>

namespace jnx
{
    struct Vertex
    {
        Vec3f position;
        Vec3f normals;
        Vec2f texture;

        Vertex(const Vec3f& pos, const Vec3f& nor, const Vec2f& tex): position(pos), normals(nor), texture(tex) {}

        static inline u32 positionLocation() { return 0; }
        static inline u32 normalLocation() { return 1; }
        static inline u32 textureLocation() { return 2; }
    };

    typedef std::vector<Vertex> VertexVector;
    typedef std::vector<u32> IndexVector;

    struct ArrayBuffer
    {
    private:
        u32 id;
        u32 attribComps = 0;

    public:
        ArrayBuffer();
        ArrayBuffer(const VertexVector& array);

        void bind() const;
        void data(const VertexVector& array) const;
        void attrib(u32 location, u32 components);
    };

    struct IndexBuffer
    {
        u32 id;

    public:
        IndexBuffer();
        IndexBuffer(const IndexVector& array);

        void bind() const;
        void data(const IndexVector& array) const;
    };

    struct VertexArray
    {
    private:
        u32 id;

    public:
        VertexArray();

        void bind() const;
    };
}