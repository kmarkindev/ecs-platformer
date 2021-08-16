/*
    Need to register all possible events here
    They should be wrapped in std::function<void(EventTypeHere&)>
*/

#include "CollisionEnter.h"
#include "CollisionExit.h"

typedef std::variant<

    std::function<void(CollisionEnter&)>,
    std::function<void(CollisionExit&)>

> EventVariant;