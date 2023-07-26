#define TEST_DECODER "./files/test_decoder.png"

static void
test_decode_png(void)
{
  unsigned char *target = NULL;
  size_t size = 0;
  struct GlhError error = { 0 };
  struct GlhImage image = { 0 };

  glh_load_ufile(TEST_DECODER, &target, &size, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  glh_decode_png(target, size, &image, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  assert(image.width == 275);
  assert(image.height == 183);
  free(target);
  glh_image_destroy(&image);
}

void test_decoder(void)
{
  test_decode_png();
}
