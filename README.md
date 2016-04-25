# RabbitHole
multi platform GameEngine  using C++ emscripten OpenGLES 

#dependency
emscripten
llvm
clang
boost 1.53 later
cmake
OpenGL
glfw




#build

$ cd rabbit

##native build
$ make clean
$ cmake .
$ make

##javascript lib
$ make clean
$ cmake -DEMSCRIPTEN=1
$ make