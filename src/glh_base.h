/*********************************************************************
 * glh_base.h - Included in every source.
 ********************************************************************/
#include "config.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

inline void *xmalloc(size_t size)
{
  void *result = malloc(size);
  if (!result)
    {
      fprintf(stderr, "Memory exhausted.\n");
      exit(EXIT_FAILURE);
    }
  return result;
}

#include "glh_error.h"
#include <GL/glew.h>
