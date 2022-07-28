//
// Created by Gianmarco Rampulla on 28/07/22.
//

#ifndef OMNIA_OMNIA_EXECUTOR_H
#define OMNIA_OMNIA_EXECUTOR_H
#include <string>
#include <vector>

class executor {

public:
    executor(std::vector<std::pair<std::string,std::string>> tokens) {
        this->tokens = tokens;
    }
    

private:
    std::vector<std::pair<std::string,std::string>> tokens;

};

#endif //OMNIA_OMNIA_EXECUTOR_H
