#include <iostream>
#include <cstring>
using namespace std;

// base class
class Cd
{ // represents a CD disk
private:
    char * performers; // use 'new' in constructors
    char * label;
    int selections;  // number of selections
    double playtime; // playing time in minutes

public:
    Cd(const char * perf = "null", const char * lbl = "null",
                int selec_count = 0, double playt = 0.0); // default constructor, provided with default values
    Cd(const Cd &d); // copy constructor
    virtual ~Cd();
    virtual void Report() const; // outputs to console all CD data
    Cd &operator=(const Cd &d); // overloaded assignment operator
};

// dynamic memory allocation (DMA) requires:
// a destructor, a copy constructor, an overloaded assignment operator
// (cause memberwise copying is inappropriate for DMA)

