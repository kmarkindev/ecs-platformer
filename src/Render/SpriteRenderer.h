#pragma once

#include <memory>
#include "Renderer.h"
#include "Assets/Sprite.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include "VertexArray.h"
#include "Assets/OpenGlShaderLoader.h"
#include "Assets/AssetsManager.h"
#include <filesystem>
#include <utility>

/*
 TODO: Test it. Try to render smth. Try different scales, rotations, positions. Try to change texture between ticks.
 */

class SpriteRenderer
{
public:

    struct RenderParams
    {
        const Sprite& sprite;
        glm::mat4 transformMatrix;
    };

public:
    explicit SpriteRenderer(std::shared_ptr<Renderer> renderer, const std::shared_ptr<OpenGlShaderLoader>& shaderLoader,
                            const std::shared_ptr<AssetsManager>& assetsManager);
    void RenderSprite(RenderParams params);

private:
    std::shared_ptr<Renderer> _renderer;
    std::shared_ptr<Window> _window;
    std::shared_ptr<IShader> _defaultShader;

    VertexArray _spriteMesh;

    [[nodiscard]] std::shared_ptr<IShader> GetShaderForRender(const RenderParams& params) const;
    VertexArray SetupSpriteMesh();
};


