#ifndef __cplusplus
#error This is a C++ header file and cannot be used from plain C
#endif

#ifndef lockLib_h
#define lockLib_h

#include <iostream>
#include <vector>
using std::vector, std::cout, std::endl, std::cin;
class baseLock
{
protected:
    vector<int> charNum;
    vector<char> charType;
    baseLock(const vector<char> type)
    {
        charType = type;
        for (int i = 0; i < charType.size(); i++)
        {
            charNum.push_back(charType.at(i));
        }
#ifdef DEBUG
        cout << endl
             << endl;
        cout << "There is [DEBUG]" << endl;
        cout << "Lock created with character types: ";
        for (char c : charType)
        {
            cout << c << ' ';
        }
        cout << endl;
        cout << "Lock created with character numbers: ";
        for (int n : charNum)
        {
            cout << n << ' ';
        }
        cout << endl;
        cout << endl
             << endl;
#endif
    }
#ifdef DEBUG
    ~baseLock()
    {
        cout << endl
             << endl;
        cout << "There is [DEBUG]" << endl;
        cout << "Class has members:" << endl;
        cout << "Character types: ";
        for (char c : charType)
        {
            cout << c << ' ';
        }
        cout << endl;
        cout << "Character numbers: ";
        for (int n : charNum)
        {
            cout << n << ' ';
        }
        cout << endl;
        cout << "Class is free" << endl;
        cout << endl
             << endl;
    }
#endif

public:
    baseLock() { cout << "This is base-class, don't use it" << endl; }
};
class Lock : baseLock
{
public:
    Lock(const vector<char> type) : baseLock(type) {}
    ~Lock() { cout << "done" << endl; }
};

class UnLock : baseLock
{
public:
    UnLock(const vector<char> type) : baseLock(type) {}
    ~UnLock() { cout << "done" << endl; }
};
#endif
