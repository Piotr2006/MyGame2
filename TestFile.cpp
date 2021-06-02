#include "TXLib.h"

int GetNumberOfSymbols (const char str[], const char Symbol);

int GetNumberOfStr (const char Allstr[], const char Smallstr [2]);

int Myfscanf (FILE* file, const char str [], ...);

int main ()
    {
    // FILE* file = stdin;

    int x = 1;
    // int y = 0;

    int nParams = Myfscanf (stdin, " Man->Point.x = %d %%", &x);

    printf ("x = %d%%, Myfscanf = %d \n", x, nParams);

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

int GetNumberOfStr (const char Allstr[], const char Smallstr [2])
    {
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
