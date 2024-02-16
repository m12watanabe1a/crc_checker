#include <vector>
#include <iostream>

uint8_t calc_crc(const std::string &data)
{
  uint8_t ret = 0;
  for (const auto &c : data)
  {
    ret ^= static_cast<uint8_t>(c);
  }
  return ret;
}

int main(int argc, char **argv)
{
  const std::string data = std::string(argv[1]);
  std::cout << "data: " << data << std::endl;
  printf("CRC: %02hhX\n", calc_crc(data));
  return EXIT_SUCCESS;
}
