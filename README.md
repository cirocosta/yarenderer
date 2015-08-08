# yabrowser

> **Y**et **A**nother **browser**

## Install

```sh
# fetch dependencies as well
$ git submodule update --init --recursive

# generate build files
$ mkdir build
$ cd build
$ cmake -Dtest=ON -DCMAKE_BUILD_TYPE=Debug ..

# build
# -jN where N = #cores so that we build in parallel
$ make -j5 && make test
$ ./src/yabrowser

# :DD
```

## LICENSE

GPLv2.

See `./LICENSE`.

