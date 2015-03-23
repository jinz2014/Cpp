#include <stddef.h>
#include "Logger.h"

Logger* Logger::m_pInstance = NULL;

Logger* Logger::Instance() {
  if (m_pInstance == NULL)
    m_pInstance = new Logger();

  return m_pInstance; 
}
