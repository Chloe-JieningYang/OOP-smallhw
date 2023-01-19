//2050598 ����� ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#ifdef  _WIN32
#include <conio.h>
#endif
//������Ҫ�ɼ�������ͷ�ļ�
using namespace std;

#define FAIL_OPEN   -1

//�˴�Ϊʾ���������޸Ľṹ�����ƣ������޸Ľṹ���еĳ�Ա���ݣ�Ҫ��sizeof������64
struct info {
    char name[16] = { '\0' };
    short life;
    short strength;
    short health;//����
    short deft;//����
    unsigned int money;
    unsigned int fame;//����
    unsigned int charm;//����
    unsigned char time1;//��Ϸʱ������λ
    unsigned char time2;
    unsigned char time3;
    unsigned char time4;
    unsigned char time5;
    unsigned char time6;
    unsigned char time7;
    unsigned char time8;//��Ϸʱ�����λ
    unsigned char move_speed;//�ƶ��ٶ�
    unsigned char attack_speed;//�����ٶ�
    unsigned char attack_range;//������Χ
    unsigned char vac;//Ԥ��ֵ
    short attack_power;//������
    short defend_power;//������
    unsigned char agility;//���ݶ�
    unsigned char intelli;//����
    unsigned char exp;//����
    unsigned char level;//�ȼ�
    short magic;//ħ��ֵ
    unsigned char consume_magic;//ÿ�����ĵ�ħ��
    unsigned char magic_hurt;//ħ���˺���
    unsigned char hit_rate;//������
    unsigned char magic_defend;//ħ��������
    unsigned char crit_chance;//������
    unsigned char endurance;//����
};


/* �˴�����������������������
   1�����������ĺ����������������µ� fstream / ifstream / ofstream �����󣬲����д�/��/д/�رյȲ���
   2�����������ĺ���������������C��ʽ�����ļ�����
   3��������������ͬ��������main����
*/

