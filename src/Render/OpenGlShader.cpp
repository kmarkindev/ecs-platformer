#include "OpenGlShader.h"

void OpenGlShader::UseProgram()
{
    glUseProgram(_program);
}

void OpenGlShader::Uniform(std::string location, bool value)
{
    UseProgram();
    GLint loc = GetUniformLocation(location);
    glUniform1i(loc, value);
}

void OpenGlShader::Uniform(std::string location, float value)
{
    UseProgram();
    GLint loc = GetUniformLocation(location);
    glUniform1f(loc, value);
}

void OpenGlShader::Uniform(std::string location, int value)
{
    UseProgram();
    GLint loc = GetUniformLocation(location);
    glUniform1i(loc, value);
}

void OpenGlShader::Uniform(std::string location, glm::vec2 value)
{
    UseProgram();
    GLint loc = GetUniformLocation(location);
    glUniform2fv(loc, 1, &value[0]);
}

void OpenGlShader::Uniform(std::string location, glm::vec3 value)
{
    UseProgram();
    GLint loc = GetUniformLocation(location);
    glUniform3fv(loc, 1, &value[0]);
}

void OpenGlShader::Uniform(std::string location, glm::vec4 value)
{
    UseProgram();
    GLint loc = GetUniformLocation(location);
    glUniform4fv(loc, 1, &value[0]);
}

void OpenGlShader::Uniform(std::string location, glm::mat3 value)
{
    UseProgram();
    GLint loc = GetUniformLocation(location);
    glUniformMatrix3fv(loc, 1, GL_FALSE, &value[0][0]);
}

void OpenGlShader::Uniform(std::string location, glm::mat4 value)
{
    UseProgram();
    GLint loc = GetUniformLocation(location);
    glUniformMatrix4fv(loc, 1, GL_FALSE, &value[0][0]);
}

GLint OpenGlShader::GetUniformLocation(const std::string& location) const
{
    return glGetUniformLocation(_program, location.c_str());
}

OpenGlShader::~OpenGlShader()
{
    if(_program != 0)
        glDeleteProgram(_program);
}

OpenGlShader::OpenGlShader(std::shared_ptr<Renderer> renderer, GLuint program)
    : _program(program),
    _renderer(std::move(renderer))
{

}

void OpenGlShader::UnuseProgram()
{
    glUseProgram(0);
}
