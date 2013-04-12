#include <QtGui/QApplication>
#include "MainWindow.h"

/** @mainpage CSCI 102 PA #4
  @section purpose Purpose/Overview
  The main point of this PA was to create a GUI for the puzzle created in PA #3. 
  This puzzle can be played through and solved by the player,
  but the player can also request a cheat in order to see the moves required to solve it.
  @section requirements Requirements
  I am required to make
  1) A complete GUI with
  	a) a start button
  	b) a quit button
  	c) three lines to allow input
  	d) A scene that shows the GUITiles
  	e) A scene that shows the Cheat + other messages
  	f) A Cheat button that allows for displaying of cheats
  2) The tiles must be animated when they move
  3) There must be a MainWindow class to handle all of this.
  4) There must be a GUITile class that will be moved and animated
  */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
