//2050598 杨洁宁 通信
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#ifdef  _WIN32
#include <conio.h>
#endif
//根据需要可加入其它头文件
using namespace std;

#define FAIL_OPEN   -1

//此处为示例，允许修改结构体名称，允许修改结构体中的成员内容，要求sizeof必须是64
struct info {
    char name[16] = { '\0' };
    short life;
    short strength;
    short health;//体质
    short deft;//灵巧
    unsigned int money;
    unsigned int fame;//名声
    unsigned int charm;//魅力
    unsigned char time1;//游戏时间的最低位
    unsigned char time2;
    unsigned char time3;
    unsigned char time4;
    unsigned char time5;
    unsigned char time6;
    unsigned char time7;
    unsigned char time8;//游戏时间最高位
    unsigned char move_speed;//移动速度
    unsigned char attack_speed;//攻击速度
    unsigned char attack_range;//攻击范围
    unsigned char vac;//预留值
    short attack_power;//攻击力
    short defend_power;//防御力
    unsigned char agility;//敏捷度
    unsigned char intelli;//智力
    unsigned char exp;//经验
    unsigned char level;//等级
    short magic;//魔法值
    unsigned char consume_magic;//每次消耗的魔法
    unsigned char magic_hurt;//魔法伤害力
    unsigned char hit_rate;//命中率
    unsigned char magic_defend;//魔法防御力
    unsigned char crit_chance;//暴击率
    unsigned char endurance;//耐力
};


/* 此处允许新增函数，数量不限
   1、所有新增的函数，均不允许定义新的 fstream / ifstream / ofstream 流对象，并进行打开/读/写/关闭等操作
   2、所有新增的函数，均不允许用C方式进行文件处理
   3、上述两个限制同样适用于main函数
*/

void usage(char* ch[])
{
    cout << "usage : " << ch[0] << " --modify | --read" << endl;
}

