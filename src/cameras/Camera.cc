#include "Camera.hh"

namespace yarenderer {
  glm::mat4 Camera::getProjectionView() {
    if (!m_dirty) {
      _updateProjectionViewMatrix();
      m_dirty = false;
    }

    return m_projectionViewMatrix;
  }


  void Camera::setUp(glm::vec3 up)
  {
    m_dirty = true; m_up = up;
  }

  void Camera::setAt(glm::vec3 at)
  {
     m_dirty = true; m_at = at;
  }

  void Camera::setPosition(glm::vec3 position)
  {
    m_dirty = true; m_position = position;
  }
};
