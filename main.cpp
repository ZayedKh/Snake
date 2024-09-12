#include <iostream>
using namespace std;
bool gameOver;

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
    }


    return 0;
}

void setup()
{
    gameOver = false;
}

void draw()
{
    

}

void input()
{
}

void logic()
{
}
