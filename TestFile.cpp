#include "TXLib.h"

int GetNumberOfSymbols (const char str[], const char Symbol);

int GetNumberOfStr (const char Allstr[], const char Smallstr [2]);

int Myfscanf (FILE* file, const char str [], ...);

void GetNumberOfStr_Test ();

int NewGetNumberOfStr (const char Allstr[], const char Smallstr []);

int MyStrLen (const char str []);

int main ()
    {
    // FILE* file = stdin;

    /*int x = 1;
    // int y = 0;

    int nParams = Myfscanf (stdin, " Man->Point.x = %d %%", &x);

    printf ("x = %d%%, Myfscanf = %d \n", x, nParams); */

    GetNumberOfStr_Test ();

    // printf ("GetNumberOfStr = %d \n ", GetNumberOfStr ("a = %*", "%*"));

    return 0;
    };

int GetNumberOfSymbols (const char str[], const char Symbol)
    {
    int Number = 0;

    int Position = 0;

    while (str [Position] != 0)
        {
        if (str [Position] == Symbol)
            Number += 1;

        Position += 1;
        };

    return Number;
    };

void GetNumberOfStr_Test ()
    {
     /*   {
        const char str [] = "Man->Point.x = %d %%";
        const char smallstr[] = "%%";

        int result = GetNumberOfStr (str, smallstr);

        if (result != 1)
            printf ("str = '%s', smallstr = '%s', ожидалось 1, получилось %d \n",
                     str, smallstr, result);
        };

        {
        const char str [] = "x = %d, y = %s";
        const char smallstr[] = "%";

        int result = GetNumberOfStr (str, smallstr);

        if (result != 2)
            printf ("str = '%s', smallstr = '%s', ожидалось 2, получилось %d \n",
                     str, smallstr, result);
        }; */

    /* $unittest (GetNumberOfStr ("Man->Point.x = %d %%", "%%"), 1);
    $unittest (GetNumberOfStr ("x = %d, y = %s", "%s"), 1);
    $unittest (GetNumberOfStr ("x = %d, y = %d", "%d"), 2);
    $unittest (GetNumberOfStr ("%", "%%"), 1); */
    $unittest (NewGetNumberOfStr ("Man->Point.x = %d %%", " "), 3);
    $unittest (NewGetNumberOfStr ("%%$ $& %%$", "%%$"), 2);
    $unittest (NewGetNumberOfStr ("% # 2 !%  %", "%"), 3);
    $unittest (NewGetNumberOfStr ("Man->Point.x = %d %%", "%%"), 1);
    $unittest (NewGetNumberOfStr ("%   ", "%%"), 0);

    $unittest (MyStrLen ("%"), 1);
    $unittest (MyStrLen ("% "), 2);
    $unittest (MyStrLen ("%^0"), 3);
    $unittest (MyStrLen ("    "), 4);
    $unittest (MyStrLen ("    &"), 5);
    };

int MyStrLen (const char str [])
    {
    int Length = 0;

    while (str [Length] != 0)
        {
        // printf ("*");

        Length += 1;
        };

    return Length;
    };

int NewGetNumberOfStr (const char Allstr[], const char Smallstr [])
    {
    int Number = 0;

    int Position = 0;

    while (Allstr [Position] != 0)
        {
        // printf ("Position = %d, Allstr [Position] = %c, Smallstr [0] = %c, Smallstr [1] = %c \n", Position, Allstr [Position], Smallstr [0], Smallstr [1]);

        int nMatchingSymbols = 0;

        for (int i = 0; Smallstr [i] != 0 && Allstr [Position + i] != 0; i ++)
            {
            if (Allstr [Position + i] == Smallstr [i])
                nMatchingSymbols += 1;
            };

        if (Smallstr [nMatchingSymbols] == 0)       // "123"
            Number += 1;

        Position += 1;
        };

    return Number;
    };

int GetNumberOfStr (const char Allstr[], const char Smallstr [2])
    {
    // if (MyStrLen (Smallstr) != 2)
    //     TX_ERROR ("неправильная длина маленькой строки! ");

    // assert (MyStrLen (Allstr)   >= 2);
    // assert (MyStrLen (Smallstr) == 2);

    if (MyStrLen (Allstr)   <  2) return -1;
    if (MyStrLen (Smallstr) != 2) return -2;

    int Number = 0;

    int Position = 0;

    while (Allstr [Position] != 0)
        {
        // printf ("Position = %d, Allstr [Position] = %c, Smallstr [0] = %c, Smallstr [1] = %c \n", Position, Allstr [Position], Smallstr [0], Smallstr [1]);

        if (Allstr [Position]     == Smallstr [0] &&
            Allstr [Position + 1] == Smallstr [1])
            Number += 1;

        Position += 1;
        };

    return Number;
    };

int Myfscanf (FILE* file, const char str [], ...)
    {
    va_list Arg {};

    va_start (Arg, str);

    // Man->Point.x = 10%
    // Myfscanf (readingfile, "Man->Point.x = %d %% ", &Man->Point.x);

    // Myfscanf (readingfile, "Man->Point.x = %d %*d ", &Man->Point.x, &Man->Point.y);


    // Myfscanf (readingfile, "Man->Health = %% ", &Man->Health);
    // Myfscanf (readingfile, "Man->Point.y = %d ", &Man->Point.y);

    int nProcents = GetNumberOfStr (str, "% ");
    int nTwoProcents = GetNumberOfStr (str, "%%");
    int nProcentsWithStar = GetNumberOfStr (str, "%*");

    int NumberOfArg = GetNumberOfSymbols (str, '%') - 2 * GetNumberOfStr (str, "%%") -
                                                          GetNumberOfStr (str, "%*");

    printf ("nProcents = %d , nTwoProcents = %d, nProcentsWithStar = %d \n", nProcents, nTwoProcents, nProcentsWithStar);

    int OK = 0;

    int VFSCANF = vfscanf (file, str, Arg);

    printf ("vscanf = %d, NumberOfArg = %d \n", VFSCANF, NumberOfArg);

    if (VFSCANF < NumberOfArg)
        OK = false;
    else
        OK = true;

    va_end (Arg);

    return OK;
    };
