#include <string.h>

#define TEST_FILE "./files/test_file.txt"

static void
test_load_file(void)
{
  char *target = NULL;
  size_t size = 0;
  struct GlhError error = { 0 };

  glh_load_file(TEST_FILE, &target, &size, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  assert(size == 9);
  assert(target);
  assert(strcmp(target, "23456789\n") == 0);
  free(target);
}

static void
test_load_ufile(void)
{
  unsigned char *target = NULL;
  size_t size = 0;
  struct GlhError error = { 0 };

  glh_load_ufile(TEST_FILE, &target, &size, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  assert(size == 9);
  assert(target);
  assert(strcmp(target, "23456789\n") == 0);
  free(target);
}

void test_file(void)
{
  test_load_file();
  test_load_ufile();
}
