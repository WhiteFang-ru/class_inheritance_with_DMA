#include "classic_dynamic-memory-alloc.h"

Classic::Classic(const char * primwrk, const char * prfrmer,
                   const char * instr_brand,  int selec_count, double plytme)
            : Cd(prfrmer, "null", selec_count, plytme)
{
    primary_work = new char[strlen(primwrk) + 1];
    strcpy(primary_work, primwrk);
    instrument_brand = new char[strlen(instr_brand) + 1];
    strcpy(instrument_brand, instr_brand);
}

Classic::Classic(const char * primwrk, const char * instr_brand, const Cd & d)
            : Cd(d) {
    primary_work = new char[strlen(primwrk) + 1];
    strcpy(primary_work, primwrk);
    instrument_brand = new char[strlen(instr_brand) + 1];
    strcpy(instrument_brand, instr_brand);
};

Classic::Classic(const Classic &cl)
            : Cd(cl) {   // invokes base class copy constructor
    cout <<  "Classic: copy constructor is called\n";
    primary_work = new char[strlen(cl.primary_work) + 1];
    strcpy(primary_work, cl.primary_work);
    instrument_brand = new char[strlen(cl.instrument_brand) + 1];
    strcpy(instrument_brand, cl.instrument_brand);
}

Classic &Classic::operator=(const Classic &cl) {
    if(this == &cl) { return *this;};
    Cd::operator=(cl); // copy base portion
    delete [] primary_work;
    delete [] instrument_brand;
    primary_work = new char[strlen(cl.primary_work) + 1];
    strcpy(primary_work, cl.primary_work);
    instrument_brand = new char[strlen(cl.instrument_brand) + 1];
    strcpy(instrument_brand, cl.instrument_brand);
    return *this;
}

Classic::~Classic() { // takes care of a derived-class  stuff
    delete [] primary_work;
    delete [] instrument_brand;
}

void Classic::Report() const
{
    Cd::Report(); // displays Cd portion
    cout << "Classic, primary work:\t"s << primary_work << endl;
    cout << "Classic, Instrument brand:\t"s << instrument_brand << endl;
}
