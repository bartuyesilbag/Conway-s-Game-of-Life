#include "myCurses.h"

myCurses *myCurses::m_instance = NULL;

myCurses::myCurses()
{
    initNCurses();
}
myCurses *myCurses::getInstance()
{
    if (!m_instance)
        m_instance = new myCurses;
    return m_instance;
}

void myCurses::initNCurses()
{
    initscr(); // init library
    cbreak();
    raw();                //
    noecho();             // no echo for getch
    keypad(stdscr, true); //provide special characters like, Backspace, Arrow Keys etc.
    mvaddstr(0, 15, "C++ Implementation of Conway's Game of Life");
    mvaddstr(2, 75, "Rules of Conway's Game of Life");
    mvaddstr(4, 80, "1 - Any live cell with fewer than two live neighbors dies, as if by underpopulation.");
    mvaddstr(6, 80, "2 - Any live cell with two or three live neighbors lives on to the next generation.");
    mvaddstr(8, 80, "3 - Any live cell with more than three live neighbors dies, as if by overpopulation.");
    mvaddstr(10,80, "4 - Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.");


    mvaddstr(12,75, "Go to the top of the cell you want to mark and press 'a' key");
    mvaddstr(13,75, "Press enter to start!");
    mvaddstr(13,75, "Press backspace to exit!");

    refresh();
}

void myCurses::endSession()
{
    endwin();
}

WINDOW *myCurses::getWindow()
{
    return m_win;
}

void myCurses::setWindow(WINDOW *win)
{
    m_win = win;
}

void myCurses::updateScreenWithVector(CONTAINER * c)
{
    //TODO
}
int myCurses::getX()
{
    return m_x;
}

int myCurses::getY()
{
    return m_y;
}

WINDOW *myCurses::newWindow(int width, int height, int x, int y)
{
    m_width = width;
    m_height = height;
    m_y = y;
    m_x = x;
    WINDOW *local_win;

    local_win = newwin(height, width, m_y, m_x);
    box(local_win, 0, 0); /* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines*/
    wmove(local_win, 1, 1);
    wrefresh(local_win); /* Show that box 		*/

    return local_win;
}

INPUTS myCurses::changeStatus(int userInput)
{
    switch (userInput)
    {
    case KEY_UP:
    case KEY_DOWN:
    case KEY_LEFT:
    case KEY_RIGHT:
    {
        return INPUTS::ARROW_KEYS;
    }
    case KEY_BACKSPACE:
    {
        return INPUTS::BACKSPACE;
    }
    case 10:
    {
        return INPUTS::EXECUTE;
    }
    default:
        return INPUTS::CHARACTER;
    }
}
INPUTS myCurses::cursorChange(int userInput)
{

    switch (userInput)
    {
    case KEY_UP:
        m_y = m_y != 1 ? m_y - 1 : m_y;
        //cout << "x : " << x << " y : " << y << endl;
        break;
    case KEY_DOWN:
        m_y = m_y != m_height - 2 ? m_y + 1 : m_y;
        //cout << "x : " << x << " y : " << y << endl;
        break;
    case KEY_LEFT:
        m_x = m_x != 1 ? m_x - 1 : m_x;
        //cout << "x : " << x << " y : " << y << endl;
        break;
    case KEY_RIGHT:
        m_x = m_x != m_width - 2 ? m_x + 1 : m_x;
        //cout << "x : " << x << " y : " << y << endl;
        break;
    default:
        break;
    }
    wmove(m_win, m_y, m_x);
    return INPUTS::ARROW_KEYS;
}

void myCurses::writeChar(const char c)
{
    //mvwaddch(getWindow(), m_y, m_x, ACS_DIAMOND);
    mvwaddch(getWindow(), m_y, m_x, c);
    if (m_x == m_width - 2)
    {
        m_x = 1;
        m_y = m_y + 1;
    }
    else
    {
        m_x = m_x + 1;
    }
    wrefresh(m_win);
}