#ifndef GUITILE_H
#define GUITILE_H

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
#include <vector>
#include <QLayout>
#include <QGraphicsSimpleTextItem>
#include <QLineEdit>
#include <iostream>
#include "board.h"
#include <QGraphicsRectItem>

class MainWindow;
class GUITile : public QGraphicsRectItem{

public:

	GUITile(double nx, double ny, double w, double h, int tile, MainWindow *gWindow);
	~GUITile();
	double x;
	double y;
	double width;
	double height;
	QGraphicsSimpleTextItem *text;
	int tile_;
	MainWindow *gWindow_;
	void mousePressEvent ( QGraphicsSceneMouseEvent* event );
	
	





};

#endif// GUITILE_H
