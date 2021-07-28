#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

glm::mat4 GetModelMatrix(glm::vec2 position, glm::vec2 scale, glm::quat rotation);

glm::mat4 GetOthroProjectionMatrix(glm::ivec2 viewportSize, float zoom);

glm::mat4 GetCameraMatrix(glm::vec2 cameraPos);