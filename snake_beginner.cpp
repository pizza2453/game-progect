#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 18;
const int WIN = 15;

int snakeX[324];
int snakeY[324];
int snakeLength;

int appleX;
int appleY;

int direction;
int apples;

bool gameOver;
bool win;

bool snakeHere(int x, int y)
{
    int i = 0;

    while (i < snakeLength)
    {
        if (snakeX[i] == x && snakeY[i] == y)
        {
            return true;
        }

        i++;
    }

    return false;
}

void createApple()
{
    do
    {
        appleX = 1 + rand() % 16;
        appleY = 1 + rand() % 16;
    }
    while (snakeHere(appleX, appleY));
}

void newGame()
{
    snakeLength = 3;

    snakeX[0] = 9;
    snakeY[0] = 9;

    snakeX[1] = 8;
    snakeY[1] = 9;

    snakeX[2] = 7;
    snakeY[2] = 9;

    direction = 3;

    apples = 0;
    gameOver = false;
    win = false;

    createApple();
}

void draw()
{
    system("cls");

    cout << "jabka: " << apples << "/" << WIN << endl;
    cout << "W -wgure | S -wdul | A -lewo | D -prawo | Q -wyjscie" << endl;
    cout << endl;

    int y = 0;

    while (y < SIZE)
    {
        int x = 0;

        while (x < SIZE)
        {
            if (y == 0 || y == SIZE - 1)
            {
                cout << "-";
            }
            else
            {
                if (x == 0 || x == SIZE - 1)
                {
                    cout << "/";
                }
                else
                {
                    if (x == snakeX[0] && y == snakeY[0])
                    {
                        cout << "X";
                    }
                    else
                    {
                        if (x == appleX && y == appleY)
                        {
                            cout << "Z";
                        }
                        else
                        {
                            bool body = false;
                            int i = 1;

                            while (i < snakeLength)
                            {
                                if (x == snakeX[i] && y == snakeY[i])
                                {
                                    body = true;
                                }

                                i++;
                            }

                            if (body)
                            {
                                cout << "C";
                            }
                            else
                            {
                                cout << " ";
                            }
                        }
                    }
                }
            }

            x++;
        }

        cout << endl;
        y++;
    }
}

void input()
{
    if (_kbhit())
    {
        char key = _getch();

        if (key == 'w' || key == 'W')
        {
            if (direction != 1)
            {
                direction = 0;
            }
        }
        else
        {
            if (key == 's' || key == 'S')
            {
                if (direction != 0)
                {
                    direction = 1;
                }
            }
            else
            {
                if (key == 'a' || key == 'A')
                {
                    if (direction != 3)
                    {
                        direction = 2;
                    }
                }
                else
                {
                    if (key == 'd' || key == 'D')
                    {
                        if (direction != 2)
                        {
                            direction = 3;
                        }
                    }
                    else
                    {
                        if (key == 'q' || key == 'Q')
                        {
                            gameOver = true;
                        }
                    }
                }
            }
        }
    }
}

void update()
{
    int newX = snakeX[0];
    int newY = snakeY[0];

    if (direction == 0)
    {
        newY--;
    }
    else
    {
        if (direction == 1)
        {
            newY++;
        }
        else
        {
            if (direction == 2)
            {
                newX--;
            }
            else
            {
                newX++;
            }
        }
    }

        if (newX <= 0 || newX >= SIZE - 1 ||
        newY <= 0 || newY >= SIZE - 1)
    {
        gameOver = true;
    }
    else
    {
        int i = 0;

        while (i < snakeLength)
        {
            if (newX == snakeX[i] && newY == snakeY[i])
            {
                gameOver = true;
            }

            i++;
        }
    }

    if (gameOver == false)
    {
        bool ateApple = false;

        if (newX == appleX && newY == appleY)
        {
            ateApple = true;
        }

                int i = snakeLength;

        if (ateApple)
        {
            snakeLength++;
        }

        while (i > 0)
        {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
            i--;
        }

        snakeX[0] = newX;
        snakeY[0] = newY;

        if (ateApple)
        {
            apples++;

            if (apples >= WIN)
            {
                win = true;
                gameOver = true;
            }
            else
            {
                createApple();
            }
        }
    }
}

void menu()
{
    bool menuEnd = false;

    while (menuEnd == false)
    {
        system("cls");

        cout << "====================" << endl;
        cout << "       SNAKE" << endl;
        cout << "====================" << endl;
        cout << endl;
        cout << "1 - START" << endl;
        cout << "2 - CLOSE" << endl;
        cout << endl;
        cout << "W/S -wybur " << endl;
        cout << "ENTER -podtwierdzenie" << endl;

        char key = _getch();

        if (key == '1')
        {
            menuEnd = true;
        }
        else
        {
            if (key == '2')
            {
                exit(0);
            }
            else
            {
                if (key == 'w' || key == 'W')
                {
                    menuEnd = true;
                }
                else
                {
                    if (key == 's' || key == 'S')
                    {
                        exit(0);
                    }
                    else
                    {
                        if (key == 13)
                        {
                            menuEnd = true;
                        }
                    }
                }
            }
        }
    }
}

void endScreen()
{
    system("cls");

    if (win)
    {
        cout << "====================" << endl;
        cout << "      wygrales      " << endl;
        cout << "====================" << endl;
    else
    {
        cout << "====================" << endl;
        cout << "     pszegrales     " << endl;
        cout << "====================" << endl;
        cout << endl;
    }

    cout << endl;
    cout << "R - nowa gra" << endl;
    cout << "Q - wyjscie" << endl;

    bool end = false;

    while (end == false)
    {
        char key = _getch();

        if (key == 'r' || key == 'R')
        {
            end = true;
        }
        else
        {
            if (key == 'q' || key == 'Q')
            {
                exit(0);
            }
        }
    }
}

int main()
{
    srand((unsigned int)time(0));

    while (true)
    {
        menu();

        newGame();

        while (gameOver == false)
        {
            input();
            update();
            draw();

            Sleep(120);
        }

        endScreen();
    }

    return 0;
}
