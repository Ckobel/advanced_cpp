#include <iostream>
#include "Word.cpp"

using namespace std;

int main(int argc, char* argv[]) {

    Word* wordlist = new Word;
    wordlist = parseFile(wordlist,argv[1]);

    print_list(wordlist);


    return 0;
}