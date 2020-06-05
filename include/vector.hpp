#pragma once
#include <core.hpp>
#include <glm/glm.hpp>

namespace jnx
{
    struct Vec2f: public glm::vec2
    {
        Vec2f(f32 x = 0, f32 y = 0): glm::vec2(x, y) {}
        Vec2f(const glm::vec2& vector): glm::vec2(vector) {}

        Vec2f normalize();
        f32 dot(const Vec2f& other);
    };

    struct Vec3f: public glm::vec3
    {
        Vec3f(f32 x = 0, f32 y = 0, f32 z = 0): glm::vec3(x, y, z) {}
        Vec3f(const glm::vec3& vector): glm::vec3(vector) {}

        Vec3f normalize();
        Vec3f cross(const Vec3f& other);
        f32 dot(const Vec3f& other);
    };

    struct Vec4f: public glm::vec4
    {
        Vec4f(f32 x = 0, f32 y = 0, f32 z = 0, f32 w = 0): glm::vec4(x, y, z, w) {}
        Vec4f(const glm::vec4& vector): glm::vec4(vector) {}

        Vec4f normalize();
        f32 dot(const Vec4f& other);
    };

    struct Vec2i: public glm::ivec2
    {
        Vec2i(i32 x = 0, i32 y = 0): glm::ivec2(x, y) {}
        Vec2i(const glm::ivec2& vector): glm::ivec2(vector) {}
    };

    struct Vec3i: public glm::ivec3
    {
        Vec3i(i32 x = 0, i32 y = 0, i32 z = 0): glm::ivec3(x, y, z) {}
        Vec3i(const glm::ivec3& vector): glm::ivec3(vector) {}
    };

    struct Vec4i: public glm::ivec4
    {
        Vec4i(i32 x = 0, i32 y = 0, i32 z = 0, i32 w = 0): glm::ivec4(x, y, z, w) {}
        Vec4i(const glm::ivec4& vector): glm::ivec4(vector) {}
    };
}