#include "lockLib.h"
int main()
{ 
    vector<char> types={'a','b','c'};
    Lock myLock=Lock(types);
    return 0;
}
