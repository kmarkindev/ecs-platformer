#include "Entity.h"

Entity::Entity(entt::entity entity, entt::registry* registry)
    : _entity(entity),
    _registry(registry)
{

}

void Entity::Delete()
{
    _registry->destroy(_entity);
    _entity = entt::null;
}

bool Entity::IsValid() const
{
    return _registry->valid(_entity);
}
