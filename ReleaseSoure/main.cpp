#include "lockLib.h"// 导入library
#include <cstdlib>// for system()
bool run = true;// 控制主循环
int main()
{
    while (run)// 主循环开始
    {
        cout << "Continue? (y/n): " << endl;// 询问是否继续
        char choice;
        cin >> choice;// 获取用户输入
        if (choice == 'n' || choice == 'N')// 退出条件
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
            #endif// 清屏命令，跨平台
            cout<<"Lock or UnLock? (l/u): "<<endl;
            cin>>choice;// 选择加密或解密
            if(choice=='l'||choice=='L')
            {
                cout<<"Input types(string): "<<endl;
                string types;
                cin>>types;
                Lock myLock(types);
                myLock.print();
            }// 加密流程
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
            }// 解密流程
            else
            {
                cout<<"Invalid input!"<<endl;
            }// 无效输入处理
        }
        else
        {
            cout << "Invalid input!" << endl;
        }// 无效输入处理
    }
    return 0;
}
