#include <vector>
#include "myCurses.h"
#include "gameOfLife.h"
#include <unistd.h>
using namespace std;

int width = 70;
int height = 28;
int x = 1, y = 1;

bool isExecuted = false;
CONTAINER gameVector(height - 2, vector<bool>(width - 2, 0));

int main(int argc, char const *argv[])
{
    myCurses *c = myCurses::getInstance();
    gameOfLife *g = new gameOfLife();
    WINDOW *win = c->newWindow(width, height, y + 3, x + 2);

    c->setWindow(win);

    //ofstream myfile;
    //myfile.open("gameOfLife.txt");
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
            while (true)
            {
                gameVector = g->execute(&gameVector);
                c->updateScreenWithVector(&gameVector);
                isExecuted = true;
                usleep(250000);
            }
        }
        wrefresh(win);
    }
    return 0;
}
