#pragma once
#include <core.hpp>
#include <glbinding/glbinding.h>
#include <glbinding/gl46core/gl.h>
#include <GLFW/glfw3.h>
#include <IL/il.h>
#include <texture.hpp>

namespace jnx
{
    struct Window
    {
    private:
        GLFWwindow* _window = nullptr;

    public:
        bool keys[255];
        bool buttons[20];

        Vec2f cursorPos = Vec2f(0, 0);

    public:
        Window(u32 width, u32 height, const str& title);

        void resize(u32 width, u32 height) const;
        void move(u32 x, u32 y) const;
        void fullscreen(bool fullscreen) const;
        void update() const;
        void clear(const Color& color) const;
        void close() const;

        bool isOpen() const;
    };
}