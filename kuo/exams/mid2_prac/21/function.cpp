#include "function.h"
#include <iostream>
using namespace std;

/* THE GUEST SIDE*/
Guest::Guest()
{
    name = "";
    money = 0;
    skill = 0;
}
Guest::Guest(string s, int m, int ski)
{
    name = s;
    money = m;
    skill = ski;
}
Guest::~Guest()
{
    // it auto clears ?
}
string Guest::get_name()
{
    return this->name;
}
int Guest::get_money()
{
    return this->money;
}
int Guest::get_skill()
{
    return this->skill;
}
void Guest::Win(int m)
{
    this->money += m;
}

/* THE CASINO SIDE */
Casino::Casino()
{
    fee = 0;
    guest_num = 0;
    income = 0;
    list_num = 0;
}
Casino::~Casino()
{
    // nothing again...
}
void Casino::Enterance(int f)
{
    fee = f;
}
void Casino::GuestEnter(string s, int m, int ski)
{
    // bouncer
    for (int i = 0; i < guest_num; i++)
    {
        if (guest[i]->get_name() == s)
            return;
    }
    for (int i = 0; i < list_num; i++)
    {
        if (blacklist[i] == s)
            return;
    }

    // cashier
    if (fee >= m)
    {
        blacklist[list_num++] = s;
        income += m;
        return;
    }

    m -= fee;
    income += fee;
    guest[guest_num++] = new Guest(s, m, ski);
}
void Casino::Win(string s, int m)
{
    for (int i = 0; i < guest_num; i++)
    {
        if (guest[i]->get_name() == s)
        {
            if (m < 0 && guest[i]->get_money() + m <= 0)
            {
                income += guest[i]->get_money();
                blacklist[list_num++] = guest[i]->get_name();

                delete guest[i];
                guest_num--;

                for (int j = i; j < guest_num; j++)
                {
                    guest[j] = guest[j + 1];
                }
            }
            else
            {
                income -= m;
                guest[i]->Win(m);

                if (m > 2 * guest[i]->get_skill())
                {
                    blacklist[list_num++] = guest[i]->get_name();
                    delete guest[i];
                    guest_num--;

                    for (int j = i; j < guest_num; j++)
                    {
                        guest[j] = guest[j + 1];
                    }
                }
            }
            break;
        }
    }
}
void Casino::EndDay()
{
    for (int i = 0; i < guest_num; i++)
    {
        delete guest[i];
    }
    guest_num = 0;
}
void Casino::Result()
{
    cout << this->income << endl;
    for (int i = 0; i < list_num; i++)
    {
        cout << blacklist[i] << endl;
    }
}