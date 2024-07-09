#include "cd_dynamic-memory-alloc.h"

using namespace std;

Cd::Cd(const char * perf, const char * lbl, int selec_count, double playt) {
    performers = new char[strlen(perf) + 1];
    strcpy(performers, perf);
    label = new char[strlen(lbl) + 1];
    strcpy(label, lbl);
    selections = selec_count;
    playtime = playt;
}

Cd &Cd::operator=(const Cd &d) {
    if(this == &d) { return *this; };
    delete [] performers;
    delete [] label;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
};

Cd::Cd(const Cd &d) {
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::~Cd() { // takes care of base class  stuff
    delete[] performers;
    delete[] label;
}

void Cd::Report() const
{
    cout << "Performer(s):\t"s << performers << endl;
    cout << "Label:\t"s << label << endl;
    cout << "Number of selections:\t"s << selections << endl;
    cout << "Playtime:\t"s << playtime << endl;
}

