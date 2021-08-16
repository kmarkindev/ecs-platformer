#pragma once

#include <typeinfo>
#include <functional>
#include <variant>
#include <list>
#include "Events/EventVariant.h"

class EventListener
{
public:

    template<typename Event, typename... Args>
    void RaiseEvent(Args&&... args)
    {
        auto event = Event(std::forward<Args>(args)...);

        for(auto& variant : _subscribers)
        {
            auto callback = std::get_if<std::function<void(Event&)>>(&variant);

            if(callback)
                (*callback)(event);
        }

    }

    template<typename Event>
    void Subscribe(std::function<void(Event&)> callback)
    {
        _subscribers.push_front(callback);
    }

private:

    std::list<EventVariant> _subscribers;

};


