/*********************************************************************
 * glh_shader.h - Shader utilities. Header.
 ********************************************************************/

/*********************************************************************
 *
 ********************************************************************/
void glh_compile_vertex_shader(const char      *code,
			       GLuint          *sid,
			       struct GlhError *error);

/*********************************************************************
 *
 ********************************************************************/
void glh_compile_fragment_shader(const char      *code,
				 GLuint          *fid,
				 struct GlhError *error);

/*********************************************************************
 *
 ********************************************************************/
void glh_compile_shader_program(GLuint           vsid,
				GLuint           fsid,
				GLuint          *pid,
				struct GlhError *error);

/*********************************************************************
 *
 ********************************************************************/
void glh_load_vertex_shader(const char      *path,
			    GLuint          *sid,
			    struct GlhError *error);

/*********************************************************************
 *
 ********************************************************************/
void glh_load_fragment_shader(const char      *path,
			      GLuint          *fid,
			      struct GlhError *error);

/*********************************************************************
 *
 ********************************************************************/
void glh_load_shader_program(const char      *vs_path,
			     const char      *fs_path,
			     GLuint          *pid,
			     struct GlhError *error);

