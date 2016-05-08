#ifndef YARENDERER__ORTHOGRAPHICCAMERA_HH
#define YARENDERER__ORTHOGRAPHICCAMERA_HH

#include "Camera.hh"

class OrthographicCamera : public Camera
{
private:
  float m_top;
  float m_right;
  float m_bottom;
  float m_left;

  float m_near;
  float m_far;
  float m_ar;

public:
  virtual void _updateProjectionViewMatrix() override;
};

#endif
