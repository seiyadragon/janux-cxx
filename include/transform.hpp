#pragma once
#include <core.hpp>
#include <vector.hpp>
#include <matrix.hpp>

namespace jnx
{
    struct Transform
    {
        Vec3f position;
        Vec3f rotation;
        Vec3f scale;

        Transform(const Vec3f& position = Vec3f(), const Vec3f rotation = Vec3f(), const Vec3f& scale = Vec3f(1, 1, 1)): position(position), rotation(rotation), scale(scale) {}

        Mat4f getModelMatrix() const;
    };

    struct View
    {
        Vec3f position;
        Vec3f forward;
        Vec3f up;

        View(const Vec3f& position, const Vec3f& forward, const Vec3f& up): position(position), forward(forward), up(up) {}
    };

    struct OrthographicView: public View
    {
        f32 width;
        f32 height;
        f32 near;
        f32 far;

        OrthographicView(const Vec3f& position, const Vec3f& forward, const Vec3f& up, f32 width, f32 height, f32 near, f32 far):
         View(position, forward, up), width(width), height(height), near(near), far(far) {}

        Mat4f getViewMatrix() const;
    };

    struct PerspectiveView: public View
    {
        f32 aspect;
        f32 near;
        f32 far;
        f32 fov;

        PerspectiveView(const Vec3f& position, const Vec3f& forward, const Vec3f& up, f32 aspect, f32 near, f32 far, f32 fov):
         View(position, forward, up), aspect(aspect), near(near), far(far), fov(fov) {}

        Mat4f getViewMatrix() const;
    };
}