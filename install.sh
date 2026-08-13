#!/bin/bash

set -e

echo "building cpbox..."

g++ src/main.cpp src/session.cpp -o cpbox

echo "installing cpbox..."

sudo mv cpbox /usr/local/bin/cpbox

echo "cpbox installed successfully!"
echo "run: cpbox <filename> <time>"
