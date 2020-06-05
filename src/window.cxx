#include <window.hpp>

namespace jnx
{
    namespace gl46core = gl;

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void window_close_callback(GLFWwindow* window);
    void window_resize_callback(GLFWwindow* window, int width, int height);

    Window::Window(u32 width, u32 height, const str& title)
    {
        if (!glfwInit())
            jnx_print("GLFW was too gay to start!");

        _window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if (_window == nullptr)
            jnx_print("Window be null mon!");

        for (i32 i = 0; i < 255; i++)
        {
            keys[i] = false;

            if (i < 20)
                buttons[i] = false;
        }

        glfwMakeContextCurrent(_window);
        glfwSetWindowUserPointer(_window, this);
        glfwSetKeyCallback(_window, key_callback);
        glfwSetCursorPosCallback(_window, cursor_position_callback);
        glfwSetMouseButtonCallback(_window, mouse_button_callback);
        glfwSetWindowCloseCallback(_window, window_close_callback);
        glfwSetWindowSizeCallback(_window, window_resize_callback);
        glbinding::initialize(glfwGetProcAddress);
        ilInit();
    }

    void Window::resize(u32 width, u32 height) const
    {
        glfwSetWindowSize(_window, width, height);
    }

    void Window::move(u32 x, u32 y) const
    {
        glfwSetWindowPos(_window, x, y);
    }

    void Window::fullscreen(bool fullscreen) const
    {
        GLFWmonitor* monitor = nullptr;
        auto video = glfwGetVideoMode(monitor);

        if (fullscreen)
            monitor = glfwGetPrimaryMonitor();

        glfwSetWindowMonitor(_window, monitor, 0, 0, video->width, video->height, 60);            
    }

    void Window::update() const
    {
        glfwPollEvents();
        glfwSwapBuffers(_window);
    }

    void Window::clear(const Color& color) const
    {
        gl::glClearColor(color.toFloat().x, color.toFloat().y, color.toFloat().z, color.toFloat().w);
        gl::glClear((gl::ClearBufferMask)(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT));
    }

    void Window::close() const
    {
        glfwSetWindowShouldClose(_window, true);
    }

    bool Window::isOpen() const
    {
        return !glfwWindowShouldClose(_window);
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        auto win = (Window*)glfwGetWindowUserPointer(window);

        if (action == GLFW_PRESS)
            win->keys[key] = true;
        else if (action == GLFW_RELEASE)
            win->keys[key] = false;
    }

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
        auto win = (Window*)glfwGetWindowUserPointer(window);

        win->cursorPos = Vec2f(xpos, ypos);
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
    {
        auto win = (Window*)glfwGetWindowUserPointer(window);

        if (action == GLFW_PRESS)
            win->buttons[button] = true;
        else if (action == GLFW_RELEASE)
            win->buttons[button] = false;
    }

    void window_close_callback(GLFWwindow* window)
    {
        glfwSetWindowShouldClose(window, true);
    }

    void window_resize_callback(GLFWwindow* window, int width, int height)
    {
        gl::glViewport(0, 0, width, height);
    }
}