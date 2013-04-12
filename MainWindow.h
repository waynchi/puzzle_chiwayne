
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFormLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QLabel>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QIntValidator>
#include <vector>
#include <QLayout>
#include <QLineEdit>
#include <iostream>
#include "GUITile.h"
#include "board.h"
#include <string>
#include <sstream>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsItemGroup>
#include <QString>
#include "puzzle_solver.h"
#include "puzzle_heur.h"
#define WINDOW_MAX_X 200
#define WINDOW_MAX_Y 150

using namespace std;

/** The Class that contains everything required to operate the game
@author Wayne Chi */
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    /** Method that moves the GUITile with animations to the empty place.
    @pre Original Positions
    @post Updated Position
    @param guitile The GUITile that is clicked and supposed to be moved.
    */
    void moveTile(GUITile *guitile);
    /** Method that shows the window */
    void show();

    
private:
    /** Scene of main game. */
    QGraphicsScene *scene;
    /** View of main game. */
    QGraphicsView *view;
    /** Timer to help with animation. */
    QTimer *timer;
    /** The window that contains everything. */
    QWidget *window;
    /** The board that operates behind the GUI. */
    Board *b;
    /** A vector of GUITiles that will be shown in game. */
    vector<GUITile*> tilevector;
    /** A GUITile */
    GUITile *tile;
    /** Size of the Board */
    int size_;
    /** Count for the timer */
    int count;
    /** Used to help handleTimer() decide which direction to move in the X axis*/
    int velocityX;
    /** Used to help handleTimer() decide which direction to move in the Y axis*/
    int velocityY;
    /** Stores the index of the GUITile that is clicked */
    int temp;
    /** Stores the index of the zero tile */
    int tempzero;
    /** Allows input for the size */
    QLineEdit *lineEdit1;
    /** Allows input for the initial randomization value */
    QLineEdit *lineEdit2;
    /** Allows input for the seed */
    QLineEdit *lineEdit3;
    /** The scene for the bottom (A* and other messages) */
    QGraphicsScene *botscene;
    /** The view for botscene */
    QGraphicsView *botview;
    /** Radio Button to choose the OutofPlace Heuristic */
    QRadioButton *OutofPlaceButton;
    /** Radio Button to choose the Manhattan Heuristic */
    QRadioButton *ManhattanButton;

public slots:
    /** Quits the game
    @post Game Ends */
    void quit();
    /** Starts the game
    @post Creates a Board based on the three inputted values */
    void start();
    /** Displays the solution sequence
    @post A solution sequence is displayed in the bottom scene */
    void displayAlg();
    /** Handles the timer and allows the tiles to move in animation.
    @post Animates the tile movement. */
    void handleTimer();
};

#endif// MAINWINDOW_H
