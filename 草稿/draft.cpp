#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <vector>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "head.h"
using namespace std;

#define MAX  16

void getFiles(string path, vector<string>& files)
{
    //文件句柄  
    long   hFile = 0;
    //文件信息，声明一个存储文件信息的结构体  
    struct _finddata_t fileinfo;
    string p;//字符串，存放路径
    if ((hFile = _findfirst(p.assign(path).append("\\*.txt").c_str(), &fileinfo)) != -1)//若查找成功，则进入
    {
        do
        {
            //如果是目录,迭代之（即文件夹内还有文件夹）  
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                //文件名不等于"."&&文件名不等于".."
                //.表示当前目录
                //..表示当前目录的父目录
                //判断时，两者都要忽略，不然就无限递归跳不出去了！
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            //如果不是,加入列表  
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        //_findclose函数结束查找
        _findclose(hFile);
    }
}


int main() {
    string filePath = ".\\book";//自己设置目录  
    vector<string> files;

    //获取该路径下的所有文件
        getFiles(filePath, files);

    int size = files.size();
    for (int i = 0; i < size; i++)
    {
        string temp = files[i];
        int tlen = temp.length();
        int postxt = temp.find(".txt");
        for (int k = postxt; k < tlen; k++)
            temp[k] = '\0';
        string temp2;
        temp2.assign(temp, 7);
        cout << temp2.c_str() << endl;
    }
    
    unsigned char s[10] = "—";
    cout << (int)s[0] << " " << (int)s[1] << endl;

    return 0;
}