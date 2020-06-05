#include <vector.hpp>

namespace jnx
{
    Vec2f Vec2f::normalize()
    {
        return glm::normalize(*this);
    }

    f32 Vec2f::dot(const Vec2f& other)
    {
        return glm::dot(*this, *(glm::vec2*)&other);
    }

    Vec3f Vec3f::normalize()
    {
        return glm::normalize(*this);
    }

    Vec3f Vec3f::cross(const Vec3f& other)
    {
        return glm::cross(*this, other);
    }

    f32 Vec3f::dot(const Vec3f& other)
    {
        return glm::dot(*this, *(glm::vec3*)&other);
    }

    Vec4f Vec4f::normalize()
    {
        return glm::normalize(*this);
    }

    f32 Vec4f::dot(const Vec4f& other)
    {
        return glm::dot(*this, *(glm::vec4*)&other);
    }
}