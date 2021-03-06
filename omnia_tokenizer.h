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
#include <map>

struct tokenizer {

public:

    tokenizer(std::string& token_m) {
        parse_token_map(token_m);
    }

    std::vector<std::pair<std::string,std::string>> tokenize(std::string& file_path) {
        code.open(file_path);
        if (code.is_open()) {
            if(code.good()) {
                while (code.get(peak)) {
                    identify_peak();
                }
                print_tokens();
                code.close();
            }
        } else {
            if(!code.eof() && code.fail())
                throw std::runtime_error("Can't read input file");
        }
        return tokens;
    }

    void print_tokens(){
        for(std::pair<std::string,std::string> s : tokens) {
            std::cout << "[" << s.first << "," << s.second << "]" << std::endl;
        }
    }

private:

    void parse_token_map(std::string& path) {

        std::ifstream token_m;
        token_m.open(path);
        std::string tok,val;
        char peak;
        bool val_phase = false;

        while (token_m.get(peak)) {
           if(peak == '\n') {
               token_map.emplace(tok, val);
               val_phase = false;
               tok.clear();
               val.clear();
           }
           else if(peak == ',') val_phase = true;
           else if(!val_phase) tok += peak;
           else val += peak;
        }
        if(!tok.empty() && !val.empty())
        token_map.emplace(tok, val);

    }

    void identify_peak() {
        if (isalpha(peak) || isnumber(peak)) {
            isCommandOrWord();
        }
        if (peak == ' ') return;
        if (peak == '\n') { lines++; return; }
        tokens.emplace_back(std::pair<std::string,std::string>(token_map[std::string(1,peak)],token_map[std::string(1,peak)]));
    }

    void isCommandOrWord() {
        int state = 0;
        std::string buffer = "";

        while(peak != 32 && peak != '.' && peak != '\n' && !code.eof()) {
            if ((state == 0 || state == 1) && isalpha(peak)) {
                buffer += peak;
                state = 1;
            }
            if (state == 0 || state == 2 && isnumber(peak)) {
                buffer += peak;
                state = 2;
            }
            if (state == 2 && std::isalpha(peak)) {
                buffer += peak;
                state = 1;
            }
            code.get(peak);
        }

        if (peak == '\n') lines++;
        try {
            tokens.emplace_back(std::pair<std::string,std::string>(buffer,token_map.at(buffer)));
        } catch (std::exception& e) {
            if(state == 1) tokens.emplace_back(std::pair<std::string,std::string>(buffer, token_map.at("s")));
            if(state == 2) tokens.emplace_back(std::pair<std::string,std::string>(buffer, token_map.at("n")));
        }

    }

    std::map<std::string,std::string> token_map;
    std::vector<std::pair<std::string,std::string>> tokens;
    std::ifstream code;
    char peak = '\0';
    int lines = 0;

};

#endif //OMNIA_OMNIA_TOKENIZER_H
