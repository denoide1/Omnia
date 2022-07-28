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
            fetch();
            while (i < this->tokens.size()) {
                if(next_token.second == "WRITE"){
                    match("WRITE");
                    write();
                }
                else {
                    throw std::runtime_error("syntax error");
                }
            }
        }

private:
    std::vector<std::pair<std::string,std::string>> tokens;
    std::pair<std::string,std::string> next_token;
    int i = -1;

    void fetch() {
        i++;
        next_token = tokens[i];
    }

    void match(const std::string& tag) {
        if(tag == tokens[i].second) fetch(); else throw std::runtime_error("syntax error");
    }

    void write() {
;
        if(next_token.second == "WORD"){
            match("WORD");
            match("ENDPHRASE");
            return;
        }
        if(next_token.second == "NUMBER"){
            match("NUMBER");
            match("ENDPHRASE");
            return;
        }

        throw std::runtime_error("syntax error");
    }
};

#endif //OMNIA_OMNIA_PARSER_H
