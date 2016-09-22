#ifndef WORD_CPP
#define WORD_CPP

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Occurence.cpp"

template<class T>
void add_at_end(T *&first, T *r);

class Word;

void print_list(Word *p);

Word *find(Word *&wrdlist, std::string wrd);

class Occurence;

void print_list_occ(Occurence *o);

using namespace std;

class Word {
private:
    string word;
    Word *Link;
    int count;
    Occurence *olist;
public:


    Word() {
        Link = 0;
        olist = 0;
    }

    Word(string wrd) {
        word = wrd;
        Link = 0;
        count = 0;
        olist = new Occurence;
    }

    string &wrd() { return word; }

    Word *&link() { return Link; }

    int &cnt() { return count; }

    Occurence *&occ() { return olist; }
};

Word *parseFile(Word *&wrdlist, char *inFile) {
    int lineNumber = 0;
    int position;
    ifstream input(inFile);
    string line;

    while (!input.eof()) {
        if (getline(input, line)) {
            position = 0;
            lineNumber++;
            stringstream ss;
            ss << line;
            string word;
            while (ss >> word) {

                Word *wrd = new Word(word);
                Occurence *wrdOcc = wrd->occ();

                wrdOcc->lin() = lineNumber;
                wrdOcc->pos() = position;

                //if not found in the list, add to the end;
                if (!find(wrdlist, word)) {
                    add_at_end(wrdlist, wrd);
                    wrd->cnt()++;
                }
                else {
                    Word *current = find(wrdlist, word);
                    add_at_end(current->occ(), wrdOcc);
                    current->cnt()++;
                }


                position += (word.length() + 1);
            }
        }
    }

    input.close();
    return wrdlist;
}



Word *find(Word *&wrdlist, string wrd) {

    Word *current = wrdlist;
    while (current) {
        if (current->wrd() == wrd) {
            return current;
        }
        current = current->link();
    }
    return NULL;
}

void print_list(Word *p) {
    if (!p->link()) {
        cout << "the list is empty";
    }
    //move to first node in the list(the head node is acting like a placeholder right now because I cant figure out how to fix it, deal with it
    p = p->link();
    while (p) {
        cout << p->wrd() << "  " << p->cnt() << "  [";


        Occurence *occr = p->occ();
        while (occr) {
            cout << "(" << occr->lin() << "," << occr->pos() << ")";
            if (occr->link()) {
                cout << " , ";
            }
            occr = occr->link();

        }
        cout << "] " << endl;
        p = p->link();
    }
}


template<class T>
void add_at_end(T *&first, T *r) {
    T *p;
    p = first;
    while (p->link()) {
        p = p->link();
    }
    p->link() = r;

}


#endif WORD_CPP