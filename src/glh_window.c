/*********************************************************************
 * glh_window.c - Window and GL context. Sourcce.
 ********************************************************************/
#include "glh_base.h"
#include "glh_window.h"

/********************************************************************/
/************************** PUBLIC SECTION **************************/
/********************************************************************/

#ifdef HAVE_SDL
void
glh_init_sdl(struct GlhError *error)
{
  assert(error);

  error->type = GLH_ERROR_TYPE_OK;
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
      glh_set_error(GLH_ERROR_TYPE_SYSTEM_INIT, SDL_GetError(), error);
      return;
    }
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                      SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
}

void
glh_finish_sdl(void)
{
  SDL_Quit();
}

void
glh_make_sdl_window(const char *title, int width, int height,
		    struct GlhSdlWindow *window, struct GlhError *error)
{
  assert(title);
  assert(width > 0);
  assert(height > 0);
  assert(window);
  assert(error);
  
  error->type = GLH_ERROR_TYPE_OK;
  window->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
				    SDL_WINDOWPOS_CENTERED, width,
				    height,
				    SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);
  if (!window->window)
    {
      glh_set_error(GLH_ERROR_TYPE_WINDOW_INIT, SDL_GetError(), error);
      return;
    }
  window->glcontext = SDL_GL_CreateContext(window->window);
  if (!window->glcontext)
    {
      glh_set_error(GLH_ERROR_TYPE_CONTEXT_INIT, SDL_GetError(), error);
      return;
    }
  SDL_GL_SetSwapInterval(0);
}

void
glh_destroy_sdl_window(struct GlhSdlWindow *window)
{
  assert(window);
  
  SDL_DestroyWindow(window->window);
  SDL_GL_DeleteContext(window->glcontext);
}
#endif

void
glh_init_glew(struct GlhError *error)
{
  assert(error);

  error->type = GLH_ERROR_TYPE_OK;
  GLenum glew_status = glewInit();
  if (glew_status != GLEW_OK)
    {
      glh_set_error(GLH_ERROR_TYPE_GLEW_INIT, glewGetErrorString(glew_status), error);
      return;
    }
  if (!GLEW_VERSION_3_0)
    {
      glh_set_error(GLH_ERROR_TYPE_GLEW_INIT, "OpenGL 3.0 not supported", error);
      return;
    }
}
