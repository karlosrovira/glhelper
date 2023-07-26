/*********************************************************************
 * glh_error.c - Error type. Source.
 ********************************************************************/
#include "glh_base.h"
/* Don't include "glh_error.h" since "glh_base.h" already does. */
#include <string.h>

void
glh_set_error(enum GlhErrorType type, const char *message,
	      struct GlhError *error)
{
  assert(error);
  
  error->type = type;
  if (message)
    strncpy(error->message, message, GLH_ERROR_MESSAGE_SIZE);
}
