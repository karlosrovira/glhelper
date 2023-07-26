/*********************************************************************
 * glh.h - GL helpers.
 *
 * These need an active GL Context to operate. That one is present
 * must be guaranteed by the caller.
 *
 * I'm using Glew to access the GL functions. If you want to use
 * another system, simply modify glh_base.h and this, and recompile.
 *
 * Compile with: -lglh -lSLD2 -lGLEW -lGL -lGLU -lGL
 * Replace SDL2 for the system(s) you want to use, i.e. GLFW3 and/or
 * GLUT. From -lGLEW to the right its all GLEW libraries. 
 * 
 * Author: Gustavo M Domato
 * Date: 07-23-2023
 * Version: 0.1
 ********************************************************************/
#ifndef GLH_H
#define GLH_H

#include "config.h"
#include <GL/glew.h>

#include "../src/glh_error.h"
#include "../src/glh_image.h"
#include "../src/glh_callback.h"
#include "../src/glh_decoder.h"
#include "../src/glh_file.h"
#include "../src/glh_shader.h"
#include "../src/glh_texture.h"
#include "../src/glh_window.h"

#endif	/* !GLH_H */
