#pragma once
#include <core.hpp>
#include <vector.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace jnx
{
    struct Mat4f: public glm::mat4
    {
        Mat4f(f32 d = 1): glm::mat4(d) {}
        Mat4f(const glm::mat4& matrix): glm::mat4(matrix) {}

        static Mat4f identity();
        static Mat4f orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far);
        static Mat4f perspective(f32 fov, f32 aspect, f32 near, f32 far);
        static Mat4f lookAt(const Vec3f& position, const Vec3f& forward, const Vec3f& up);
        static Mat4f translate(const Vec3f& position);
        static Mat4f rotate(const Vec3f& rotation);
        static Mat4f scale(const Vec3f& scale);
    };
}