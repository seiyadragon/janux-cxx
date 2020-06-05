#pragma once
#include <core.hpp>
#include <window.hpp>
#include <renderer.hpp>
#include <chrono>

namespace jnx
{
    struct Clock
    {
    private:
        u64 epoch = 0;
    
    public:
        Clock();
        f64 now() const;
    };
    
    struct ObjectManager;
    
    struct Engine
    {
    protected:
        Window* window = nullptr;
        Renderer* renderer = nullptr;
        ObjectManager* manager = nullptr;
        Clock clock;
        
    public:
        f32 ticksPerSec;
        f32 framesPerSec;
        
    public:
        Engine(Window* window, Renderer* renderer);
        
        void start(f32 ticksPerSecond);
        
        virtual void draw(const Renderer& renderer) = 0;
        virtual void tick(const Clock& clock) = 0;
    };
    
    struct Object
    {
        virtual void draw(const Renderer& render) = 0;
        virtual void tick(const Clock& clock) = 0;
    };
    
    struct ObjectManager: public Object
    {
    private:
        std::vector<Object*> objects;
        
    public:
        ObjectManager(u32 size): objects(size) {}
        
        void addObject(Object* object) { objects.push_back(object); }
        void remObject(u32 index) { objects.erase(objects.begin() + index); }
        Object* getObject(u32 index) { return objects[index]; }
        
        void draw(const Renderer& renderer);
        void tick(const Clock& clock);
    };
}