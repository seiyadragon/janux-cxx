#pragma once
#include <core.hpp>
#include <drawable.hpp>

namespace jnx
{
    struct Renderer
    {
        OrthographicView view;

        Renderer(const Vec3f& position, const Vec2f& size);
        void draw(const Drawable& drawable) const;
    };
}