// converting from UTF-32 to UTF-8
#include <iostream>       // std::cout, std::hex
#include <string>         // std::string, std::u32string
#include <locale>         // std::wstring_convert
#include <bits/codecvt.h>        // std::codecvt_utf8
#include <cstdint>        // std::uint_least32_t


int main ()
{
  std::u32string str32 ( U"\U00004f60\U0000597d" );  // ni hao (�A�n)
  std::string str8;

  wstring_convert<std::codecvt_utf8<char32_t>,char32_t> cv;

  str8 = cv.to_bytes(str32);

  // print contents (as their hex representations):
  std::cout << std::hex;

  std::cout << "UTF-32: ";
  for (char32_t c : str32)
    std::cout << '[' << std::uint_least32_t(c) << ']';
  std::cout << '\n';

  std::cout << "UTF-8 : ";
  for (char c : str8)
    std::cout << '[' << int(static_cast<unsigned char>(c)) << ']';
  std::cout << '\n';

  return 0;
}
