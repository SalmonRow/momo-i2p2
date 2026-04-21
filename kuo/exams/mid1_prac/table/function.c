#include "function.h"
#include <stdlib.h>

Table *createTable()
{
    Table *t = malloc(sizeof(Table));
    scanf("%d", &t->tableSize);
    t->guest = NULL;
    t->leaveTime = 0;
    return t;
}

Guest *createGuest()
{
    Guest *g = malloc(sizeof(Guest));
    g->guestName = malloc(11);
    scanf("%s %d %d %d", g->guestName, &g->groupSize, &g->arriveTime, &g->diningTime);
    return g;
}

Guest *checkLeave(Table **table, int tableCount, int currentTime)
{
    for (int i = 0; i < tableCount; i++)
    {
        if (table[i]->leaveTime == currentTime && table[i]->guest != NULL)
        {
            Guest *temp = table[i]->guest;
            table[i]->guest = NULL;
            return temp;
        }
    }
    return NULL;
}

int assignTable(Table **table, int tableCount, int currentTime, Guest *guest)
{
    for (int i = 0; i < tableCount; i++)
    {
        if (table[i]->tableSize >= guest->groupSize && table[i]->guest == NULL)
        {
            table[i]->guest = guest;
            table[i]->leaveTime = currentTime + guest->diningTime;
            return 1;
        }
    }
    return 0;
}
