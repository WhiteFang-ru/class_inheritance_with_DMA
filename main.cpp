
#include "classic_dynamic-memory-alloc.h" // which will contain #include "cd_dynamic-memory-alloc.h"

void Bravo(const Cd &disk);
int main()
{
    Cd cd("Beatles", "Capitol", 14, 35.5); //  calls the constructor implicitly
    Classic classic = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17); //calls the constructor explicitly
    Cd *pcd = &cd;
    cout << "Using object directly:\n";
    cd.Report(); // use Cd method
    classic.Report(); // use Classic method
    cout << "\nUsing type cd * pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &classic;
    pcd->Report(); // use Classic method for classic object
    cout << "\nCalling a function with a Cd reference argument:\n";
    Bravo(cd);
    Bravo(classic);
    Cd cd1(cd); // copy constructor usage
    cd1.Report();
    Classic def_param;
    def_param.Report();
    cout << "\nTesting assignment: \n";
    def_param = classic;
    def_param.Report();

    return 0;
}
void Bravo(const Cd &disk)
{
    disk.Report();
}
