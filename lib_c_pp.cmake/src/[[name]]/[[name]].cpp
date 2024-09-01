#include <string>

#include "[[name]]/[[name]].hpp"

exported_class::exported_class()
    : m_name {"[[name]]"}
{
  feta::directories fetadir(m_name);
  project_directories = fetadir.proj_dirs();
}

auto exported_class::name() const -> char const*
{
  return m_name.c_str();
}
