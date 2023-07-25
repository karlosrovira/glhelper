/*********************************************************************
 * glh_shader.c - Shader utilities. Source.
 ********************************************************************/
#include "glh_base.h"
#include "glh_shader.h"
#include "glh_file.h"

void
glh_compile_shader(GLenum           type,
		   const char      *code,
		   GLuint          *sid,
		   struct GlhError *error)
{
  GLint success = 0;

  error->type = GLH_ERROR_TYPE_OK;
  *sid = glCreateShader(type);
  if (*sid == 0)
    {
      error->type = GLH_ERROR_TYPE_CREATION;
      return;		     
    }
  glShaderSource(*sid, 1, &code, NULL);
  glCompileShader(*sid);
  glGetShaderiv(*sid, GL_COMPILE_STATUS, &success);
  if (success == GL_FALSE)
    {
      error->type = GLH_ERROR_TYPE_COMPILATION;
      glGetShaderInfoLog(*sid, GLH_ERROR_MESSAGE_SIZE, NULL, error->message);
    }
}

void
glh_compile_program(GLuint           vsid,
		    GLuint           fsid,
		    GLuint          *pid,
		    struct GlhError *error)
{
  GLint is_linked = 0;

  error->type = GLH_ERROR_TYPE_OK;
  *pid = glCreateProgram();
  if (*pid == 0)
    {
      error->type = GLH_ERROR_TYPE_CREATION;
      return;		     
    }
  glAttachShader(*pid, vsid);
  glAttachShader(*pid, fsid);
  glLinkProgram(*pid);
  glGetProgramiv(*pid, GL_LINK_STATUS, (GLint *) &is_linked);
  if (is_linked == GL_FALSE)
    {
      error->type = GLH_ERROR_TYPE_COMPILATION;
      glGetProgramInfoLog(*pid, GLH_ERROR_MESSAGE_SIZE, NULL, error->message);
    }
  glDetachShader(*pid, vsid);
  glDetachShader(*pid, fsid);
}

void glh_load_shader(GLenum           type,
		     const char      *path,
		     GLuint          *sid,
		     struct GlhError *error)
{
  char *code = NULL;
  size_t size;

  error->type = GLH_ERROR_TYPE_OK;
  glh_load_file(path, code, &size, error);
  if (error->type != GLH_ERROR_TYPE_OK)
    return;
  glh_compile_shader(type, code, sid, error);
}

/********************************************************************/
/************************** PUBLIC SECTION **************************/
/********************************************************************/


void glh_compile_vertex_shader(const char      *code,
			       GLuint          *sid,
			       struct GlhError *error)
{
  assert(code);
  assert(sid);
  assert(error);
  
  glh_compile_shader(GL_VERTEX_SHADER, code, sid, error);
}

void glh_compile_fragment_shader(const char      *code,
				 GLuint          *fid,
				 struct GlhError *error)
{
  assert(code);
  assert(fid);
  assert(error);
  
  glh_compile_shader(GL_FRAGMENT_SHADER, code, fid, error);
}

void glh_compile_shader_program(GLuint           vsid,
				GLuint           fsid,
				GLuint          *pid,
				struct GlhError *error)
{
  assert(fsid > 0);
  assert(vsid > 0);
  assert(pid);
  assert(error);
  
  glh_compile_program(vsid, fsid, pid, error);
}

void glh_load_vertex_shader(const char      *path,
			    GLuint          *sid,
			    struct GlhError *error)
{
  assert(path);
  assert(sid);
  assert(error);
  
  glh_load_shader(GL_VERTEX_SHADER, path, sid, error);
}

void glh_load_fragment_shader(const char      *path,
			      GLuint          *fid,
			      struct GlhError *error)
{
  assert(path);
  assert(fid);
  assert(error);
  
  glh_load_shader(GL_FRAGMENT_SHADER, path, fid, error);
}

void glh_load_shader_program(const char      *vs_path,
			     const char      *fs_path,
			     GLuint          *pid,
			     struct GlhError *error)
{
  assert(vs_path);
  assert(fs_path);
  assert(pid);
  assert(error);
  
  char *vscode = NULL;
  char *fscode = NULL;
  GLuint vsid = 0;
  GLuint fsid = 0;

  glh_load_shader(GL_VERTEX_SHADER, vs_path, &vsid, error);
  if (error->type != GLH_ERROR_TYPE_OK)
    return;
  glh_load_shader(GL_FRAGMENT_SHADER, fs_path, &fsid, error);
  if (error->type != GLH_ERROR_TYPE_OK)
    return;
  glh_compile_program(vsid, fsid, pid, error);
}
