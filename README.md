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

## LICENSE

GPLv2.

See `./LICENSE`.

