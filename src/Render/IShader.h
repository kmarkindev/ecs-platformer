#pragma once

#include <string>
#include <glm/glm.hpp>

class IShader
{
public:
    virtual void UseProgram() = 0;
    virtual void UnuseProgram() = 0;
    virtual void Uniform(std::string location, bool value) = 0;
    virtual void Uniform(std::string location, float value) = 0;
    virtual void Uniform(std::string location, int value) = 0;
    virtual void Uniform(std::string location, glm::vec2 value) = 0;
    virtual void Uniform(std::string location, glm::vec3 value) = 0;
    virtual void Uniform(std::string location, glm::vec4 value) = 0;
    virtual void Uniform(std::string location, glm::mat3 value) = 0;
    virtual void Uniform(std::string location, glm::mat4 value) = 0;
};