#include <iostream>
#include<unistd.h>

using namespace std;
bool gameOver;
const int width = 40;
const int height = 20;
int x,y, fruitX, fruitY, score;
char border = '#';
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void setup();
void draw();
void input();
void logic();

int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        logic();
        usleep(300000);
    }


    return 0;
}

void setup()
{
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw()
{
    system("cls"); // clears the screen
    for (int i = 0; i <= width; i++) // draws the top border
    {
        cout << border;
    }

    cout << endl; // moves onto the next line


    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << border;
            }
                cout << " ";

            if (j == width - 2 )
            {
                cout << border;
            }
        }
        cout << endl;
    }

    for (int i = 0; i <= width; i++) // draws the bottom border
    {
        cout << border;
    }
    cout << endl;
}

void input()
{
}

void logic()
{
}
