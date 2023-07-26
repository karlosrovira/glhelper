/*********************************************************************
 * glh_texture.c - GL texture utilities. Source.
 ********************************************************************/
#include "glh_base.h"
#include "glh_image.h"
#include "glh_texture.h"

void
glh_load_texture(const struct GlhImage *image,
		 struct GlhTexture     *texture,
		 struct GlhError       *error)
{
  assert(image);
  assert(texture);
  assert(error);
  
  error->type = GLH_ERROR_TYPE_OK;
  glGenTextures(1, &texture->id);
  if (texture->id == 0)
    {
      glh_set_error(GLH_ERROR_TYPE_IMAGE_LOAD, "Load image into GL",
		    error);
      return;
    }
  glBindTexture(GL_TEXTURE_2D, texture->id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width, image->height,
	       0, GL_RGBA, GL_UNSIGNED_BYTE, image->data);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_LINEAR);
  glGenerateMipmap(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, 0);
  texture->width = image->width;
  texture->height = image->height;
}
