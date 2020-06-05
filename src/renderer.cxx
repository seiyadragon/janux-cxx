#include <renderer.hpp>

namespace jnx
{

    Renderer::Renderer(const Vec3f& position, const Vec2f& size): view(position, Vec3f(0, 0, 1), Vec3f(0, 1, 0), size.x, size.y, -1.0f, 1.0f)
    {

    }

    void Renderer::draw(const Drawable& drawable) const
    {
        drawable.shader.bind();
        drawable.shader.uniformMat4f("matrix", view.getViewMatrix() * drawable.transform.getModelMatrix());
        drawable.draw();
    }
}