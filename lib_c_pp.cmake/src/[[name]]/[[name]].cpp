#include <string>

#include "[[name]]/[[name]].hpp"

exported_class::exported_class()
    : m_name {"[[name]]"}
{
}

auto exported_class::name() const -> char const*
{
  return m_name.c_str();
}
