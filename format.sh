#!/bin/bash

find . -name "*.cc" -o -name "*.hh" -print0 | xargs -0 clang-format -i
