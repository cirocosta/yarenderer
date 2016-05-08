#ifndef YARENDERER__CAMERA_HH
#define YARENDERER__CAMERA_HH

#include "glm/gtc/type_ptr.hpp"

namespace yarenderer
{

class Camera
{
protected:
  bool m_dirty;

  glm::vec3 m_at;
  glm::vec3 m_up;
  glm::vec3 m_position;

  glm::mat4 m_view = glm::mat4();
  glm::mat4 m_projection = glm::mat4();
  glm::mat4 m_projectionViewMatrix = glm::mat4();

  virtual void _updateProjectionViewMatrix() = 0;

public:
  void setUp(glm::vec3);
  void setAt(glm::vec3);
  void setPosition(glm::vec3);

  glm::vec3 getUp()
  {
    return m_up;
  }
  glm::vec3 getAt()
  {
    return m_at;
  }
  glm::vec3 getPosition()
  {
    return m_position;
  }
  glm::mat4 getProjectionView();
};
}

#endif
