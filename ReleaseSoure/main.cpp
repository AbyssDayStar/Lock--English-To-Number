#include "lockLib.h"// 导入library
#include <cstdlib>// for system()
bool run = true;// 控制主循环
bool lang=true;// true for English, false for Chinese
int main()
{
    cout<<"choose language / 选择语言 (e/c): "<<endl;
        char lchar;
        cin>>lchar;
        while(true){
        if(lchar=='e'||lchar=='E')
        {
            lang=true;
            break;
        }
        else if(lchar=='c'||lchar=='C')
        {
            lang=false;
            break;
        }
        else
        {
            cout<<"Invalid input!/无效的输入！"<<endl;
        }
    }
    while (run)// 主循环开始
    {
        
        if (lang){
            cout << "Continue? (y/n): " << endl;}// 询问是否继续
        else{
            cout << "是否继续？ (y/n): " << endl;}// 询问是否继续
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
            if(lang)
            {cout<<"Conver or Revert? (c/r): "<<endl;}
            else{
                cout<<"转换还是恢复？ (c/r): "<<endl;
            }
            cin>>choice;// 选择加密或解密
            if(choice=='c'||choice=='C')
            {
                if(lang)
                {cout<<"Input types(end with -1): "<<endl;}
                else{
                    cout<<"输入字符(以-1结束): "<<endl;
                }
                vector<string> types;
                while(true)
                {
                    string s;
                    cin>>s;
                    if(s=="-1") break;
                    types.push_back(s);
                }
                Lock myLock(types,lang);
                myLock.print();
            }// 加密流程
            else if(choice=='r'||choice=='R')
            {
                if(lang)
                {cout<<"Input numbers(separated by space, end with -1): "<<endl;}
                else{
                    cout<<"输入数字(以空格分隔，以-1结束): "<<endl;
                }
                vector<int> input;
                int num;
                while(true)
                {
                    cin>>num;
                    if(num==-1) break;
                    input.push_back(num);
                }
                UnLock myUnLock(input,lang);
                myUnLock.print();
            }// 解密流程
            else
            {
                if(lang)
                {cout<<"Invalid input!"<<endl;}
                else{
                    cout<<"无效输入！"<<endl;
                }
            }// 无效输入处理
        }
        else
        {
            if(lang)
            {cout << "Invalid input!" << endl;}
            else{
                cout<<"无效输入！"<<endl;
            }
        }// 无效输入处理
    }
    return 0;
}
