#include <iostream>
//#include <Windows.h>
#include <ncurses.h>
#include <time.h>

void mainland_generation(char mainland[50][50])
{
    int x, y,direction, maxlandsize;
    bool da;
    x = rand() % 49;
    y = rand() % 49;

    mainland[x][y] = '#';
    maxlandsize = 200 + rand() % 500;
        for (int i = 0; i < maxlandsize; i++)
        {

            da = true;
            direction = 1 + rand() % 8;
            switch (direction)
            {
            case 1: x++; break;
            case 2: y++; break;
            case 3: y--; break;
            case 4: x--; break;
            case 5: x--; y++; break;
            case 6: x++; y++; break;
            case 7: x++; y--; break;
            case 8: x--; y--; break;
            }
            if (mainland[x][y] == '*' || mainland[x][y] == '#')
            {
                da = false;
                i--;
            }
            if (da == true)
            {
                mainland[x][y] = '#';
            }
        }

}

void build(char mainland[50][50])
{
    for (int x = 0; x < 50; x++)
    {
        for (int y = 0; y < 50; y++)
        {
            mainland[x][y] = ' ';
            mainland[x][0] = '*';
            mainland[0][y] = '*';
            mainland[49][y] = '*';
            mainland[x][49] = '*';

        }
    }
}

void print(char mainland[50][50])
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            std::cout << mainland[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main()
{
    char mainland[50][50];
    while (1)
    {
        system("cls");
        srand(time(NULL));
        build(mainland);
        mainland_generation(mainland);
        print(mainland);
        getch();
    }

    return 0;
    
}
