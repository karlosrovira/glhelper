/*********************************************************************
 * glh_error.c - Error type. Header.
 ********************************************************************/
#define GLH_ERROR_MESSAGE_SIZE 4096

enum GlhErrorType {
  GLH_ERROR_TYPE_OK = 0,
  GLH_ERROR_TYPE_OPEN_FILE = 1,
  GLH_ERROR_TYPE_READ_FILE = 2,
  GLH_ERROR_TYPE_CREATION = 3,
  GLH_ERROR_TYPE_COMPILATION = 4
};

struct GlhError
{
  enum GlhErrorType type;
  char message[GLH_ERROR_MESSAGE_SIZE];
};
