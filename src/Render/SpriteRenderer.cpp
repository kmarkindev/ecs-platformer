#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(std::shared_ptr<Renderer> renderer, const std::shared_ptr<OpenGlShaderLoader>& shaderLoader,
                               const std::shared_ptr<AssetsManager>& assetsManager)
    : _renderer(std::move(renderer)),
    _spriteMesh(SetupSpriteMesh()),
    _defaultShader(
            shaderLoader->LoadShader(
                    assetsManager->GetAssetData(
                            std::filesystem::path("shaders") / "default_sprite_shader.shader"
                    )
            )
    )
{

}

void SpriteRenderer::RenderSprite(SpriteRenderer::RenderParams params)
{
    std::shared_ptr<IShader> shader = GetShaderForRender(params);
    auto* texture = params.sprite.GetTexture();

    shader->UseProgram();
    texture->Bind(0);

    glm::mat4 transform = glm::mat4(1.0f);

    transform = glm::scale(transform, {params.sprite.GetSize().x, params.sprite.GetSize().y, 1});
    transform = glm::translate(transform, {params.sprite.GetOffset().x, params.sprite.GetOffset().y, 0});

    transform = params.transformMatrix * transform;

    shader->Uniform("u_transform", transform);
    shader->Uniform("u_texture", 0);

    _renderer->DrawArrays(_spriteMesh);

    texture->Unbind();
    shader->UnuseProgram();
}

std::shared_ptr<IShader> SpriteRenderer::GetShaderForRender(const SpriteRenderer::RenderParams& params) const
{
    auto shader = params.sprite.GetShader();

    if(shader == nullptr)
        return _defaultShader;

    return shader;
}

VertexArray SpriteRenderer::SetupSpriteMesh()
{
    std::vector<float> meshData = {
         /* Verts          UV  */
         0.5,  0.5,     1.0, 1.0,
        -0.5,  0.5,     0.0, 1.0,
        -0.5, -0.5,     0.0, 0.0,

         0.5,  0.5,     1.0, 1.0,
        -0.5, -0.5,     0.0, 0.0,
         0.5, -0.5,     1.0, 0.0
    };

    std::vector<VertexBuffer::BufferParam> params = {
        {
            .size = 2,
            .normalized = false,
            .stride = 4,
            .offset = 0
        },
        {
            .size = 2,
            .normalized = false,
            .stride = 4,
            .offset = 2
        }
    };

    auto spriteMeshBuffer = VertexBuffer(_renderer, meshData, params);
    auto spriteMeshArray = VertexArray(_renderer, spriteMeshBuffer);

    return spriteMeshArray;
}