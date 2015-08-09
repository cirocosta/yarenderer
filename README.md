# yarenderer

> **Y**et **A**nother **renderer**

## Install

```sh
# fetch dependencies as well
$ git submodule update --init --recursive --depth=10

# generate build files
$ mkdir build
$ cd build
$ cmake -Dtest=ON -DCMAKE_BUILD_TYPE=Debug ..

# build
# -jN where N = #cores so that we build in parallel
$ make -j5 
$ ./src/main

# :D
```

### Dependencies

The project builds almost everything. You'll only need an OpenGL implementation (like [mesa](http://www.mesa3d.org/)) and, if you wish to include tests, an offscreen opengl implementation is required (`osmesa`). Both of them are easily installed from `apt`:

```sh
# apt-get install mesa-common-dev libglu1-mesa-dev libosmesa6 libosmesa6-dev
```

Ubuntu 14.04.3 has a problem with the apt version of libosmesa6. If you encounter any problems, build it directly from source:

```sh
 # based on http://wiki.octave.org/OSMesa#Build_libOSMesa_from_source

 wget -nc ftp://ftp.freedesktop.org/pub/mesa/current/mesa-10.5.4.tar.xz
 tar -xf mesa-10.5.4.tar.xz
 cd mesa-10.5.4/
 
 autoreconf -fi
 
 ./configure \
   CXXFLAGS="-O2 -g -DDEFAULT_SOFTWARE_DEPTH_BITS=31" \
   CFLAGS="-O2 -g -DDEFAULT_SOFTWARE_DEPTH_BITS=31" \
   --disable-xvmc \
   --disable-glx \
   --disable-dri \
   --with-dri-drivers="" \
   --with-gallium-drivers="" \
   --disable-shared-glapi \
   --disable-egl \
   --with-egl-platforms="" \
   --enable-osmesa \
   --enable-gallium-llvm=no
 make -j
```

Set the env variable `MESA_DIR` in your shell rc and you're ready to go.

## LICENSE

GPLv2.

See `./LICENSE`.

