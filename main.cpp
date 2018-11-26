#include <iostream>
#include <fstream>
#include <vector>
#include "myCurses.h"
#include "gameOfLife.h"

using namespace std;

int width = 70;
int height = 30;
int x = 1, y = 1;

CONTAINER gameVector(height - 2, vector<int>(width - 2, 0));

int main(int argc, char const *argv[])
{
    myCurses *c = myCurses::getInstance();
    gameOfLife *g = new gameOfLife();
    WINDOW *win = c->newWindow(width, height, y + 1, x);

    c->setWindow(win);

    ofstream myfile;
    myfile.open("gameOfLife.txt");
    while (true)
    {
        const int userInput = getch();

        INPUTS input = c->changeStatus(userInput);
        if (input == INPUTS::ARROW_KEYS)
        {
            c->cursorChange(userInput);
        }
        else if (input == INPUTS::BACKSPACE)
        {
            c->endSession();
            return 0;
        }
        else if (input == INPUTS::CHARACTER)
        {
            gameVector[c->getY() - 1][c->getX() - 1] = 1;
            c->writeChar(userInput);
        }
        else if (input == INPUTS::EXECUTE)
        {
            for (int i = 0; i < gameVector.size(); i++)
            {
                for (int j = 0; j < gameVector[i].size(); j++)
                {
                    myfile << gameVector[i][j] << " ";
                }
                myfile << "\n";
            }
            auto res = g->execute(&gameVector);
            c->updateScreenWithVector(&gameVector);
        }
        wrefresh(win);
    }
    myfile.close();
    return 0;
}
