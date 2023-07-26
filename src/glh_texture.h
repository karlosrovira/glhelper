/*********************************************************************
 * glh_texture.h - GL texture utilities. Header.
 ********************************************************************/

/*********************************************************************
 * A loaded texture of 'heigh' x 'width' size with 'id'.
 ********************************************************************/
struct GlhTexture
{
  GLuint        id;
  unsigned long width;
  unsigned long height;
};

/*********************************************************************
 * Load image into GL context.
 ********************************************************************/
void glh_load_texture(const struct GlhImage *image,
		      struct GlhTexture     *texture,
		      struct GlhError       *error);
