//
// Created by mew on 07/09/22.
//

#include "camera.hpp"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "imgui.h"

namespace lens
{

glm::mat4 Camera::m_camera;
glm::vec2 Camera::m_pos;
float Camera::m_rotation;
float Camera::m_zoom;
glm::vec2 Camera::m_origin;


void Camera::Initialize(float originX, float originY, bool resetCameraMatrix)
{
    m_origin = glm::vec2(originX, originY);
    if (resetCameraMatrix)
        m_camera = glm::mat4(1.0f);
    m_pos = glm::vec2(0.0f, 0.0f);
    m_rotation = 0.0f;
    m_zoom = 1.0f;
}

void Camera::UpdateCameraMatrix()
{
    m_camera = glm::ortho(-m_origin.x, m_origin.x, -m_origin.y, m_origin.y, -1.0f, 1.0f);
    m_camera = glm::translate(m_camera, glm::vec3(m_pos, 0.0f));
    m_camera = glm::rotate(m_camera, -m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    m_camera = glm::scale(m_camera, glm::vec3(m_zoom, m_zoom, 1.0f));
}

void Camera::CameraImGui()
{
    ImGui::Begin("Camera");
    ImGui::Text("This window controls the camera in 2D space.");
    ImGui::DragFloat2("Camera Position", glm::value_ptr(m_pos));
    ImGui::SliderAngle("Camera Rotation", &m_rotation, -360.0f, 360.0f, "%.1f deg");
    ImGui::DragFloat("Camera Zoom", &m_zoom, 0.01f);
    if (ImGui::Button("Reset Settings"))
        Initialize(m_origin.x, m_origin.y, false);
    ImGui::End();
}

}
