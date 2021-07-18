#pragma once

template<typename T>
class Singleton
{
protected:
    Singleton() = default;
public:
    static T* GetInstance()
    {
        static T instance = T();
        return &instance;
    }
};


