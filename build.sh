#!/bin/bash

set -xe

cc=gcc
flags="-Wall -Wextra"

$cc main.c -o collatz $flags
