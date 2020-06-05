#include <matrix.hpp>

namespace jnx
{
    Mat4f Mat4f::identity()
    {
        return glm::identity<glm::mat4>();
    }

    Mat4f Mat4f::orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far)
    {
        return glm::ortho(left, right, bottom, top, near, far);
    }

    Mat4f Mat4f::perspective(f32 fov, f32 aspect, f32 near, f32 far)
    {
        return glm::perspective(fov, aspect, near, far);
    }

    Mat4f Mat4f::lookAt(const Vec3f& position, const Vec3f& forward, const Vec3f& up)
    {
        return glm::lookAt(position, forward, up);
    }

    Mat4f Mat4f::translate(const Vec3f& position)
    {
        return glm::translate(glm::mat4(1), position);
    }

    Mat4f Mat4f::rotate(const Vec3f& rotation)
    {
        Mat4f rotX = glm::rotate(glm::mat4(1), rotation.x, Vec3f(1, 0, 0));
        Mat4f rotY = glm::rotate(glm::mat4(1), rotation.y, Vec3f(0, 1, 0));
        Mat4f rotZ = glm::rotate(glm::mat4(1), rotation.z, Vec3f(0, 0, 1));

        return rotZ * rotY * rotX;
    }

    Mat4f Mat4f::scale(const Vec3f& scale)
    {
        return glm::scale(glm::mat4(1), scale);
    }
}