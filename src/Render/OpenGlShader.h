#pragma once

#include "IShader.h"
#include "Renderer.h"
#include <glad/glad.h>

class OpenGlShader : public IShader
{
public:
    explicit OpenGlShader(std::shared_ptr<Renderer> renderer, GLuint program);
    ~OpenGlShader();

    OpenGlShader(const OpenGlShader&) = delete;
    OpenGlShader& operator = (const OpenGlShader&) = delete;

    void UseProgram() override;
    void UnuseProgram() override;
    void Uniform(std::string location, bool value) override;
    void Uniform(std::string location, float value) override;
    void Uniform(std::string location, int value) override;
    void Uniform(std::string location, glm::vec2 value) override;
    void Uniform(std::string location, glm::vec3 value) override;
    void Uniform(std::string location, glm::vec4 value) override;
    void Uniform(std::string location, glm::mat3 value) override;
    void Uniform(std::string location, glm::mat4 value) override;

private:
    GLuint _program;
    std::shared_ptr<Renderer> _renderer;

    [[nodiscard]] GLint GetUniformLocation(const std::string& location) const;
};


