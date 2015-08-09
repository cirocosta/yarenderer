#include "OSContext.hh"
#include <iostream>

using namespace yarenderer;
using yarenderer::utils::OSContext;

int main(int argc, char *argv[])
{
  OSContext ctx (400, 400);
  ctx.make_current();

  return 0;
}
