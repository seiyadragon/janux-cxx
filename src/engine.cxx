#include <engine.hpp>

namespace jnx
{
    Clock::Clock()
    {
        epoch = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }

    f64 Clock::now() const
    {
        u64 t = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        
        return (f64)(t - epoch) / 1000000.0;
    }
    
    Engine::Engine(Window* window, Renderer* renderer): window(window), renderer(renderer)
    {
        
    }

    void Engine::start(f32 ticksPerSecond) 
    {
        f64 lastTime = clock.now();
        f64 lag = 0.0;
        
        i64 frames = 0;
        i64 ticks = 0;
        
        while (window->isOpen())
        {
            f64 now = clock.now();
            f64 elapsed = now - lastTime;
            lastTime = now;
            lag += elapsed;
            
            window->clear(0xff000000);
            
            if (ticks >= ticksPerSecond)
            {
                framesPerSec = frames;
                ticksPerSec = ticks;
                
                frames = 0;
                ticks = 0;
            }
            
            while(lag >= 1000.0 / ticksPerSecond)
            {
                if (manager != nullptr)
                    manager->tick(clock);
                
                tick(clock);
                ticks++;
                
                lag -= (1000.0 / ticksPerSecond);
            }
            
            if (manager != nullptr)
                manager->draw(*renderer);
            
            draw(*renderer);
            frames++;
            
            window->update();
        }
    }

    void ObjectManager::draw(const Renderer& renderer) 
    {
        for (int i = 0; i < objects.size(); i++)
            if (getObject(i) != nullptr)
                getObject(i)->draw(renderer);
    }
    
    void ObjectManager::tick(const Clock& clock) 
    {
        for (int i = 0; i < objects.size(); i++)
            if (getObject(i) != nullptr)
                getObject(i)->tick(clock);
    }
}