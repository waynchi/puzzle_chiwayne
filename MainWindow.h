
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

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    void moveTile(GUITile *guitile);
    void show();
    void displayAlg();
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    QWidget *window;
    Board *b;
    vector<GUITile*> tilevector;
    GUITile *tile;
    int size_;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QGraphicsScene *botscene;
    QGraphicsView *botview;
    QRadioButton *OutofPlaceButton;
    QRadioButton *ManhattanButton;

public slots:
    void quit();
    void start();
};

#endif// MAINWINDOW_H
