//http://blog.wonderrabbitproject.net/2014/04/glfw3glfw2emscripten-114glfw.html


#include <stdexcept>
#include <boost/scope_exit.hpp>
#include <iostream>

#include "render.h"

#ifdef EMSCRIPTEN
  #include <GL/glfw.h>
  #include <emscripten/emscripten.h>
#else
  #include <GLFW/glfw3.h>
#endif

namespace
{
  struct glfw_runtime_error: std::runtime_error
  {
    glfw_runtime_error(const std::string& what)
      : std::runtime_error(what)
    { }
  };
#if GLFW_VERSION_MAJOR < 3
  bool main_loop_is_continuous = true;
#endif
}

auto main() -> int
{
  {
    const auto r = glfwInit();
    if ( not r )
      throw glfw_runtime_error( std::string("glfwInit failed. return value: ") + std::to_string(r) );
  }
  
  BOOST_SCOPE_EXIT_ALL(){ glfwTerminate(); };

#if GLFW_VERSION_MAJOR >= 3
  glfwSetErrorCallback
  ( [](int error, const char* description)
    { throw glfw_runtime_error
      ( std::string("glfw error: error = ") + std::to_string(error) 
      + std::string(" , description = ") + std::string(description)
      );
    }
  );
#endif
  
#if GLFW_VERSION_MAJOR >= 3
  // GLFW3 receive a window
  const auto window =
#endif
  []
  {
    // GLFW3 & GLFW2 common params
    constexpr int window_width_in_px   = 320;
    constexpr int window_height_in_px  = 240;
#if GLFW_VERSION_MAJOR >= 3
    // GLFW3 params
    constexpr const char* window_title = "glfw";
    GLFWmonitor* window_monitor = nullptr;
    GLFWwindow*  window_window  = nullptr;
#else
    // GLFW2 params
    constexpr int red_bits    = 8;
    constexpr int green_bits  = 8;
    constexpr int blue_bits   = 8;
    constexpr int alpha_bits  = 8;
    constexpr int depth_bits  = 8;
    constexpr int stencilbits = 8;
    constexpr int mode = GLFW_WINDOW;
#endif
    // generate a window
    const auto result
#if GLFW_VERSION_MAJOR >= 3
      = glfwCreateWindow
        ( window_width_in_px, window_height_in_px
        , window_title, window_monitor, window_window
        );
#else
      = glfwOpenWindow
        ( window_width_in_px, window_height_in_px
        , red_bits, green_bits, blue_bits
        , alpha_bits
        , depth_bits
        , stencilbits
        , mode
        );
#endif
    // check result
    // GLFW3: error if result == nullptr
    // GLFW2: error if result == GL_FALSE
    if ( not result )
      // throw error
      throw glfw_runtime_error
      ( "glfw"
#if GLFW_VERSION_MAJOR >= 3
        "CreateWindow"
#else
        "OpenWindow"
#endif
        " failed. window is nullptr."
      );
    
#if GLFW_VERSION_MAJOR >= 3
    // GLFW3: GLFWwindow*
    return result;
#endif
  }();
  
#if GLFW_VERSION_MAJOR >= 3
  BOOST_SCOPE_EXIT_ALL( window ){ glfwDestroyWindow( window ); };
#else
  BOOST_SCOPE_EXIT_ALL( ){ glfwCloseWindow( ); };
#endif
  
#if GLFW_VERSION_MAJOR >= 3
  glfwMakeContextCurrent( window );
#endif
  
  glfwSetKeyCallback
  (
#if GLFW_VERSION_MAJOR >= 3
    window,
#endif
    []
    (
#if GLFW_VERSION_MAJOR >= 3
      GLFWwindow* window, int key, int scancode, int action, int mods
#else
                          int key,               int action
#endif
    )
    {
      std::cerr
        << "\n--- key callback (time: " << glfwGetTime() << ") ---\n"
           "  key     : " << key      << "\n"
           "  action  : " << action   << "\n"
#if GLFW_VERSION_MAJOR >= 3
           "  window  : " << window   << "\n"
           "  scancode: " << scancode << "\n"
           "  mods    : " << mods     << "\n"
#endif
        ;
#if GLFW_VERSION_MAJOR >= 3
      if ( key == GLFW_KEY_ESCAPE and action == GLFW_PRESS )
        glfwSetWindowShouldClose( window, GL_TRUE );
#else
      if ( key == GLFW_KEY_ESC and action == GLFW_PRESS )
        ::main_loop_is_continuous = false;
#endif
    }
  );
  
#if GLFW_VERSION_MAJOR >= 3
  glfwSetFramebufferSizeCallback
  ( window
  , [](GLFWwindow* window, int width, int height)
    { glViewport(0, 0, width, height); }
  );
#endif

    init();

#ifdef EMSCRIPTEN  
  emscripten_set_main_loop( []
#else
  do
#endif
  {
    // do update world
    {
        update();
    }
    
    // do render with GL(glXxx)
    {
        render();
    }
    
    glfwSwapBuffers
    (
#if GLFW_VERSION_MAJOR >= 3
      window
#endif
    );
    glfwPollEvents();
  }
#ifdef EMSCRIPTEN  
  , 0, 1);
#else
 #if GLFW_VERSION_MAJOR >= 3
  while ( not glfwWindowShouldClose( window ) );
 #else
  while ( ::main_loop_is_continuous );
 #endif
#endif
}