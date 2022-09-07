//
// Created by mew on 07/09/22.
//

#ifndef LENS_CAMERA_HPP
#define LENS_CAMERA_HPP


#include "glm/glm.hpp"

namespace lens
{

class Camera
{
public:
    static void Initialize(float originX, float originY, bool resetCameraMatrix = true);

    static glm::mat4 GetCameraMatrix() { return m_camera; }
    static void UpdateCameraMatrix();
    static void CameraImGui();

    static void Zoom(float zoom)
    {
        if (m_zoom * zoom >= 0.0f)
            m_zoom *= zoom;
    }

    static void SetZoom(float zoom)
    {
        if (zoom >= 0.0f)
            m_zoom = zoom;
    }

    static void Rotate(float rotation)
    {
        m_rotation += rotation;
    }

    static void SetRotation(float rotation)
    {
        m_rotation = rotation;
    }

    static void Move(float x, float y)
    {
        m_pos.x += x;
        m_pos.y += y;
    }

    static void SetPosition(float x, float y)
    {
        m_pos.x = x;
        m_pos.y = y;
    }

private:
    static glm::mat4 m_camera;
    static glm::vec2 m_pos;
    static float m_rotation;
    static float m_zoom;
    static glm::vec2 m_origin;
};

}


#endif //LENS_CAMERA_HPP
