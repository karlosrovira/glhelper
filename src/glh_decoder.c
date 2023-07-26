/*********************************************************************
 * glh_decoder.h - Image decoder utilities. Source.
 ********************************************************************/
#include "glh_base.h"
#include "glh_image.h"
#include "glh_decoder.h"
#include "lodepng.h"
#include <string.h>

void glh_decode_png(const unsigned char *png_data,
		    size_t               png_size,
		    struct GlhImage     *image,
		    struct GlhError     *error)
{
  assert(png_data);
  assert(png_size > 0);
  assert(error);
  
  unsigned width = 0;
  unsigned height = 0;
  const char *error_text = NULL;
  error->type = GLH_ERROR_TYPE_OK;
  unsigned err = lodepng_decode32(&image->data, &width, &height,
				  png_data, png_size);
  if (err > 0)
    {
      error->type = GLH_ERROR_TYPE_DECODE;
      error_text = lodepng_error_text(err);
      strncpy(error->message, error_text, GLH_ERROR_MESSAGE_SIZE);
      return;
    }
  image->width = width;
  image->height = height;
}

