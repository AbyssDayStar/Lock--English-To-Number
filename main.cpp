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
            #ifdef _WIN32
            system("cls");
            #elif __linux__ or __APPLE__  
            system("clear");
            #elif __unix__
            system("clear");
            #endif
            cout<<"Lock or UnLock? (l/u): "<<endl;
            cin>>choice;
            if(choice=='l'||choice=='L')
            {
                cout<<"Input types(string): "<<endl;
                string types;
                cin>>types;
                Lock myLock(types);
                myLock.print();
            }
            else if(choice=='u'||choice=='U')
            {
                cout<<"Input numbers(separated by space, end with -1): "<<endl;
                vector<int> input;
                int num;
                while(true)
                {
                    cin>>num;
                    if(num==-1) break;
                    input.push_back(num);
                }
                UnLock myUnLock(input);
                myUnLock.print();
            }
            else
            {
                cout<<"Invalid input!"<<endl;
            }
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
    return 0;
}
