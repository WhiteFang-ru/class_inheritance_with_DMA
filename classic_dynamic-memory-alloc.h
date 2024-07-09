#include "cd_dynamic-memory-alloc.h"

class Classic : public Cd {
private:
    char * primary_work;
    char * instrument_brand;

public:
    Classic(const char * primwrk = "null", const char * prfrmer = "null",
                const char * instr_brand = "null", int selec_count = 0, double plytme = 0.0);
    Classic(const char * primwrk, const char * instr_brand, const Cd & d);
    Classic(const Classic & cl); // copy constructor
    virtual ~Classic(); // derived class destructor automatically calls the base-class destructor
    Classic &operator=(const Classic &cl);
    virtual void Report() const;
};

// derived class with dynamic memory allocation
// destructor needed (virtual, cause base class also has destructor)
// uses explicit copy constructor
// uses explicit assignment operator
