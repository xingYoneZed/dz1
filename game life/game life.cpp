#include <iostream>             // Header Files
#include  <conio.h>
#include   <cstdlib>
#include   <windows.h>
#include  <time.h>


using namespace std;


void gotoxy(int x, int y)
{
    COORD coordinates;    
    coordinates.X = x;     
    coordinates.Y = y;     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}


int main()
{
    int i, j, data[83][60], nextarray[83][60];
    int around;
    srand(time(NULL));

    for (i = 0; i <= 79; i++)
        for (j = 0; j <= 56; j++)
        {
            data[i][j] = 0;

            if (i > 1 && i < 78 && j>1 && j < 55)
                if (rand() % 10 == 1)
                {
                    data[i][j] = 1;
                }
        }

    while (1)
    {

        for (i = 2; i <= 77; i++)
            for (j = 2; j <= 54; j++)
            {
                gotoxy(i, j);
                if (data[i][j]) cout << "\2"; else cout << " ";

            }


        for (i = 2; i <= 77; i++)
            for (j = 2; j <= 54; j++)
            {

                nextarray[i][j] = data[i][j];
                around = data[i - 1][j - 1] + data[i][j - 1] + data[i + 1][j - 1] + data[i - 1][j] + data[i + 1][j] + data[i - 1][j + 1] + data[i][j + 1] + data[i + 1][j + 1];
                if (data[i][j] == 1)
                {
                    if (around < 2 || around>3) nextarray[i][j] = 0; else nextarray[i][j] = 1;


                }
                else
                {
                    if (around == 3) nextarray[i][j] = 1;
                }

            }

        for (i = 2; i <= 77; i++)
            for (j = 2; j <= 54; j++)
                data[i][j] = nextarray[i][j];

        Sleep(100);


    }






    return 0;
}