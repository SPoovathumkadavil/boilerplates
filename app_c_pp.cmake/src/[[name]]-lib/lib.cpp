#include "lib.hpp"

#ifndef IS_TESTING
#define IS_TESTING false
#endif

library::library()
    : _name {"[[name]]"},
      _feta_dir {feta::directories(_name, feta::directories::get_home_dir() / ".loc.json", _test)}
{
}
