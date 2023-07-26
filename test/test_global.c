#include "../include/glh.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "test_file.c"
#include "test_decoder.c"
#include "test_shader.c"
#include "test_texture.c"

static struct GlhSdlWindow window;

static void
init_tests(void)
{
  struct GlhError error;
  glh_init_sdl(&error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  glh_make_sdl_window("Test window", 100, 100, &window, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  glh_init_glew(&error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  /*glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(glh_message_callback, NULL);*/
}

static void
finish_tests(void)
{
  glh_destroy_sdl_window(&window);
  glh_finish_sdl();
}

int
main(void)
{
  init_tests();
  test_file();
  printf("Test file: passed.\n");
  test_decoder();
  printf("Test decoder: passed.\n");
  test_shader();
  printf("Test shader: passed.\n");
  test_texture();
  printf("Test texture: passed.\n");
  finish_tests();
  printf("All tests passed.\n");
  return 0;
}
