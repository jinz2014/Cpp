#ifndef LOGGER_H
#define LOGGER_H

#include <string>
class Logger {
  public:
    // only Instance can call the ctor
    // public access to the ctor is not allowed
    static Logger* Instance();
    bool openLogFile(std::string logFile);
    bool closeLogFile();
    void writeToLogFile();

  private:
    Logger();
    Logger(Logger const&);  // copy
    Logger& operator=(Logger const&);  // copy
    static Logger* m_pInstance;
};

#endif
