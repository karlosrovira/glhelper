/*********************************************************************
 * glh_error.h - Error type. Header.
 ********************************************************************/
#define GLH_ERROR_MESSAGE_SIZE 4096

enum GlhErrorType {
  GLH_ERROR_TYPE_OK = 0,
  GLH_ERROR_TYPE_OPEN_FILE = 1,
  GLH_ERROR_TYPE_READ_FILE = 2,
  GLH_ERROR_TYPE_CREATION = 3,
  GLH_ERROR_TYPE_COMPILATION = 4,
  GLH_ERROR_TYPE_DECODE = 5,
  GLH_ERROR_TYPE_SYSTEM_INIT = 6,
  GLH_ERROR_TYPE_WINDOW_INIT = 7,
  GLH_ERROR_TYPE_CONTEXT_INIT = 8,
  GLH_ERROR_TYPE_GLEW_INIT = 9,
  GLH_ERROR_TYPE_IMAGE_LOAD = 10
};

struct GlhError
{
  enum GlhErrorType type;
  char message[GLH_ERROR_MESSAGE_SIZE];
};

/*********************************************************************
 * Set 'error' to 'type' with 'message'. If 'message' null then just 
 * set the type.
 ********************************************************************/
void glh_set_error(enum GlhErrorType type,
		   const char       *message,
		   struct GlhError  *error);
