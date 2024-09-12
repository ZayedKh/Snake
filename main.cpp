#include <iostream>
#include<unistd.h>
#include <conio.h>

using namespace std;
bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
char border = '#';
char head = 'O';
char tail = 'o';
char fruit = 'F';

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
                cout << head;
            }
            else if (i == fruitY && j == fruitX) // prints the fruit
            {
                cout << fruit;
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << tail;
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
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
    cout << "Score: " << score << endl;
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
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
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

    if (x >= width - 1 || x <= 0 || y >= height || y < 0) // statement to check whether the snake has collided with the wall
    {
        gameOver = true;
        cout << "You died!" << endl;
    }
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
            cout << "You died!" << endl;
        }
    }
    if (x == fruitX && y == fruitY) // statement to check whether the snake has eaten the fruit
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
