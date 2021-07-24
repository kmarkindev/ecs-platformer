#include "OpenGlShaderLoader.h"

std::shared_ptr<IShader> OpenGlShaderLoader::LoadShader(const std::vector<unsigned char>& data) const
{
    auto vertexShader = _groupedAssetsParser->ParseData(data, "VERTEX_SHADER");
    auto fragmentShader = _groupedAssetsParser->ParseData(data, "FRAGMENT_SHADER");

    auto vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    auto fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

    CompileShader(vertexShaderId, vertexShader);
    CompileShader(fragmentShaderId, fragmentShader);

    GLuint programId = glCreateProgram();

    LinkProgram(vertexShaderId, fragmentShaderId, programId);

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    return std::make_shared<OpenGlShader>(_renderer, programId);
}

OpenGlShaderLoader::OpenGlShaderLoader(std::shared_ptr<Renderer> renderer,
                                       std::shared_ptr<GroupedAssetsParser> groupedAssetsParser)
    : _renderer(std::move(renderer)),
      _groupedAssetsParser(std::move(groupedAssetsParser))
{
}

void OpenGlShaderLoader::CompileShader(GLuint shaderId, const std::vector<unsigned char>& data) const
{
    int success;
    constexpr int INFO_LOG_SIZE = 512;
    char infoLog[INFO_LOG_SIZE];

    auto str = std::string(data.begin(), data.end());
    auto rawStr = str.c_str();

    glShaderSource(shaderId, 1, &rawStr, nullptr);

    glCompileShader(shaderId);

    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shaderId, INFO_LOG_SIZE, nullptr, infoLog);
        throw std::runtime_error(std::string("Cannot compile shader: " + std::string(infoLog)));
    }
}

void OpenGlShaderLoader::LinkProgram(GLuint vertexShaderId, GLuint fragmentShaderId, GLuint programId) const
{
    int success;
    constexpr int INFO_LOG_SIZE = 512;
    char infoLog[INFO_LOG_SIZE];

    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);

    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(programId, INFO_LOG_SIZE, nullptr, infoLog);
        throw std::runtime_error(std::string("Cannot link shader program: " + std::string(infoLog)));
    }
}
