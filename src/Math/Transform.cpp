#include "Transform.h"

glm::mat4 GetModelMatrix(glm::vec2 position, glm::vec2 scale, float angle)
{
    auto res = glm::mat4(1.0f);

    res = glm::translate(res, {position.x, position.y, 0});
    res = glm::rotate(res, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
    res = glm::scale(res, {scale.x, scale.y, 0});

    return res;
}

glm::mat4 GetOthroProjectionMatrix(glm::ivec2 viewportSize, float zoom)
{
    float xScale = 1.0f;
    float yScale = 1.0f;

    if(viewportSize.x > viewportSize.y)
        xScale = viewportSize.x / (float)viewportSize.y;
    else
        yScale = viewportSize.y / (float)viewportSize.x;

    float xSide = (zoom * xScale) / 2;
    float ySide = (zoom * yScale) / 2;

    return glm::ortho(-xSide, xSide, -ySide, ySide);
}

glm::mat4 GetCameraMatrix(glm::vec2 cameraPos, float angle)
{
    auto res = glm::mat4(1.0f);
    res = glm::translate(res, {-cameraPos.x, -cameraPos.y, 0});
    res = glm::rotate(res, glm::radians(-angle), glm::vec3(0.0f, 0.0f, 1.0f));
    return res;
}