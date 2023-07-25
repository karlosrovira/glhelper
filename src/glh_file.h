/*********************************************************************
 * glh_file.h - File utilities. Header.
 ********************************************************************/

/*********************************************************************
 * Load file named 'fname' into 'buffer', and set the 'size'. Memory
 * will be assigned to 'buffer' by the function.
 *
 * If there is an error, 'error' will be filled with details and the
 * values returned of 'buffer' and 'size' will be meaningless. 
 ********************************************************************/
void glh_load_file(const char        *fname,
		   char              *buffer,
		   size_t            *size,
		   struct GlhError   *error);

/*********************************************************************
 * Same as 'glh_load_file' but loads an unsigned char buffer.
 ********************************************************************/
void glh_load_ufile(const char           *fname,
		    unsigned char        *buffer,
		    size_t               *size,
		    struct GlhError      *error);