void usage(char* ch[])
{
    cout << "usage : " << ch[0] << " --modify | --read" << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����pow����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
unsigned long long MyPow(int num,int time)
{
    unsigned long long result = 1;
    if (time == 0)
        return result;
    for (int n = 1; n <= time; n++)
        result *= num;
    return result;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���8��char ��ת��1��unsigned long long ��
  ���������char �����λ�����λ
  �� �� ֵ��
  ˵    ����
***************************************************************************/
unsigned long long TransferTime(unsigned char time1, unsigned char time2, unsigned char time3, unsigned char time4, unsigned char time5, unsigned char time6, unsigned char time7, unsigned char time8)
{
    unsigned long long time = 0;
    time += (unsigned long long)(time1) % 16 * MyPow(16, 0) + (unsigned long long)(time1) / 16 * MyPow(16, 1);
    time += (unsigned long long)(time2) % 16 * MyPow(16, 2) + (unsigned long long)(time2) / 16 * MyPow(16, 3);
    time += (unsigned long long)(time3) % 16 * MyPow(16, 4) + (unsigned long long)(time3) / 16 * MyPow(16, 5);
    time += (unsigned long long)(time4) % 16 * MyPow(16, 6) + (unsigned long long)(time4) / 16 * MyPow(16, 7);
    time += (unsigned long long)(time5) % 16 * MyPow(16, 8) + (unsigned long long)(time5) / 16 * MyPow(16, 9);
    time += (unsigned long long)(time6) % 16 * MyPow(16, 10) + (unsigned long long)(time6) / 16 * MyPow(16, 11);
    time += (unsigned long long)(time7) % 16 * MyPow(16, 12) + (unsigned long long)(time7) / 16 * MyPow(16, 13);
    time += (unsigned long long)(time8) % 16 * MyPow(16, 14) + (unsigned long long)(time8) / 16 * MyPow(16, 15);
    return time;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���һ��long longת��8��char
  ���������char �����λ�����λ
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void RenewTime(unsigned long long s, unsigned char& t1, unsigned char& t2, unsigned char& t3, unsigned char& t4, unsigned char& t5, unsigned char& t6, unsigned char& t7, unsigned char& t8)
{
    t1 = s % 16;
    s /= 16;
    t1 += s % 16 * 16;
    s /= 16;

    t2 = s % 16;
    s /= 16;
    t2 += s % 16 * 16;
    s /= 16;
    
    t3 = s % 16;
    s /= 16;
    t3 += s % 16 * 16;
    s /= 16;

    t4 = s % 16;
    s /= 16;
    t4 += s % 16 * 16;
    s /= 16;

    t5 = s % 16;
    s /= 16;
    t5 += s % 16 * 16;
    s /= 16;

    t6 = s % 16;
    s /= 16;
    t6 += s % 16 * 16;
    s /= 16;

    t7 = s % 16;
    s /= 16;
    t7 += s % 16 * 16;
    s /= 16;

    t8 = s % 16;
    s /= 16;
    t8 += s % 16 * 16;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡinfo������Ϣ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void PrintInfo(info player)
{
    cout << "--------------------------------------" << endl;
    cout << "  ��Ϸ�浵�ļ��޸Ĺ���" << endl;
    cout << "--------------------------------------" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  a.����ǳ�" << "(" << player.name << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  b.����" << "(" << player.life << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  c.����" << "(" << player.strength << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  d.����" << "(" << player.health << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  e.����" << "(" << player.deft << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  f.��Ǯ" << "(" << player.money << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  g.����" << "(" << player.fame << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  h.����" << "(" << player.charm << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  i.��Ϸ�ۼ�ʱ��" << "(" << TransferTime(player.time1, player.time2, player.time3, player.time4,
        player.time5, player.time6, player.time7, player.time8) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  j.�ƶ��ٶ�" << "(" << (int)(player.move_speed) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  k.�����ٶ�" << "(" << (int)(player.attack_speed) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  l.������Χ" << "(" << (int)(player.attack_range) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  m.������" << "(" << player.attack_power << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  n.������" << "(" << player.defend_power << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  o.���ݶ�" << "(" << (int)(player.agility) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  p.����" << "(" << (int)(player.intelli) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  q.����" << "(" << (int)(player.exp) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  r.�ȼ�" << "(" << (int)(player.level) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  s.ħ��ֵ" << "(" << player.magic << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  t.����ħ��ֵ" << "(" << (int)(player.consume_magic) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  u.ħ���˺���" << "(" << (int)(player.magic_hurt) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  v.ħ��������" << "(" << (int)(player.hit_rate) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  w.ħ��������" << "(" << (int)(player.magic_defend) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  x.������" << "(" << (int)(player.crit_chance) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  y.����" << "(" << (int)(player.endurance) << ")" << endl;

    cout << "--------------------------------------" << endl;
    cout << "  0.�����޸�" << endl;
    cout << "  1.�����˳�" << endl;
    cout << "--------------------------------------" << endl;
    cout << "��ѡ��[a..y, 0..1] ";

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ��������������ֻ�������һ��open��һ��read����Ϊ����������������close��
***************************************************************************/
int read()
{
    /* ��������ֻ������һ�� ifstream�����󣬲����������κ���ʽ��fstream/ifstream/ofstream������Ҳ������ʹ��C��ʽ���ļ����� */
    ifstream gfile;

    /* �ļ��򿪣�����Ҫ��Ϊ��
       1��Ҫ���Զ���ʽ�򿪣��򿪷�ʽ***����ָ��
       2��������open�⣬�����������ط��������ٳ���open  */
    gfile.open("game.dat", ios::in | ios::binary);

    /* ���к����������������������ļ�����ʾ����Ϸ���ֵ���ر��ļ��ȣ�������ú���
       ���У�ֻ������һ���Զ�ȡ64�ֽڵķ�����game.dat�����ݶ���***�����������ơ��ṹ����������ָ����
                 gfile.read(***, sizeof(demo));
    */
    if (gfile.is_open() == 0)
    {
        cout << "�޷����ļ�game.dat" << endl;
        return FAIL_OPEN;
    }
    info player;
    gfile.read((char*)&player, sizeof(player));

    cout << setw(20) << "����ǳƣ�" << player.name << endl;
    cout << setw(20) << "����ֵ��" << player.life << endl;
    cout << setw(20) << "����ֵ��" << player.strength << endl;
    cout << setw(20) << "����ֵ��" << player.health << endl;
    cout << setw(20) << "����ֵ��" << player.deft << endl;
    cout << setw(20) << "��Ǯֵ��" << player.money << endl;
    cout << setw(20) << "����ֵ��" << player.fame << endl;
    cout << setw(20) << "����ֵ��" << player.charm << endl;
    cout << setw(20) << "��Ϸ�ۼ�ʱ��(us)ֵ��" << TransferTime(player.time1, player.time2, player.time3,
        player.time4, player.time5, player.time6, player.time7, player.time8) << endl; 
    cout << setw(20) << "�ƶ��ٶ�ֵ��" << (int)(player.move_speed) << endl;
    cout << setw(20) << "�����ٶ�ֵ��" << (int)(player.attack_speed) << endl;
    cout << setw(20) << "������Χֵ��" << (int)(player.attack_range) << endl;
    cout << setw(20) << "������ֵ��" << player.attack_power << endl;
    cout << setw(20) << "������ֵ��" << player.defend_power << endl;
    cout << setw(20) << "���ݶ�ֵ��" << (int)(player.agility) << endl;
    cout << setw(20) << "����ֵ��" << (int)(player.intelli) << endl;
    cout << setw(20) << "����ֵ��" << (int)(player.exp) << endl;
    cout << setw(20) << "�ȼ�ֵ��" << (int)(player.level) << endl;
    cout << setw(20) << "ħ��ֵ��" << player.magic << endl;
    cout << setw(20) << "����ħ��ֵ��" << (int)(player.consume_magic) << endl;
    cout << setw(20) << "ħ���˺���ֵ��" << (int)(player.magic_hurt) << endl;
    cout << setw(20) << "������ֵ��" << (int)(player.hit_rate) << endl;
    cout << setw(20) << "ħ��������ֵ��" << (int)(player.magic_defend) << endl;
    cout << setw(20) << "������ֵ��" << (int)(player.crit_chance) << endl;
    cout << setw(20) << "����ֵ��" << (int)(player.endurance) << endl;

    gfile.close();

    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ��������������ֻ�������һ��open��һ��read��һ��write����Ϊ����������������close��
***************************************************************************/
int modify()
{
    /* ��������ֻ������һ�� fstream�����󣬲����������κ���ʽ��fstream/ifstream/ofstream������Ҳ������ʹ��C��ʽ���ļ����� */
    fstream gfile;

    /* �ļ��򿪣�����Ҫ��Ϊ��
       1��Ҫ���Զ�д��ʽ�򿪣��򿪷�ʽ***����ָ��
       2��������open�⣬�����������ط��������ٳ���open  */
    gfile.open("game.dat", ios::in | ios::out | ios::binary);

    /* ���к����������������������ļ�����ʾ����Ϸ���ֵ���ر��ļ��ȣ�������ú���
       ���У�ֻ������һ���Զ�ȡ64�ֽڵķ�����game.dat�����ݶ���***�����������ơ��ṹ����������ָ����
                 gfile.read(***, sizeof(demo));
             ֻ������һ����д��64�ֽڵķ�����***������д��game.dat�У����������ơ��ṹ����������ָ����
                 gfile.write(***, sizeof(demo));
    */
    if (!gfile.is_open())
    {
        cout << "�޷����ļ�game.dat" << endl;
        return FAIL_OPEN;
    }

    info player;
    gfile.read((char*)&player, sizeof(player));

    while (1)
    {
        PrintInfo(player);
        char choice;
#ifdef _WIN32
        choice = _getche();
#endif
#ifdef __linux__
        choice = getchar();
#endif
        if ((choice >= 'a' && choice <= 'y') || choice == '0' || choice == '1')
            ;
        else
        {
            cout << endl;
            continue;
        }
        if (choice == 'a')
        {
            cout << endl;
            cout << "����ǳƣ���ǰֵ=" << player.name << "�������� : ";
            cin >> player.name;
            player.name[15] = '\0';
        }
        else if (choice == 'b')
        {
            
            while (1)
            {
                cout << endl;
                cout << "��������ǰֵ=" << player.life << "����Χ[0..10000]�������� : ";
                short life;
                cin >> life;
                if (cin.good())
                {
                    if (life >= 0 && life <= 10000)
                    {
                        player.life = life;
                        break;
                    }
                    else
                        cout << "�Ƿ�������ֵ��" << life << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'c')
        {
            
            while(1)
            { 
                cout << endl;
                cout << "��������ǰֵ=" << player.strength << "����Χ[0..10000]�������� : ";
                short s;
                cin >> s;
                if (cin.good() )
                {
                    if (s >= 0 && s <= 10000)
                    {
                        player.strength = s;
                        break;
                    }
                    else
                        cout << "�Ƿ�������ֵ��" << s << endl;
                } 
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
            
        }
        else if (choice == 'd')
        {
            
            while (1)
            {
                cout << endl;
                cout << "���ʣ���ǰֵ=" << player.health << "����Χ[0..8192]�������� : ";
                short s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 8192)
                    {
                        player.health = s;
                        break;
                    }
                    else
                        cout << "�Ƿ�������ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'e')
        {
            
            while (1)
            {
                cout << endl;
                cout << "���ɣ���ǰֵ=" << player.deft << "����Χ[0..1024]�������� : ";
                short s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 1024)
                    {
                        player.deft = s;
                        break;
                    }
                    else
                        cout << "�Ƿ�������ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'f')
        {
            
            while (1)
            {
                cout << endl;
                cout << "��Ǯ����ǰֵ=" << player.money << "����Χ[0..100000000]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100000000)
                    {
                        player.money = s;
                        break;
                    }
                    else
                        cout << "�Ƿ��Ľ�Ǯֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'g')
        {
            
            while (1)
            {
                cout << endl;
                cout << "��������ǰֵ=" << player.fame << "����Χ[0..1000000]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 1000000)
                    {
                        player.fame = s;
                        break;
                    }
                    else
                        cout << "�Ƿ�������ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'h')
        {
            
            while (1)
            {
                cout << endl;
                cout << "��������ǰֵ=" << player.charm << "����Χ[0..1000000]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 1000000)
                    {
                        player.charm = s;
                        break;
                    }
                    else
                        cout << "�Ƿ�������ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'i')
        {
            
            while (1)
            {
                cout << endl;
                cout << "��Ϸ�ۼ�ʱ�䣬��ǰֵ=" << TransferTime(player.time1, player.time2, player.time3, 
                    player.time4, player.time5, player.time6, player.time7, player.time8) << "����Χ[0..10000000000000000]�������� : ";
                unsigned long long s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 10000000000000000)
                    {
                        RenewTime(s, player.time1, player.time2, player.time3, player.time4, player.time5, player.time6, player.time7, player.time8);
                        break;
                    }
                    else
                        cout << "�Ƿ�����Ϸ�ۼ�ʱ��ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'j')
        {
            
            while (1)
            {
                cout << endl;
                cout << "�ƶ��ٶȣ���ǰֵ=" << (int)(player.move_speed) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.move_speed = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ����ƶ��ٶ�ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'k')
        {
            
            while (1)
            {
                cout << endl;
                cout << "�����ٶȣ���ǰֵ=" << (int)(player.attack_speed) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.attack_speed = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ��Ĺ����ٶ�ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'l')
        {
           
            while (1)
            {
                cout << endl;
                cout << "������Χ����ǰֵ=" << (int)(player.attack_range) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.attack_range = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ��Ĺ�����Χֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'm')
        {
            
            while (1)
            {
                cout << endl;
                cout << "����������ǰֵ=" << player.attack_power << "����Χ[0..2000]�������� : ";
                short s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 2000)
                    {
                        player.attack_power = s;
                        break;
                    }
                    else
                        cout << "�Ƿ��Ĺ�����ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'n')
        {
            
            while (1)
            {
                cout << endl;
                cout << "����������ǰֵ=" << player.defend_power << "����Χ[0..2000]�������� : ";
                short s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 2000)
                    {
                        player.defend_power = s;
                        break;
                    }
                    else
                        cout << "�Ƿ��ķ�����ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'o')
        {
            
            while (1)
            {
                cout << endl;
                cout << "���ݶȣ���ǰֵ=" << (int)(player.agility) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.agility = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ������ݶ�ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'p')
        {
            
            while (1)
            {
                cout << endl;
                cout << "��������ǰֵ=" << (int)(player.intelli) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.intelli = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ�������ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'q')
        {
            
            while (1)
            {
                cout << endl;
                cout << "���飬��ǰֵ=" << (int)(player.exp) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.exp = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ��ľ���ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'r')
        {
            
            while (1)
            {
                cout << endl;
                cout << "�ȼ�����ǰֵ=" << (int)(player.level) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.level = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ��ĵȼ�ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 's')
        {
            
            while (1)
            {
                cout << endl;
                cout << "ħ������ǰֵ=" << player.magic << "����Χ[0..10000]�������� : ";
                short s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 10000)
                    {
                        player.magic = s;
                        break;
                    }
                    else
                        cout << "�Ƿ���ħ��ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 't')
        {
            
            while (1)
            {
                cout << endl;
                cout << "����ħ������ǰֵ=" << (int)(player.consume_magic) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.consume_magic = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ�������ħ��ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'u')
        {
            
            while (1)
            {
                cout << endl;
                cout << "ħ���˺�������ǰֵ=" << (int)(player.magic_hurt) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.magic_hurt = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ���ħ���˺���ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'v')
        {
            
            while (1)
            {
                cout << endl;
                cout << "ħ�������ʣ���ǰֵ=" << (int)(player.hit_rate) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.hit_rate = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ���ħ��������ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'w')
        {
            
            while (1)
            {
                cout << endl;
                cout << "ħ������������ǰֵ=" << (int)(player.magic_defend) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.magic_defend = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ���ħ��������ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'x')
        {
            
            while (1)
            {
                cout << endl;
                cout << "�����ʣ���ǰֵ=" << (int)(player.crit_chance) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.crit_chance = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ��ı�����ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == 'y')
        {
            
            while (1)
            {
                cout << endl;
                cout << "��������ǰֵ=" << (int)(player.endurance) << "����Χ[0..100]�������� : ";
                unsigned int s;
                cin >> s;
                if (cin.good())
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.endurance = (unsigned char)(s);
                        break;
                    }
                    else
                        cout << "�Ƿ�������ֵ��" << s << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
        else if (choice == '0')
        {
            gfile.close();
            return 0;
        }
        else if (choice == '1')
        {
            gfile.seekp(0, ios::beg);
            gfile.write((char*)&player, sizeof(player));
            gfile.close();
            break;
        }
    }

  
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�������������������������ļ���д
***************************************************************************/
int main(int argc, char* argv[])
{
    if (argc >= 2)
    {
        if (strcmp(argv[1], "--read") == 0)
            read();
        else if (strcmp(argv[1], "--modify") == 0)
            modify();
    }
    else
        usage(argv);

    return 0;
}
