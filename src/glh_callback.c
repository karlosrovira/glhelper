/*********************************************************************
 * glh_callback.c - Callback functions for debugging GL. Source.
 ********************************************************************/
#include "glh_base.h"
#include "glh_callback.h"

void glh_message_callback(GLenum        source,
			  GLenum        type,
			  GLuint        id,
			  GLenum        severity,
			  GLsizei       length,
			  const GLchar* message,
			  const void*   userParam)
{
  fprintf(stderr,
	  "GL CALLBACK: %s | type = 0x%d, severity = 0x%d, message = <<<%s>>>.\n",
	  (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
	  type,
	  severity,
	  message);
}
