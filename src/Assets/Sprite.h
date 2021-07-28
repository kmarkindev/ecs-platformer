#pragma once

#include <memory>
#include <glm/glm.hpp>
#include "Texture.h"
#include "Render/IShader.h"

class Sprite
{
public:
    explicit Sprite(Texture* texture);

    [[nodiscard]] const glm::vec2& GetSize() const;
    void SetSize(const glm::vec2& size);
    [[nodiscard]] Texture* GetTexture() const;
    void SetTexture(Texture* texture);
    [[nodiscard]] const glm::vec2& GetOffset() const;
    void SetOffset(const glm::vec2& offset);
    [[nodiscard]] const std::shared_ptr<IShader>& GetShader() const;
    void SetShader(const std::shared_ptr<IShader>& shader);

    Sprite(const Sprite&) = default;
    Sprite(Sprite&&) = default;

private:
    Texture* _texture;
    glm::vec2 _size;
    glm::vec2 _offset;
    std::shared_ptr<IShader> _shader;
};


