#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "[[name]]" ? 0 : 1;
}
