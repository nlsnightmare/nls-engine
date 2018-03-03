#include <iostream>
#include "Log.hpp"



void logging::init(){
    file.open(LOGFILE);
    if (!file.is_open()){
	std::cout << "ERROR: couldn't open file " << LOGFILE << "\n";
	return;
    }
}

void logging::log(std::string s){
    file << s << "\n";
}

