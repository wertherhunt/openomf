#!/bin/sh

sudo apt-get --force-yes install libopenal-dev libglew-dev libsdl2-static-dev libconfuse-dev libenet-dev libogg-dev libvorbis-dev

# remove the 2 lines below if travis updates sdl to 2.0.1+
wget http://libsdl.org/release/SDL2-2.0.1.tar.gz -O - | tar xz
(cd SDL2-2.0.1 && ./configure --prefix=$PREFIX && make -j5 && make install)
  
cd travis/
git clone --depth=1 https://github.com/omf2097/libShadowDive.git
git clone --depth=1 https://bitbucket.org/kode54/dumb.git

cd libShadowDive
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
make install

cd ../../dumb
mkdir dumb/cmake/build/
cd dumb/cmake/build/
cmake -DCMAKE_BUILD_TYPE=Release ..
make
make install




