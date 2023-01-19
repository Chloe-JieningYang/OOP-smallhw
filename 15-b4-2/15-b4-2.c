//2050598 ����� ͨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h>
#endif

//������Ҫ�ɼ�������ͷ�ļ�


//�˴�Ϊʾ���������޸Ľṹ�����ƣ������޸Ľṹ���еĳ�Ա���ݣ�Ҫ��sizeof������64
struct info {
    char name[16];
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
   1�����������ĺ����������������µ� FILE* �����д�/��/д/�رյȲ���
   2����������ͬ��������main����
*/

void usage(char*ch[])
{
    printf("%s%s%s\n", "usage : ", ch[0], " --modify | --read");
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�����pow����
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ���ӡ��Ϣ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void PrintInfo(struct info player)
{
    printf("%s\n", "--------------------------------------");
    printf("%s\n", "  ��Ϸ�浵�ļ��޸Ĺ���");
    printf("%s\n", "--------------------------------------");

    printf("%-16s%s%s%s\n", "  a.����ǳ�", "(", player.name, ")");

    printf("%-16s%s%hd%s\n", "  b.����", "(", player.life, ")");
    printf("%-16s%s%hd%s\n", "  c.����", "(", player.strength, ")");
    printf("%-16s%s%hd%s\n", "  d.����", "(", player.health, ")");
    printf("%-16s%s%hd%s\n", "  e.����", "(", player.deft, ")");

    printf("%-16s%s%u%s\n", "  f.��Ǯ", "(", player.money, ")");
    printf("%-16s%s%u%s\n", "  g.����", "(", player.fame, ")");
    printf("%-16s%s%u%s\n", "  h.����", "(", player.charm, ")");

    printf("%-16s%s%llu%s\n", "  i.��Ϸ�ۼ�ʱ��", "(", TransferTime(player.time1, player.time2, player.time3, player.time4,
        player.time5, player.time6, player.time7, player.time8), ")");

    printf("%-16s%s%d%s\n", "  j.�ƶ��ٶ�", "(", (int)(player.move_speed), ")");
    printf("%-16s%s%d%s\n", "  k.�����ٶ�", "(", (int)(player.attack_speed), ")");
    printf("%-16s%s%d%s\n", "  l.������Χ", "(", (int)(player.attack_range), ")");

    printf("%-16s%s%hd%s\n", "  m.������", "(", player.attack_power, ")");
    printf("%-16s%s%hd%s\n", "  n.������", "(", player.defend_power, ")");

    printf("%-16s%s%d%s\n", "  o.���ݶ�", "(", (int)(player.agility), ")");
    printf("%-16s%s%d%s\n", "  p.����", "(", (int)(player.intelli), ")");
    printf("%-16s%s%d%s\n", "  q.����", "(", (int)(player.exp), ")");
    printf("%-16s%s%d%s\n", "  r.�ȼ�", "(", (int)(player.level), ")");

    printf("%-16s%s%hd%s\n", "  s.ħ��ֵ", "(", player.magic, ")");

    printf("%-16s%s%d%s\n", "  t.����ħ��ֵ", "(", (int)(player.consume_magic), ")");
    printf("%-16s%s%d%s\n", "  u.ħ���˺���", "(", (int)(player.magic_hurt), ")");
    printf("%-16s%s%d%s\n", "  v.ħ��������", "(", (int)(player.hit_rate), ")");
    printf("%-16s%s%d%s\n", "  w.ħ��������", "(", (int)(player.magic_defend), ")");
    printf("%-16s%s%d%s\n", "  x.������", "(", (int)(player.crit_chance), ")");
    printf("%-16s%s%d%s\n", "  y.����", "(", (int)(player.endurance), ")");

    printf("%s\n", "--------------------------------------");
    printf("%s\n", "  0.�����޸�");
    printf("%s\n", "  1.�����˳�");
    printf("%s\n", "--------------------------------------");
    printf("%s", "��ѡ��[a..y, 0..1] ");
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ��������������ֻ�������һ��fopen��һ��fread����Ϊ����������������fclose��
***************************************************************************/
int read()
{
    /* ��������ֻ������һ�� FILE* */
    FILE *fp;

    /* �ļ��򿪣�����Ҫ��Ϊ��
       1��Ҫ���Զ���ʽ�򿪣��򿪷�ʽ***����ָ��
       2��������fopen�⣬�����������ط��������ٳ���fopen/freopen  */
    fp = fopen("game.dat", "rb");

    /* ���к����������������������ļ�����ʾ����Ϸ���ֵ���ر��ļ��ȣ�������ú���
       ���У�ֻ������һ���Զ�ȡ64�ֽڵķ�����game.dat�����ݶ���***�����������ơ��ṹ����������ָ����
                 fread(***, 1, sizeof(demo), fp);
    */
    if (fp == NULL)
    {
        printf("�޷����ļ�game.dat\n");
        return 0;
    }
    
    struct info player;

    fread((char*)&player, 1, sizeof(player), fp);

    printf("%20s%s\n", "����ǳƣ�", player.name);
    printf("%20s%hd\n", "����ֵ��", player.life);
    printf("%20s%hd\n", "����ֵ��", player.strength);
    printf("%20s%hd\n", "����ֵ��", player.health);
    printf("%20s%hd\n", "����ֵ��", player.deft);

    printf("%20s%u\n", "��Ǯֵ��", player.money);
    printf("%20s%u\n", "����ֵ��", player.fame);
    printf("%20s%u\n", "����ֵ��", player.charm);

    printf("%20s%llu\n", "��Ϸ�ۼ�ʱ��(us)ֵ��", TransferTime(player.time1, player.time2, player.time3,
        player.time4, player.time5, player.time6, player.time7, player.time8));

    printf("%20s%d\n", "�ƶ��ٶ�ֵ��", (int)(player.move_speed));
    printf("%20s%d\n", "�����ٶ�ֵ��", (int)(player.attack_speed));
    printf("%20s%d\n", "������Χֵ��", (int)(player.attack_range));

    printf("%20s%hd\n", "������ֵ��", player.attack_power);
    printf("%20s%hd\n", "������ֵ��", player.defend_power);

    printf("%20s%d\n", "���ݶ�ֵ��", (int)(player.agility));
    printf("%20s%d\n", "����ֵ��", (int)(player.intelli));
    printf("%20s%d\n", "����ֵ��", (int)(player.exp));
    printf("%20s%d\n", "�ȼ�ֵ��", (int)(player.level));

    printf("%20s%hd\n", "ħ��ֵ��", player.magic);

    printf("%20s%d\n", "����ħ��ֵ��", (int)(player.consume_magic));
    printf("%20s%d\n", "ħ���˺���ֵ��", (int)(player.magic_hurt));
    printf("%20s%d\n", "������ֵ��", (int)(player.hit_rate));
    printf("%20s%d\n", "ħ��������ֵ��", (int)(player.magic_defend));
    printf("%20s%d\n", "������ֵ��", (int)(player.crit_chance));
    printf("%20s%d\n", "����ֵ��", (int)(player.endurance));

    fclose(fp);

    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ��������������ֻ�������һ��open��һ��read��һ��write����Ϊ����������������fclose��
***************************************************************************/
int modify()
{
    /* ��������ֻ������һ�� FILE* */
    FILE *fp;

    /* �ļ��򿪣�����Ҫ��Ϊ��
       1��Ҫ���Զ�д��ʽ�򿪣��򿪷�ʽ***����ָ��
       2��������fopen�⣬�����������ط��������ٳ���fopen/freopen  */
    fp = fopen("game.dat", "rb+");

    /* ���к����������������������ļ�����ʾ����Ϸ���ֵ���ر��ļ��ȣ�������ú���
       ���У�ֻ������һ���Զ�ȡ64�ֽڵķ�����game.dat�����ݶ���***�����������ơ��ṹ����������ָ����
                 fread(***, 1, sizeof(struct demo), fp);
             ֻ������һ����д��64�ֽڵķ�����***������д��game.dat�У����������ơ��ṹ����������ָ����
                 fwrite(***, 1, sizeof(struct demo), fp);
    */
    if (fp == NULL)
    {
        printf("�޷����ļ�game.dat\n");
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
            printf("%s%s%s", "����ǳƣ���ǰֵ=", player.name, "�������� : ");
            scanf("%s", player.name);
            player.name[15] = '\0';
        }
        else if (choice == 'b')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "��������ǰֵ = ", player.life, "����Χ[0..10000]�������� : ");
                short life;
                if (scanf("%hd", &life) == 1)
                {
                    if (life >= 0 && life <= 10000)
                    {
                        player.life = life;
                        break;
                    }
                    else
                        printf("%s%hd\n", "�Ƿ�������ֵ��", life);
                }
                
            }
        }
        else if (choice == 'c')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "��������ǰֵ=", player.strength, "����Χ[0..10000]�������� : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 10000)
                    {
                        player.strength = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "�Ƿ�������ֵ��", s);
                }

            }
        }
        else if (choice == 'd')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "���ʣ���ǰֵ=", player.health, "����Χ[0..8192]�������� : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 8192)
                    {
                        player.health = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "�Ƿ�������ֵ��", s);
                }

            }
        }
        else if (choice == 'e')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "���ɣ���ǰֵ=", player.deft, "����Χ[0..1024]�������� : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 1024)
                    {
                        player.deft = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "�Ƿ�������ֵ��", s);
                }

            }
        }
        else if (choice == 'f')
        {
            printf("\n");
            while (1)
            {
                printf("%s%u%s", "��Ǯ����ǰֵ=", player.money, "����Χ[0..100000000]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100000000)
                    {
                        player.money = s;
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ��Ľ�Ǯֵ��", s);
                }
            }
        }
        else if (choice == 'g')
        {
            printf("\n");
            while (1)
            {
                printf("%s%u%s", "��������ǰֵ=", player.fame, "����Χ[0..1000000]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 1000000)
                    {
                        player.fame = s;
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ�������ֵ��", s);
                }
            }
        }
        else if (choice == 'h')
        {
            printf("\n");
            while (1)
            {
                printf("%s%u%s", "��������ǰֵ=", player.charm, "����Χ[0..1000000]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 1000000)
                    {
                        player.charm = s;
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ�������ֵ��", s);
                }
            }
        }
        else if (choice == 'i')
        {
            printf("\n");
            while (1)
            {
                printf("%s%llu%s", "��Ϸ�ۼ�ʱ�䣬��ǰֵ=", TransferTime(player.time1, player.time2, player.time3,
                    player.time4, player.time5, player.time6, player.time7, player.time8), "����Χ[0..10000000000000000]�������� : ");
                unsigned long long s;
                if (scanf("%llu", &s) == 1)
                {
                    if (s >= 0 && s <= 10000000000000000)
                    {
                        RenewTime(s, &player.time1, &player.time2, &player.time3, &player.time4, &player.time5, &player.time6, &player.time7, &player.time8);
                        break;
                    }
                    else
                        printf("%s%llu\n", "�Ƿ�����Ϸ�ۼ�ʱ��ֵ��", s);
                }
            }
        }
        else if (choice == 'j')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "�ƶ��ٶȣ���ǰֵ=", (int)(player.move_speed), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.move_speed = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ����ƶ��ٶ�ֵ��", s);
                }
            }
        }
        else if (choice == 'k')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "�����ٶȣ���ǰֵ=", (int)(player.attack_speed), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.attack_speed = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ��Ĺ����ٶ�ֵ��", s);
                }
            }
        }
        else if (choice == 'l')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "������Χ����ǰֵ=", (int)(player.attack_range), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.attack_range = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ��Ĺ�����Χֵ��", s);
                }
            }
        }
        else if (choice == 'm')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "����������ǰֵ=", player.attack_power, "����Χ[0..2000]�������� : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 2000)
                    {
                        player.attack_power = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "�Ƿ��Ĺ�����ֵ��", s);
                }

            }
        }
        else if (choice == 'n')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "����������ǰֵ=", player.defend_power, "����Χ[0..2000]�������� : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 2000)
                    {
                        player.defend_power = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "�Ƿ��ķ�����ֵ��", s);
                }
            }
        }
        else if (choice == 'o')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "���ݶȣ���ǰֵ=", (int)(player.agility), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.agility = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ������ݶ�ֵ��", s);
                }
            }
        }
        else if (choice == 'p')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "��������ǰֵ=", (int)(player.intelli), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.intelli = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ�������ֵ��", s);
                }
            }
        }
        else if (choice == 'q')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "���飬��ǰֵ=", (int)(player.exp), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.exp = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ��ľ���ֵ��", s);
                }
            }
        }
        else if (choice == 'r')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "�ȼ�����ǰֵ=", (int)(player.level), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.level = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ��ĵȼ�ֵ��", s);
                }
            }
        }
        else if (choice == 's')
        {
            printf("\n");
            while (1)
            {
                printf("%s%hd%s", "ħ������ǰֵ=", player.magic, "����Χ[0..10000]�������� : ");
                short s;
                if (scanf("%hd", &s) == 1)
                {
                    if (s >= 0 && s <= 10000)
                    {
                        player.magic = s;
                        break;
                    }
                    else
                        printf("%s%hd\n", "�Ƿ���ħ��ֵ��", s);
                }
            }
        }
        else if (choice == 't')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "����ħ������ǰֵ=", (int)(player.consume_magic), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.consume_magic = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ�������ħ��ֵ��", s);
                }
            }
        }
        else if (choice == 'u')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "ħ���˺�������ǰֵ=", (int)(player.magic_hurt), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.magic_hurt = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ���ħ���˺���ֵ��", s);
                }
            }
        }
        else if (choice == 'v')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "ħ�������ʣ���ǰֵ=", (int)(player.hit_rate), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.hit_rate = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ���ħ��������ֵ��", s);
                }
            }
        }
        else if (choice == 'w')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "ħ������������ǰֵ=", (int)(player.magic_defend), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.magic_defend = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ���ħ��������ֵ��", s);
                }
            }
        }
        else if (choice == 'x')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "�����ʣ���ǰֵ=", (int)(player.crit_chance), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.crit_chance = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ��ı�����ֵ��", s);
                }
            }
        }
        else if (choice == 'y')
        {
            printf("\n");
            while (1)
            {
                printf("%s%d%s", "��������ǰֵ=", (int)(player.endurance), "����Χ[0..100]�������� : ");
                unsigned int s;
                if (scanf("%u", &s) == 1)
                {
                    if (s >= 0 && s <= 100)
                    {
                        player.endurance = (unsigned char)(s);
                        break;
                    }
                    else
                        printf("%s%u\n", "�Ƿ�������ֵ��", s);
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
