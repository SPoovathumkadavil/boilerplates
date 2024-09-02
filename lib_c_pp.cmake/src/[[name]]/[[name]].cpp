#include <string>

#include "[[name]]/[[name]].hpp"

#ifndef IS_TESTING
#define IS_TESTING false
#endif

exported_class::exported_class()
    : _name {"[[name]]"},
      _test {IS_TESTING},
      _feta_dirs {feta::directories(_name, feta::directories::get_home_dir() / ".loc.json", _test)}
{}

