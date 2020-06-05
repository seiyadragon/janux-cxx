#include <transform.hpp>

namespace jnx
{
    Mat4f Transform::getModelMatrix() const
    {
        return Mat4f::translate(position) * Mat4f::rotate(rotation) * Mat4f::scale(scale);
    }

    Mat4f OrthographicView::getViewMatrix() const
    {
        return Mat4f::orthographic(0, width, height, 0, near, far) * Mat4f::lookAt(position, position + forward, up);
    }

    Mat4f PerspectiveView::getViewMatrix() const
    {
        return Mat4f::perspective(fov, aspect, near, far) * Mat4f::lookAt(position, position + forward, up);
    }
}