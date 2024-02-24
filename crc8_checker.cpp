#include <vector>
#include <iostream>
#include <cstring>

#ifndef USE_TABLE
static const uint8_t crc8_ccitt_small_table[16] = {
	0x00, 0x07, 0x0e, 0x09, 0x1c, 0x1b, 0x12, 0x15,
	0x38, 0x3f, 0x36, 0x31, 0x24, 0x23, 0x2a, 0x2d
};

uint8_t crc8_ccitt_table(uint8_t val, const void *buf, size_t len)
{
	size_t i;
	const uint8_t *p = (uint8_t *)buf;

	for (i = 0; i < len; i++) {
		val ^= p[i];
		val = (val << 4) ^ crc8_ccitt_small_table[val >> 4];
		val = (val << 4) ^ crc8_ccitt_small_table[val >> 4];
	}
	return val;
}
#else
uint8_t crc8_ccitt(uint8_t val, const void *buf, size_t len)
{
  const uint8_t poly = 0x07;
  uint8_t *p = (uint8_t *)buf;
  for (size_t i = 0; i < len; i++) {
    val ^= p[i];
    for (size_t j = 0; j < 8; j++) {
      if ((val & 0x80) != 0) {
        val = (uint8_t)((val << 1) ^ poly);
      } else {
        val = (val << 1);
      }
    }
  }
  return val;
}
#endif

int main(int argc, char **argv)
{
  const std::string data = std::string(argv[1]);
#ifndef USE_TABLE
  printf("%s -> %02hhX\n", data.c_str(), crc8_ccitt(0, data.c_str(), data.length()));
#else
  printf("%s => %02hhX\n", data.c_str(), crc8_ccitt_table(0, data.c_str(), data.length()));
#endif
  return EXIT_SUCCESS;
}
