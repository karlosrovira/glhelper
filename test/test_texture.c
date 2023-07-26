void
test_texture(void)
{
  unsigned char *target = NULL;
  size_t size = 0;
  struct GlhError error = { 0 };
  struct GlhImage image = { 0 };
  struct GlhTexture texture = { 0 };

  glh_load_ufile(TEST_DECODER, &target, &size, &error);
  glh_decode_png(target, size, &image, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  glh_load_texture(&image, &texture, &error);
  assert(error.type == GLH_ERROR_TYPE_OK);
  assert(texture.id != 0);
  assert(texture.width == 275);
  assert(texture.height == 183);
  free(target);
  glh_image_destroy(&image);
}
