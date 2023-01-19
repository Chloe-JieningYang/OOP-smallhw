//2050598 杨洁宁 通信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h>
#endif

//根据需要可加入其它头文件


//此处为示例，允许修改结构体名称，允许修改结构体中的成员内容，要求sizeof必须是64
struct info {
    char name[16];
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
   1、所有新增的函数，均不允许定义新的 FILE* 并进行打开/读/写/关闭等操作
   2、上述限制同样适用于main函数
*/

void usage(char*ch[])
{
    printf("%s%s%s\n", "usage : ", ch[0], " --modify | --read");
}
/***************************************************************************
  函数名称：
  功    能：代替pow函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
unsigned long long MyPow(int num, int time)
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
void RenewTime(unsigned long long s, unsigned char* t1, unsigned char* t2, unsigned char* t3, unsigned char* t4, unsigned char* t5, unsigned char* t6, unsigned char* t7, unsigned char* t8)
{
    *t1 = s % 16;
    s /= 16;
    *t1 += s % 16 * 16;
    s /= 16;

    *t2 = s % 16;
    s /= 16;
    *t2 += s % 16 * 16;
    s /= 16;

    *t3 = s % 16;
    s /= 16;
    *t3 += s % 16 * 16;
    s /= 16;

    *t4 = s % 16;
    s /= 16;
    *t4 += s % 16 * 16;
    s /= 16;

    *t5 = s % 16;
    s /= 16;
    *t5 += s % 16 * 16;
    s /= 16;

    *t6 = s % 16;
    s /= 16;
    *t6 += s % 16 * 16;
    s /= 16;

    *t7 = s % 16;
    s /= 16;
    *t7 += s % 16 * 16;
    s /= 16;

    *t8 = s % 16;
    s /= 16;
    *t8 += s % 16 * 16;
}

/***************************************************************************
  函数名称：
  功    能：打印信息
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void PrintInfo(struct info player)
{
    printf("%s\n", "--------------------------------------");
    printf("%s\n", "  游戏存档文件修改工具");
    printf("%s\n", "--------------------------------------");

    printf("%-16s%s%s%s\n", "  a.玩家昵称", "(", player.name, ")");

    printf("%-16s%s%hd%s\n", "  b.生命", "(", player.life, ")");
    printf("%-16s%s%hd%s\n", "  c.力量", "(", player.strength, ")");
    printf("%-16s%s%hd%s\n", "  d.体质", "(", player.health, ")");
    printf("%-16s%s%hd%s\n", "  e.灵巧", "(", player.deft, ")");

    printf("%-16s%s%u%s\n", "  f.金钱", "(", player.money, ")");
    printf("%-16s%s%u%s\n", "  g.名声", "(", player.fame, ")");
    printf("%-16s%s%u%s\n", "  h.魅力", "(", player.charm, ")");

    printf("%-16s%s%llu%s\n", "  i.游戏累计时间", "(", TransferTime(player.time1, player.time2, player.time3, player.time4,
        player.time5, player.time6, player.time7, player.time8), ")");

    printf("%-16s%s%d%s\n", "  j.移动速度", "(", (int)(player.move_speed), ")");
    printf("%-16s%s%d%s\n", "  k.攻击速度", "(", (int)(player.attack_speed), ")");
    printf("%-16s%s%d%s\n", "  l.攻击范围", "(", (int)(player.attack_range), ")");

    printf("%-16s%s%hd%s\n", "  m.攻击力", "(", player.attack_power, ")");
    printf("%-16s%s%hd%s\n", "  n.防御力", "(", player.defend_power, ")");

    printf("%-16s%s%d%s\n", "  o.敏捷度", "(", (int)(player.agility), ")");
    printf("%-16s%s%d%s\n", "  p.智力", "(", (int)(player.intelli), ")");
    printf("%-16s%s%d%s\n", "  q.经验", "(", (int)(player.exp), ")");
    printf("%-16s%s%d%s\n", "  r.等级", "(", (int)(player.level), ")");

    printf("%-16s%s%hd%s\n", "  s.魔法值", "(", player.magic, ")");

    printf("%-16s%s%d%s\n", "  t.消耗魔法值", "(", (int)(player.consume_magic), ")");
    printf("%-16s%s%d%s\n", "  u.魔法伤害力", "(", (int)(player.magic_hurt), ")");
    printf("%-16s%s%d%s\n", "  v.魔法命中率", "(", (int)(player.hit_rate), ")");
    printf("%-16s%s%d%s\n", "  w.魔法防御力", "(", (int)(player.magic_defend), ")");
    printf("%-16s%s%d%s\n", "  x.暴击率", "(", (int)(player.crit_chance), ")");
    printf("%-16s%s%d%s\n", "  y.耐力", "(", (int)(player.endurance), ")");

    printf("%s\n", "--------------------------------------");
    printf("%s\n", "  0.放弃修改");
    printf("%s\n", "  1.存盘退出");
    printf("%s\n", "--------------------------------------");
    printf("%s", "请选择[a..y, 0..1] ");
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次fopen、一次fread（因为包含错误处理，允许多次fclose）
***************************************************************************/
int read()
{
    /* 本函数中只允许定义一个 FILE* */
    FILE *fp;

    /* 文件打开，具体要求为：
       1、要求以读方式打开，打开方式***自行指定
       2、除本次fopen外，本函数其它地方不允许再出现fopen/freopen  */
    fp = fopen("game.dat", "rb");

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 fread(***, 1, sizeof(demo), fp);
    */
    if (fp == NULL)
    {
        printf("无法打开文件game.dat\n");
        return 0;
    }
    
    struct info player;

    fread((char*)&player, 1, sizeof(player), fp);

    printf("%20s%s\n", "玩家昵称：", player.name);
    printf("%20s%hd\n", "生命值：", player.life);
    printf("%20s%hd\n", "力量值：", player.strength);
    printf("%20s%hd\n", "体质值：", player.health);
    printf("%20s%hd\n", "灵巧值：", player.deft);

    printf("%20s%u\n", "金钱值：", player.money);
    printf("%20s%u\n", "名声值：", player.fame);
    printf("%20s%u\n", "魅力值：", player.charm);

    printf("%20s%llu\n", "游戏累计时间(us)值：", TransferTime(player.time1, player.time2, player.time3,
        player.time4, player.time5, player.time6, player.time7, player.time8));

    printf("%20s%d\n", "移动速度值：", (int)(player.move_speed));
    printf("%20s%d\n", "攻击速度值：", (int)(player.attack_speed));
    printf("%20s%d\n", "攻击范围值：", (int)(player.attack_range));

    printf("%20s%hd\n", "攻击力值：", player.attack_power);
    printf("%20s%hd\n", "防御力值：", player.defend_power);

    printf("%20s%d\n", "敏捷度值：", (int)(player.agility));
    printf("%20s%d\n", "智力值：", (int)(player.intelli));
    printf("%20s%d\n", "经验值：", (int)(player.exp));
    printf("%20s%d\n", "等级值：", (int)(player.level));

    printf("%20s%hd\n", "魔法值：", player.magic);

    printf("%20s%d\n", "消耗魔法值：", (int)(player.consume_magic));
    printf("%20s%d\n", "魔法伤害力值：", (int)(player.magic_hurt));
    printf("%20s%d\n", "命中率值：", (int)(player.hit_rate));
    printf("%20s%d\n", "魔法防御力值：", (int)(player.magic_defend));
    printf("%20s%d\n", "暴击率值：", (int)(player.crit_chance));
    printf("%20s%d\n", "耐力值：", (int)(player.endurance));

    fclose(fp);

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read、一次write（因为包含错误处理，允许多次fclose）
***************************************************************************/
int modify()
{
    /* 本函数中只允许定义一个 FILE* */
    FILE *fp;

    /* 文件打开，具体要求为：
       1、要求以读写方式打开，打开方式***自行指定
       2、除本次fopen外，本函数其它地方不允许再出现fopen/freopen  */
    fp = fopen("game.dat", "rb+");

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 fread(***, 1, sizeof(struct demo), fp);
             只允许用一次性写入64字节的方法将***的内容写入game.dat中（缓冲区名称、结构体名称自行指定）
                 fwrite(***, 1, sizeof(struct demo), fp);
    */
    if (fp == NULL)
    {
        printf("无法打开文件game.dat\n");
        return 0;
    }

    struct info player;
    fread((char*)&player, 1, sizeof(player), fp);

    while (1)
    {
        PrintInfo(player);
        char choice;
#ifdef _WIN32
        choice = _getche();
#elif defined __linux__
        choice = getchar();
#endif
        if ((choice >= 'a' && choice <= 'y') || choice == '0' || choice == '1')
            ;
        else
        {
            printf('\n');
            continue;
        }
        if (choice == 'a')
        {
            printf("\n");
            printf("%s%s%s", "玩家昵称，当前值=", player.name, "，请输入 : ");
            scanf("%s", player.name);
            player.name[15] = '\0';
        }
        else if (choice == 'b')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "生命，当前值 = ", player.life, "，范围[0..10000]，请输入 : ");
                short life;
                if (scanf("%hd", &life) == 1)
                {
                    if (life >= 0 && life <= 10000)
                    {
                        player.life = life;
                        break;
                    }
                    else
                        printf("%s%hd\n", "非法的生命值：", life);
                }
                
            }
        }
        else if (choice == 'c')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "力量，当前值=", player.strength, "，范围[0..10000]，请输入 : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 10000)
                    {
                        player.strength = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "非法的力量值：", s);
                }

            }
        }
        else if (choice == 'd')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "体质，当前值=", player.health, "，范围[0..8192]，请输入 : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 8192)
                    {
                        player.health = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "非法的体质值：", s);
                }

            }
        }
        else if (choice == 'e')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "灵巧，当前值=", player.deft, "，范围[0..1024]，请输入 : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 1024)
                    {
                        player.deft = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "非法的灵巧值：", s);
                }

            }
        }
        else if (choice == 'f')
        {
            printf("\n");
            while (1)
            {
                printf("%s%u%s", "金钱，当前值=", player.money, "，范围[0..100000000]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100000000)
                    {
                        player.money = s;
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的金钱值：", s);
                }
            }
        }
        else if (choice == 'g')
        {
            printf("\n");
            while (1)
            {
                printf("%s%u%s", "名声，当前值=", player.fame, "，范围[0..1000000]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 1000000)
                    {
                        player.fame = s;
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的名声值：", s);
                }
            }
        }
        else if (choice == 'h')
        {
            printf("\n");
            while (1)
            {
                printf("%s%u%s", "魅力，当前值=", player.charm, "，范围[0..1000000]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 1000000)
                    {
                        player.charm = s;
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的魅力值：", s);
                }
            }
        }
        else if (choice == 'i')
        {
            printf("\n");
            while (1)
            {
                printf("%s%llu%s", "游戏累计时间，当前值=", TransferTime(player.time1, player.time2, player.time3,
                    player.time4, player.time5, player.time6, player.time7, player.time8), "，范围[0..10000000000000000]，请输入 : ");
                unsigned long long s;
                if (scanf("%llu", &s) == 1)
                {
                    if (s >= 0 && s <= 10000000000000000)
                    {
                        RenewTime(s, &player.time1, &player.time2, &player.time3, &player.time4, &player.time5, &player.time6, &player.time7, &player.time8);
                        break;
                    }
                    else
                        printf("%s%llu\n", "非法的游戏累计时间值：", s);
                }
            }
        }
        else if (choice == 'j')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "移动速度，当前值=", (int)(player.move_speed), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.move_speed = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的移动速度值：", s);
                }
            }
        }
        else if (choice == 'k')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "攻击速度，当前值=", (int)(player.attack_speed), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.attack_speed = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的攻击速度值：", s);
                }
            }
        }
        else if (choice == 'l')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "攻击范围，当前值=", (int)(player.attack_range), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.attack_range = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的攻击范围值：", s);
                }
            }
        }
        else if (choice == 'm')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "攻击力，当前值=", player.attack_power, "，范围[0..2000]，请输入 : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 2000)
                    {
                        player.attack_power = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "非法的攻击力值：", s);
                }

            }
        }
        else if (choice == 'n')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "防御力，当前值=", player.defend_power, "，范围[0..2000]，请输入 : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 2000)
                    {
                        player.defend_power = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "非法的防御力值：", s);
                }
            }
        }
        else if (choice == 'o')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "敏捷度，当前值=", (int)(player.agility), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.agility = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的敏捷度值：", s);
                }
            }
        }
        else if (choice == 'p')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "智力，当前值=", (int)(player.intelli), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.intelli = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的智力值：", s);
                }
            }
        }
        else if (choice == 'q')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "经验，当前值=", (int)(player.exp), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.exp = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的经验值：", s);
                }
            }
        }
        else if (choice == 'r')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "等级，当前值=", (int)(player.level), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.level = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的等级值：", s);
                }
            }
        }
        else if (choice == 's')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "魔法，当前值=", player.magic, "，范围[0..10000]，请输入 : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 10000)
                    {
                        player.magic = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "非法的魔法值：", s);
                }
            }
        }
        else if (choice == 't')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "消耗魔法，当前值=", (int)(player.consume_magic), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.consume_magic = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的消耗魔法值：", s);
                }
            }
        }
        else if (choice == 'u')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "魔法伤害力，当前值=", (int)(player.magic_hurt), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.magic_hurt = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的魔法伤害力值：", s);
                }
            }
        }
        else if (choice == 'v')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "魔法命中率，当前值=", (int)(player.hit_rate), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.hit_rate = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的魔法命中率值：", s);
                }
            }
        }
        else if (choice == 'w')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "魔法防御力，当前值=", (int)(player.magic_defend), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.magic_defend = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的魔法防御力值：", s);
                }
            }
        }
        else if (choice == 'x')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "暴击率，当前值=", (int)(player.crit_chance), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.crit_chance = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的暴击率值：", s);
                }
            }
        }
        else if (choice == 'y')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "耐力，当前值=", (int)(player.endurance), "，范围[0..100]，请输入 : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.endurance = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "非法的耐力值：", s);
                }
            }
        }
        else if (choice == '0')
        {
            fclose(fp);
            return 0;
        }
        else if (choice == '1')
        {
            fseek(fp, 0, SEEK_SET);
            fwrite((char*)&player, 1, sizeof(player), fp);
            fclose(fp);
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
