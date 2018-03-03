#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define LOCATION std::string(__FILE__) + " : " + std::to_string(__LINE__) + "("+ std::string(__FUNCTION__) + ")"

#define log_message(x) logging::log(std::string(x) + " " + LOCATION)
#define log_error(x) logging::log(std::string("[ERROR] :") + std::string(x) + " " + LOCATION)

namespace logging {
    
    static const char* LOGFILE = "log.txt";
    static std::ofstream file;

    void init();

    void log(std::string s);
}

