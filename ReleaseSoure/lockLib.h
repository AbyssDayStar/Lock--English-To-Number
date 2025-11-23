#ifndef __cplusplus
#error This is a C++ header file and cannot be used from plain C
#endif // cpp指定，因为需要string vector isotream等C++特性

#ifndef lockLib_h
#define lockLib_h // 防止重复包含

#include <iostream>
#include <vector>                                               //导入头文件
using std::vector, std::cout, std::endl, std::cin, std::string; // 使用命名空间中的特定成员
class baseLock                                                  // 基类
{
protected:
    vector<int> charNum;
    string charType; // 定义所需数据成员
};
class Lock : baseLock // 加密类
{
public:
    Lock(const string type) // 构造函数：传入字符串并转换为数字
    {
        charType = type;
        for (int i = 0; i < charType.size(); i++)
        {
            charNum.push_back(charType.at(i) - '0'-'0');
        }
    }
    void print()
    {
        cout << "Lock types: ";
        for (int c : charNum)
        {
            cout << c << ' ';
        }
        cout<<-1;
        cout << endl;
    } // 输出内容
    ~Lock() { cout << "done" << endl; } // 析构函数
};

class UnLock : baseLock
{
public:
    UnLock(const vector<int> num)
    { // 构造函数：传入数字并转换为字符
        charNum = num;
        for (int i = 0; i < charNum.size(); i++)
        {
            charType.push_back(charNum.at(i) + '0'+'0');
        }
    }
    void print()
    {
        cout << "Lock types: ";
        for (char c : charType)
        {
            cout << c << ' ';
        }
        cout << endl;
    } // 输出内容
    ~UnLock() { cout << "done" << endl; } // 析构函数
};
#endif
