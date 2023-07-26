/*********************************************************************
 * glh_image.h - Raw image utilities. Header.
 ********************************************************************/

/*********************************************************************
 * An 32-bit RGBA image of size 'width' x 'height' stored in 'data'.
 ********************************************************************/
struct GlhImage
{
  unsigned long width;
  unsigned long height;
  unsigned char *data;
};

/*********************************************************************
 * Initialize 'image' to all zeroes of size 'width' x 'height' x 4x8.
 ********************************************************************/
void glh_image_init(unsigned long    width,
		    unsigned long    height,
		    struct GlhImage *image);

/*********************************************************************
 * Free memory inside 'image' but not the pointer itself.
 ********************************************************************/
void glh_image_destroy(struct GlhImage *image);
