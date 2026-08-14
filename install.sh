#!/bin/bash

set -e

echo "building cpbox..."

g++ src/main.cpp src/session.cpp -o cpbox

echo "installing cpbox..."

sudo mkdir -p /usr/local/share/cpbox
sudo mv cpbox /usr/local/bin/cpbox
sudo cp -R nvim /usr/local/share/cpbox/
sudo cp -R wezterm /usr/local/share/cpbox/

echo "cpbox installed successfully!"
echo "run: cpbox <filename> <time>"
