#include "OSContext.hh"

namespace yarenderer
{

namespace utils
{
OSContext::OSContext(GLsizei w, GLsizei h) : width(w), height(h)
{
  context = OSMesaCreateContextExt(OSMESA_RGBA, 16, 0, 0, NULL);
  ASSERT(context, "Couldn't create offscreen context.");
}

OSContext::~OSContext() { OSMesaDestroyContext(context); }

void OSContext::make_current()
{
  ASSERT(OSMesaMakeCurrent(context, &buffer, GL_UNSIGNED_BYTE, width, height),
         "Couldn't make current offscreen context.");
}

} // ns utils

} // ns yarenderer
