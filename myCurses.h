#ifndef MYCURSES_h
#define MYCURSES_H

#include <curses.h>
#include "globalVeriables.h"
class myCurses
{
public:
  static myCurses *getInstance();
  WINDOW *newWindow(int width, int height, int x, int y);
  INPUTS changeStatus(int userInput);
  INPUTS cursorChange(int userInput);
  void updateScreenWithVector(CONTAINER * c);
  void writeChar(const char c);
  void endSession();
  WINDOW *getWindow();
  void setWindow(WINDOW *win);
  int getX();
  int getY();

private:
  static myCurses *m_instance;
  myCurses();
  void initNCurses();
  int m_width, m_height, m_x, m_y;
  WINDOW *m_win;
};


#endif