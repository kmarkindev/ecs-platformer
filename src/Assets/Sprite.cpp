#include "Sprite.h"

Sprite::Sprite(Texture&& texture)
    : _texture(std::forward<Texture>(texture))
{

}
