#ifndef OCC_CPP
#define OCC_CPP

class Occurence {
private:
    Occurence *Link;
    int position;
    int line;
public:

    Occurence() { Link = 0; }

    Occurence(int l, int p) {
        position = p;
        line = l;
        Link = 0;
    }



    int &pos() { return position; }

    int &lin() { return line; }

    Occurence *&link() { return Link; }
};

#endif OCC_CPP