#pragma once
#include <transform.hpp>
#include <vertex.hpp>
#include <shader.hpp>
#include <texture.hpp>
#include <file.hpp>

namespace jnx
{
    struct Mesh
    {
        VertexVector vertices;
        IndexVector indices;
        VertexArray vao;
        ArrayBuffer abo;
        IndexBuffer ibo;

        Mesh();
        Mesh(const VertexVector& vertices, const IndexVector& indices);

        void bind() const;
        u32 size() const;
    };

    struct Drawable
    {
        Mesh mesh;
        ShaderProgram shader;
        Transform transform;

        virtual void draw() const = 0;

        void translate(const Vec3f& position);
        void rotate(const Vec3f& rotation);
        void scale(const Vec3f& scale);
    };

    struct Sprite: public Drawable
    {
    private:
        Texture texture;
        Color color;
        
    public:
        Vec2f position = Vec2f(0, 0);
        Vec2f size = Vec2f(1, 1);
        f32 rotation = 0;

        Sprite(f32 width, f32 height, const Color& color);

        void setTexture(const Texture& texture);
        void setColor(const Color& color);
        void draw() const;
        
        void setPosition(f32 x, f32 y);
        void setRotation(f32 angle);
        void setSize(f32 width, f32 height);
    };
}