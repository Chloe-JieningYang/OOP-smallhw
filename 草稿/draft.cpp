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
    //�ļ����  
    long   hFile = 0;
    //�ļ���Ϣ������һ���洢�ļ���Ϣ�Ľṹ��  
    struct _finddata_t fileinfo;
    string p;//�ַ��������·��
    if ((hFile = _findfirst(p.assign(path).append("\\*.txt").c_str(), &fileinfo)) != -1)//�����ҳɹ��������
    {
        do
        {
            //�����Ŀ¼,����֮�����ļ����ڻ����ļ��У�  
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                //�ļ���������"."&&�ļ���������".."
                //.��ʾ��ǰĿ¼
                //..��ʾ��ǰĿ¼�ĸ�Ŀ¼
                //�ж�ʱ�����߶�Ҫ���ԣ���Ȼ�����޵ݹ�������ȥ�ˣ�
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            //�������,�����б�  
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        //_findclose������������
        _findclose(hFile);
    }
}


int main() {
    string filePath = ".\\book";//�Լ�����Ŀ¼  
    vector<string> files;

    //��ȡ��·���µ������ļ�
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
    
    unsigned char s[10] = "��";
    cout << (int)s[0] << " " << (int)s[1] << endl;

    return 0;
}