#include <drawable.hpp>

namespace jnx
{
    Mesh::Mesh()
    {
        this->vertices = {};
        this->indices = {};
        abo.data(vertices);
        abo.attrib(Vertex::positionLocation(), 3);
        abo.attrib(Vertex::normalLocation(), 3);
        abo.attrib(Vertex::textureLocation(), 2);
        ibo.data(indices);
    }

    Mesh::Mesh(const VertexVector& vertices, const IndexVector& indices)
    {
        this->vertices = vertices;
        this->indices = indices;
        abo.data(vertices);
        abo.attrib(Vertex::positionLocation(), 3);
        abo.attrib(Vertex::normalLocation(), 3);
        abo.attrib(Vertex::textureLocation(), 2);
        ibo.data(indices);
    }

    void Mesh::bind() const
    {
        vao.bind();
    }

    u32 Mesh::size() const
    {
        return indices.size();
    }

    void Drawable::translate(const Vec3f& position)
    {
        transform.position = position;
    }

    void Drawable::rotate(const Vec3f& rotation)
    {
        transform.rotation = rotation;
    }

    void Drawable::scale(const Vec3f& scale)
    {
        transform.scale = scale;
    }

    Sprite::Sprite(f32 width, f32 height, const Color& color): texture(1, 1, color), color(color), position(0, 0), size(width, height)
    {
        mesh = Mesh({
                        Vertex(Vec3f(-1,  1, 0), Vec3f(), Vec2f(1, 0)),
                        Vertex(Vec3f(-1, -1, 0), Vec3f(), Vec2f(1, 1)),
                        Vertex(Vec3f( 1, -1, 0), Vec3f(), Vec2f(0, 1)),
                        Vertex(Vec3f( 1,  1, 0), Vec3f(), Vec2f(0, 0)),
                    },
                    {
                        0, 1, 3, 3, 1, 2
                    });

        shader.bind();
        shader.uniform1i("tex", 0);
        shader.uniform4f("color", color.toFloat());

        setPosition(0, 0);
        setSize(width, height);
    }

    void Sprite::setTexture(const Texture& texture)
    {
        this->texture = texture;
    }

    void Sprite::draw() const
    {
        texture.bind(0);
        mesh.bind();
        gl::glDrawElements(gl::GL_TRIANGLES, mesh.size(), gl::GL_UNSIGNED_INT, nullptr);
    }
    
    void Sprite::setPosition(f32 x, f32 y)
    {
        position = Vec2f(x, y);
        translate(Vec3f(x, y, 0));
    }
    
    void Sprite::setRotation(f32 angle)
    {
        rotation = angle;
        rotate(Vec3f(0, 0, angle));
    }
    
    void Sprite::setSize(f32 width, f32 height)
    {
        size = Vec2f(width, height);
        scale(Vec3f(width, height, 1));
    }
}