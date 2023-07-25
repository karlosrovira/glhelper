/*********************************************************************
 * An image of size 'width' x 'height' stored in 'data'.
 ********************************************************************/
struct GlhImage
{
  unsigned long width;
  unsigned long height;
  unsigned char *data;
};

/*********************************************************************
 * Initialize 'image' to all zeroes of size 'width' x 'height'.
 ********************************************************************/
void glh_image_init(unsigned long width,
		    unsigned long height,
		    struct GlhImage *image);

/*********************************************************************
 * Get memory and initialize result to all zeroes of size 'width' x 
 * 'height'.
 ********************************************************************/
struct GlhImage *glh_image_create(unsigned long width,
				  unsigned long height);

/*********************************************************************
 * Free memory inside 'image' but not the pointer itself.
 ********************************************************************/
void glh_image_destroy(struct GlhImage *image);

/*********************************************************************
 * Free memory inside 'image' and the pointer. Set the pointer to 
 * NULL.
 ********************************************************************/
void glh_image_destroy_ptr(struct GlhImage **image);
