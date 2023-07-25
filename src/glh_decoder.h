/*********************************************************************
 * glh_decoder.h - Image decoder utilities. Source.
 ********************************************************************/

/*********************************************************************
 * Decode image in 'png_data' of size 'png_size' and store it in 
 * 'image'. Assign memory to 'image'. 
 ********************************************************************/
void glh_decode_png(const unsigned char *png_data,
		    size_t               png_size,
		    struct GlhImage     *image,
		    struct GlhError     *error);
