#include <string>

#include "[[name]]/[[name]].hpp"

auto main() -> int
{
  auto const exported = exported_class {};

  return std::string("[[name]]") == exported.name() ? 0 : 1;
}
