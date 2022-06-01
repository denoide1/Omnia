//
// Created by Gianmarco Rampulla on 01/06/2022.
//

#ifndef OMNIA_OMNIA_TOKENIZER_H
#define OMNIA_OMNIA_TOKENIZER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

struct tokenizer {

public:
    std::vector<std::string> tokenize(std::string file_path) {
        std::ifstream code;
        code.open(file_path);
        if (code.is_open()) {
            char c;
            if(code.good()) {
                code.get(c);
                update_chunk(c);
            }
        } else {
            if(!code.eof() && code.fail())
                throw std::runtime_error("Can't read input file");
        }
    }

private:
    std::vector<std::string> tokens;
    std::string buffer = "";

    void update_chunk(char c) {
        if(isalpha(c)) buffer += c;
        if(c == ' ' || c == '\n' || c == '.') identify_chunk();
    }

    void identify_chunk() {

    }


};

#endif //OMNIA_OMNIA_TOKENIZER_H
