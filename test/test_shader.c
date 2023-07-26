#include <string.h>

#define VSCODE "#version 330\n			\
in vec4 ipos;\n					\
void main(void) { gl_Position = ipos; }"
#define FSCODE "#version 330\n			\
out vec4 ocolor;				\
void main(void) { ocolor = vec4(1.0); }"

static void
test_compile_vertex_shader(void)
{
  char *code = strdup(VSCODE);
  GLuint id = 0;
  struct GlhError error = { 0 };
  
  glh_compile_vertex_shader(code, &id, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  assert(id != 0);
  free(code);
}

static void
test_compile_fragment_shader(void)
{
  char *code = strdup(VSCODE);
  GLuint id = 0;
  struct GlhError error = { 0 };
  
  glh_compile_fragment_shader(code, &id, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  assert(id != 0);
  free(code);
}

static void
test_compile_program(void)
{
  char *vscode = strdup(VSCODE);
  char *fscode = strdup(FSCODE);
  GLuint vid = 0;
  GLuint fid = 0;
  GLuint pid = 0;
  struct GlhError error = { 0 };

  glh_compile_vertex_shader(vscode, &vid, &error);
  glh_compile_fragment_shader(fscode, &fid, &error);
  glh_compile_shader_program(vid, fid, &pid, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  assert(pid != 0);
  free(vscode);
  free(vscode);
}

void test_shader(void)
{
  test_compile_vertex_shader();
  test_compile_fragment_shader();
  test_compile_program();
}
