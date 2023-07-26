/*********************************************************************
 * glh_window.h - Window and GL context. Header.
 *
 * To initialize a system, f.e. SDL2, do:
 * glh_init_sdl(...)
 * glh_make_sdl_window(...)
 * glh_init_glew(...) // For any system
 ********************************************************************/

#ifdef HAVE_SDL
#include <SDL2/SDL.h>
/*********************************************************************
 *
 ********************************************************************/
struct GlhSdlWindow
{
  SDL_Window   *window;
  SDL_GLContext glcontext;
};

/*********************************************************************
 * Initialize sdl system.
 ********************************************************************/
void glh_init_sdl(struct GlhError *error);

/*********************************************************************
 * Finish sdl system.
 ********************************************************************/
void glh_finish_sdl(void);

/*********************************************************************
 * Create a sdl window with 'title', of size 'width'x'height'. The
 * window is hidden by default.
 ********************************************************************/
void glh_make_sdl_window(const char          *title,
			 int                  width,
			 int                  height,
			 struct GlhSdlWindow *window,
			 struct GlhError     *error);

/*********************************************************************
 * Free memory in 'window' but not the pointer itself.
 ********************************************************************/
void glh_destroy_sdl_window(struct GlhSdlWindow *window);
#endif

#ifdef HAVE_GLUT
struct GlhGlutWindow
{
  GLUT_Window *window;
};
#endif

#ifdef HAVE_GLFW
struct GlhGlfwWindow
{
  GLFW_Window *window;
};
#endif

/*********************************************************************
 * Initialize GLEW. Requires a window and an active GL context. 
 ********************************************************************/
void glh_init_glew(struct GlhError *error);
