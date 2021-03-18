#ifndef HELPSYSTEM_H
#define HELPSYSTEM_H

enum HelpSystem
    {
    HelpFallingTree = 0,
    HelpFindStone   = 1,
    HelpCrafting    = 2,
    HelpDestroyTree = 3,
    HelpFindBonfire = 4,
    HelpAddWood     = 5,
    HelpWarmBonfire = 6
    };

struct HelpType
    {
    int Number;

    /* int FallingTree;
    int SmallStone;
    int Crafting;
    int DestroyTree;
    int FindBonFire;
    int AddWodd;
    int FightEnemy;
    int Trading;
    int Boat;
    int Fishing; */
    };

void Helping (HelpType* Help);

#endif
