/*********************************************************************
 * glh.h - GL helpers.
 *
 * These need an active GL Context to operate. That one is present
 * must be guaranteed by the caller.
 *
 * I'm using Glew to access the GL functions. If you want to use
 * another system, simply modify glh_base.h and this, and recompile.
 *
 * Author: Gustavo M Domato
 * Date: 07-23-2023
 * Version: 0.1
 ********************************************************************/
#ifndef GLH_H
#define GLH_H

#include <GL/glew.h>

#include "../src/glh_error.h"
#include "../src/glh_image.h"
#include "../src/glh_callback.h"
#include "../src/glh_decoder.h"
#include "../src/glh_file.h"
#include "../src/glh_shader.h"

#endif	/* !GLH_H */
