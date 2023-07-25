/*********************************************************************
 * glh_file.c - File utilities. Source.
 ********************************************************************/
#include "glh_base.h"
#include "glh_file.h"

#include <fcntl.h>
#include <unistd.h>

int glh_open_file(const char *fname, struct GlhError *error)
{
  int fd = open(fname, O_RDONLY);
  if (fd < 0)
    error->type = GLH_ERROR_TYPE_OPEN_FILE;
  return fd;
}

int glh_get_file_size(int fd, struct GlhError *error)
{
  off_t pos = 0;
  off_t retval = 0;
  
  pos = lseek(fd, 0, SEEK_END);
  if (pos < 0)
    {
      error->type = GLH_ERROR_TYPE_READ_FILE;
      return -1;  
    }
  retval = lseek(fd, 0, SEEK_SET);
  if (retval < 0)
    {
      error->type = GLH_ERROR_TYPE_READ_FILE;
      return -1;		
    }
  return pos;
}

/********************************************************************/
/************************** PUBLIC SECTION **************************/
/********************************************************************/

void
glh_load_file(const char      *fname,
	      char            *buffer,
	      size_t          *size,
	      struct GlhError *error)
{
  assert(fname);
  assert(buffer);
  assert(size);
  assert(error);
  
  off_t pos = 0;
  int fd = 0;
  int retval = 0;

  error->type = GLH_ERROR_TYPE_OK;
  fd = glh_open_file(fname, error);
  if (fd < 0)
    return;
  pos = glh_get_file_size(fd, error);
  if (pos < 0)
    goto exit;
  buffer = (char *) xmalloc(pos);
  *size = pos;
  retval = read(fd, buffer, *size);
  if (retval < *size)
    {
      error->type = GLH_ERROR_TYPE_READ_FILE;
      free(buffer);
      goto exit;
    }

 exit:
  close(fd);
}

void
glh_load_ufile(const char      *fname,
	       unsigned char   *buffer,
	       size_t          *size,
	       struct GlhError *error)
{
  assert(fname);
  assert(buffer);
  assert(size);
  assert(error);
  
  off_t pos = 0;
  int fd = 0;
  int retval = 0;

  error->type = GLH_ERROR_TYPE_OK;
  fd = glh_open_file(fname, error);
  if (fd < 0)
    return;
  pos = glh_get_file_size(fd, error);
  if (pos < 0)
    goto exit;
  buffer = (unsigned char *) xmalloc(pos);
  *size = pos;
  retval = read(fd, buffer, *size);
  if (retval < *size)
    {
      error->type = GLH_ERROR_TYPE_READ_FILE;
      free(buffer);
      goto exit;
    }

 exit:
  close(fd);
}
