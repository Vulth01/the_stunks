#pragma once
#include <glm/glm.hpp>

class CameraController
{
public:
    CameraController();
    void update();

    void setMovementSpeed(float speed);
    void setLookSensitivity(float sensitivity);
    bool getFpsCounterShow();

    int camPos;
    bool camLocked = true;
    bool fpsCounterShow = true;

private:
    float deltaTime;

    float movementSpeed = 5.0f;
    float lookSensitivity = 2.0f;

    bool mouseFirstMovement = true;

    float yaw = -90.0f;
    float pitch = 0.0f;

    glm::vec3 startPos;
    glm::vec3 startLookAt;
    glm::vec3 startUp;

    glm::vec3 position;
    glm::vec3 forward;
    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 lookAt;

    bool cursorLocked = false;

    void updateLook();
    void updatePosition();
    void updateCursorLocked();
    void updateResetCamera();
    void updateCamera();
    void updateCameraLocked(int camPos);
};