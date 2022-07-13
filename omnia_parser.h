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

        int parse() {

            int value = 0;
            while (i < this->tokens.size()) {
                fetch();
                switch (next_token.first) {
                    case "WRITE":
                        value = write();
                        break;
                    case "WORD":
                        value = -1;
                        break;
                    case "ENDPHRASE":
                        value =  -1;
                        break;
                    case "NUMBER":
                        value = -1;
                        break;

                }
            }

            return value;

        }

private:
    std::vector<std::pair<std::string,std::string>> tokens;
    std::pair<std::string,std::string> next_token;
    int i = 0;

    fetch() {
        next_token = tokens[i];
        i++;
    }

    write() {
        fetch();
        switch(next_token.first) {

            case "WRITE":
                return -1;
            case "WORD":
                return word();
            case "NUMBER":
                return number();
            case "ENDPHRASE":
                return -1;

        }

    }

    number() {
        fetch();
        switch(next_token.first) {

            case "WRITE":
                return -1;
            case "WORD":
                return word();
            case "NUMBER"
                return number();
            case "ENDPHRASE"
                return 0;

        }
    }

    word() {

        fetch();
        switch(next_token.first) {

            case "WRITE":
                return -1;
            case "WORD":
                return word();
            case "NUMBER":
                return number();
            case "ENDPHRASE":
                return 0;

        }

    }

};

#endif //OMNIA_OMNIA_PARSER_H
