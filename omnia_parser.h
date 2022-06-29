//
// Created by Gianmarco Rampulla on 29/06/22.
//

#ifndef OMNIA_OMNIA_PARSER_H
#define OMNIA_OMNIA_PARSER_H
#include <string>
#include <vector>


struct parser {

public:
        parser(std::vector<std::pair<std::string,std::string>> tokens) {
            this->tokens = tokens;
        }

        void parse() {



        }

private:
    std::vector<std::pair<std::string,std::string>> tokens;


};

#endif //OMNIA_OMNIA_PARSER_H
