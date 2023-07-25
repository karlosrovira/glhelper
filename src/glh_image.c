/*********************************************************************
 * Image.c - Image implementation. Source.
 ********************************************************************/
#include "glh_base.h"
#include "glh_image.h"

static void pfn_image_init(unsigned long    width,
			   unsigned long    height,
			   struct GlhImage *image)
{
  image->height = height;
  image->width  = width;
  image->data = (unsigned char *) xmalloc(width * height);
}

static void pfn_image_destroy(struct GlhImage *image)
{
  free(image->data);
}

/********************************************************************/
/************************** PUBLIC SECTION **************************/
/********************************************************************/

void
glh_image_init(unsigned long    width,
	       unsigned long    height,
	       struct GlhImage *image)
{
  assert(image);
  assert(width > 0);
  assert(height > 0);
  
  pfn_image_init(width, height, image);
}

struct GlhImage *
glh_image_create(unsigned long width, unsigned long height)
{
  assert(width > 0);
  assert(height > 0);
  
  struct GlhImage *result =
    (struct GlhImage *) xmalloc(sizeof(struct GlhImage));
  pfn_image_init(width, height, result);
  return result;
}

void
glh_image_destroy(struct GlhImage *image)
{
  assert(image);
  
  pfn_image_destroy(image);
}

void
glh_image_destroy_ptr(struct GlhImage **image)
{
  assert(image);
  assert(*image);
  
  pfn_image_destroy(*image);
  free(*image);
  *image = NULL;
}
