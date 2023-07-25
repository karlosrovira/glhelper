/*********************************************************************
 * glh_callback.h - Callback functions for debugging GL. Header.
 ********************************************************************/

/*********************************************************************
 *
 ********************************************************************/
void glh_message_callback(GLenum        source,
			  GLenum        type,
			  GLuint        id,
			  GLenum        severity,
			  GLsizei       length,
			  const GLchar* message,
			  const void*   userParam);
