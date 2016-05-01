# yarenderer

> **Y**et **A**nother **renderer**

  ```bash
  $ git clone git@github.com:cirocosta/yarenderer.git     # clone repo
  $ git submodule update --init --recursive               # fetch dependencies
  ```

## Running

Initialize `build` directory:

  ```bash
  $ ./run init
  ```

Run the test:

  ```bash
  $ ./run run test_window
  ```

### Dependencies

#### Mac OSX

If you have `cmake`, `clang-format` and `xcode-cli` properly installed, you're ready to run.

#### Debian Based

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

