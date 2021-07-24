#pragma once

#include <memory>
#include <glad/glad.h>
#include <string>
#include <stdexcept>
#include "Render/Renderer.h"
#include "Render/OpenGlShader.h"
#include "Render/IShader.h"
#include "GroupedAssetsParser.h"

class OpenGlShaderLoader
{
public:
    explicit OpenGlShaderLoader(std::shared_ptr<Renderer> renderer,
                                std::shared_ptr<GroupedAssetsParser> groupedAssetsParser);

    [[nodiscard]] std::shared_ptr<IShader> LoadShader(const std::vector<unsigned char>& data) const;

private:
    std::shared_ptr<Renderer> _renderer;
    std::shared_ptr<GroupedAssetsParser> _groupedAssetsParser;

    void CompileShader(GLuint shaderId, const std::vector<unsigned char>& data) const;
    void LinkProgram(GLuint vertexShader, GLuint fragmentShader, GLuint programId) const;
};