/***************************************************************************
  函数名称：
  功    能：代替pow函数
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：将8个char 型转成1个unsigned long long 型
  输入参数：char 从最低位到最高位
  返 回 值：
  说    明：
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
  函数名称：
  功    能：将一个long long转成8个char
  输入参数：char 从最低位到最高位
  返 回 值：
  说    明：
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
  函数名称：
  功    能：打印info所有信息
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void PrintInfo(info player)
{
    cout << "--------------------------------------" << endl;
    cout << "  游戏存档文件修改工具" << endl;
    cout << "--------------------------------------" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  a.玩家昵称" << "(" << player.name << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  b.生命" << "(" << player.life << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  c.力量" << "(" << player.strength << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  d.体质" << "(" << player.health << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  e.灵巧" << "(" << player.deft << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  f.金钱" << "(" << player.money << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  g.名声" << "(" << player.fame << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  h.魅力" << "(" << player.charm << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  i.游戏累计时间" << "(" << TransferTime(player.time1, player.time2, player.time3, player.time4,
        player.time5, player.time6, player.time7, player.time8) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  j.移动速度" << "(" << (int)(player.move_speed) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  k.攻击速度" << "(" << (int)(player.attack_speed) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  l.攻击范围" << "(" << (int)(player.attack_range) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  m.攻击力" << "(" << player.attack_power << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  n.防御力" << "(" << player.defend_power << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  o.敏捷度" << "(" << (int)(player.agility) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  p.智力" << "(" << (int)(player.intelli) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  q.经验" << "(" << (int)(player.exp) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  r.等级" << "(" << (int)(player.level) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  s.魔法值" << "(" << player.magic << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  t.消耗魔法值" << "(" << (int)(player.consume_magic) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  u.魔法伤害力" << "(" << (int)(player.magic_hurt) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  v.魔法命中率" << "(" << (int)(player.hit_rate) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  w.魔法防御力" << "(" << (int)(player.magic_defend) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  x.暴击率" << "(" << (int)(player.crit_chance) << ")" << endl;
    cout << setiosflags(ios::left) << setw(16) << "  y.耐力" << "(" << (int)(player.endurance) << ")" << endl;

    cout << "--------------------------------------" << endl;
    cout << "  0.放弃修改" << endl;
    cout << "  1.存盘退出" << endl;
    cout << "--------------------------------------" << endl;
    cout << "请选择[a..y, 0..1] ";

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read（因为包含错误处理，允许多次close）
***************************************************************************/
int read()
{
    /* 本函数中只允许定义一个 ifstream流对象，不再允许定义任何形式的fstream/ifstream/ofstream流对象，也不允许使用C方式的文件处理 */
    ifstream gfile;

    /* 文件打开，具体要求为：
       1、要求以读方式打开，打开方式***自行指定
       2、除本次open外，本函数其它地方不允许再出现open  */
    gfile.open("game.dat", ios::in | ios::binary);

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 gfile.read(***, sizeof(demo));
    */
    if (gfile.is_open() == 0)
    {
        cout << "无法打开文件game.dat" << endl;
        return FAIL_OPEN;
    }
    info player;
    gfile.read((char*)&player, sizeof(player));

    cout << setw(20) << "玩家昵称：" << player.name << endl;
    cout << setw(20) << "生命值：" << player.life << endl;
    cout << setw(20) << "力量值：" << player.strength << endl;
    cout << setw(20) << "体质值：" << player.health << endl;
    cout << setw(20) << "灵巧值：" << player.deft << endl;
    cout << setw(20) << "金钱值：" << player.money << endl;
    cout << setw(20) << "名声值：" << player.fame << endl;
    cout << setw(20) << "魅力值：" << player.charm << endl;
    cout << setw(20) << "游戏累计时间(us)值：" << TransferTime(player.time1, player.time2, player.time3,
        player.time4, player.time5, player.time6, player.time7, player.time8) << endl; 
    cout << setw(20) << "移动速度值：" << (int)(player.move_speed) << endl;
    cout << setw(20) << "攻击速度值：" << (int)(player.attack_speed) << endl;
    cout << setw(20) << "攻击范围值：" << (int)(player.attack_range) << endl;
    cout << setw(20) << "攻击力值：" << player.attack_power << endl;
    cout << setw(20) << "防御力值：" << player.defend_power << endl;
    cout << setw(20) << "敏捷度值：" << (int)(player.agility) << endl;
    cout << setw(20) << "智力值：" << (int)(player.intelli) << endl;
    cout << setw(20) << "经验值：" << (int)(player.exp) << endl;
    cout << setw(20) << "等级值：" << (int)(player.level) << endl;
    cout << setw(20) << "魔法值：" << player.magic << endl;
    cout << setw(20) << "消耗魔法值：" << (int)(player.consume_magic) << endl;
    cout << setw(20) << "魔法伤害力值：" << (int)(player.magic_hurt) << endl;
    cout << setw(20) << "命中率值：" << (int)(player.hit_rate) << endl;
    cout << setw(20) << "魔法防御力值：" << (int)(player.magic_defend) << endl;
    cout << setw(20) << "暴击率值：" << (int)(player.crit_chance) << endl;
    cout << setw(20) << "耐力值：" << (int)(player.endurance) << endl;

    gfile.close();

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read、一次write（因为包含错误处理，允许多次close）
***************************************************************************/
int modify()
{
    /* 本函数中只允许定义一个 fstream流对象，不再允许定义任何形式的fstream/ifstream/ofstream流对象，也不允许使用C方式的文件处理 */
    fstream gfile;

    /* 文件打开，具体要求为：
       1、要求以读写方式打开，打开方式***自行指定
       2、除本次open外，本函数其它地方不允许再出现open  */
    gfile.open("game.dat", ios::in | ios::out | ios::binary);

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 gfile.read(***, sizeof(demo));
             只允许用一次性写入64字节的方法将***的内容写入game.dat中（缓冲区名称、结构体名称自行指定）
                 gfile.write(***, sizeof(demo));
    */
    if (!gfile.is_open())
    {
        cout << "无法打开文件game.dat" << endl;
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
            cout << "玩家昵称，当前值=" << player.name << "，请输入 : ";
            cin >> player.name;
            player.name[15] = '\0';
        }
        else if (choice == 'b')
        {
            
            while (1)
            {
                cout << endl;
                cout << "生命，当前值=" << player.life << "，范围[0..10000]，请输入 : ";
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
                        cout << "非法的生命值：" << life << endl;
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
                cout << "力量，当前值=" << player.strength << "，范围[0..10000]，请输入 : ";
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
                        cout << "非法的力量值：" << s << endl;
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
                cout << "体质，当前值=" << player.health << "，范围[0..8192]，请输入 : ";
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
                        cout << "非法的体质值：" << s << endl;
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
                cout << "灵巧，当前值=" << player.deft << "，范围[0..1024]，请输入 : ";
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
                        cout << "非法的灵巧值：" << s << endl;
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
                cout << "金钱，当前值=" << player.money << "，范围[0..100000000]，请输入 : ";
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
                        cout << "非法的金钱值：" << s << endl;
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
                cout << "名声，当前值=" << player.fame << "，范围[0..1000000]，请输入 : ";
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
                        cout << "非法的名声值：" << s << endl;
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
                cout << "魅力，当前值=" << player.charm << "，范围[0..1000000]，请输入 : ";
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
                        cout << "非法的魅力值：" << s << endl;
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
                cout << "游戏累计时间，当前值=" << TransferTime(player.time1, player.time2, player.time3, 
                    player.time4, player.time5, player.time6, player.time7, player.time8) << "，范围[0..10000000000000000]，请输入 : ";
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
                        cout << "非法的游戏累计时间值：" << s << endl;
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
                cout << "移动速度，当前值=" << (int)(player.move_speed) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的移动速度值：" << s << endl;
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
                cout << "攻击速度，当前值=" << (int)(player.attack_speed) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的攻击速度值：" << s << endl;
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
                cout << "攻击范围，当前值=" << (int)(player.attack_range) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的攻击范围值：" << s << endl;
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
                cout << "攻击力，当前值=" << player.attack_power << "，范围[0..2000]，请输入 : ";
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
                        cout << "非法的攻击力值：" << s << endl;
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
                cout << "防御力，当前值=" << player.defend_power << "，范围[0..2000]，请输入 : ";
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
                        cout << "非法的防御力值：" << s << endl;
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
                cout << "敏捷度，当前值=" << (int)(player.agility) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的敏捷度值：" << s << endl;
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
                cout << "智力，当前值=" << (int)(player.intelli) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的智力值：" << s << endl;
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
                cout << "经验，当前值=" << (int)(player.exp) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的经验值：" << s << endl;
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
                cout << "等级，当前值=" << (int)(player.level) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的等级值：" << s << endl;
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
                cout << "魔法，当前值=" << player.magic << "，范围[0..10000]，请输入 : ";
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
                        cout << "非法的魔法值：" << s << endl;
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
                cout << "消耗魔法，当前值=" << (int)(player.consume_magic) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的消耗魔法值：" << s << endl;
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
                cout << "魔法伤害力，当前值=" << (int)(player.magic_hurt) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的魔法伤害力值：" << s << endl;
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
                cout << "魔法命中率，当前值=" << (int)(player.hit_rate) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的魔法命中率值：" << s << endl;
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
                cout << "魔法防御力，当前值=" << (int)(player.magic_defend) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的魔法防御力值：" << s << endl;
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
                cout << "暴击率，当前值=" << (int)(player.crit_chance) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的暴击率值：" << s << endl;
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
                cout << "耐力，当前值=" << (int)(player.endurance) << "，范围[0..100]，请输入 : ";
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
                        cout << "非法的耐力值：" << s << endl;
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数允许带参数，不允许进行文件读写
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
