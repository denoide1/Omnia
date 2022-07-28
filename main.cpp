#include <iostream>
#include "omnia_tokenizer.h"
#include "omnia_parser.h"

int main(int argc, char *argv[]) {

    std::string test_path = "/Users/gianmarcorampulla/Desktop/testOmniaLexer.txt";
    std::string token_map = "/Users/gianmarcorampulla/Desktop/testOmniaMap.txt";


    tokenizer tokenizer(token_map);
    parser parser(tokenizer.tokenize(test_path));

    parser.parse();
    return 0;
}
