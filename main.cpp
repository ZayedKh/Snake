#include <iostream>
#include<unistd.h>
#include <conio.h>

using namespace std;
bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
char border = '#';

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

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
        usleep(100000); // lets the program sleep for 1 ms
    }


    return 0;
}

void setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
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


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << border;
            }
            if (i == y && j == x) // prints the snake head
            {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX) // prints the fruit
            {
                cout << "F";
            }
            else
            {
                cout << " ";
            }

            if (j == width - 2)
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
    cout << "Score: " <<score << endl;
}

void input()
{
    if (_kbhit()) // checks if keyboard was pressed, returns 1 or 0
    {
        switch (_getch()) // returns ASCII value of the key that was pressed
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width -1 || x <= 0 || y > height || y < 0)
    {
        gameOver = true;
        cout << "You died!" << endl;
    }
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }

}
