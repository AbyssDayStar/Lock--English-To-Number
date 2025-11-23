#include "lockLib.h"
#include <cstdlib>
bool run = true;
int main()
{
#ifdef DEBUG
    cout << "It is [DEBUG]" << endl;
#endif
    while (run)
    {
        cout << "Continue? (y/n): " << endl;
        char choice;
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            run = false;
        }
        else if (choice == 'y' || choice == 'Y')
        {
            system("clear");
            cout << "Enter lock character types (e.g., 'abc' for a lock with):" << endl;
        }
    }
    return 0;
}
