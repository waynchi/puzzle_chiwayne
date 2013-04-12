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

/** A basic GUITile that can be clicked on and appears in game 
@author Wayne Chi */
class GUITile : public QGraphicsRectItem{

public:
	/** basic constructor 
	@param nx location on x-axis
	@param ny location on y-axis
	@param w width
	@param h height
	@param tile tile number for the GUITile
	@param gWindow a pointer to the MainWindow*/
	GUITile(double nx, double ny, double w, double h, int tile, MainWindow *gWindow);
	/** basic destructor */
	~GUITile();
	/** location on x-axis*/
	double x;
	/** location on y-axis*/
	double y;
	/** width of the tile*/	
	double width;
	/** height of the tile */
	double height;
	/** the text that will be displayed by the GUITile */
	QGraphicsSimpleTextItem *text;
	/** the tile number for the GUITile */
	int tile_;
	/** a pointer to the MainWindow */
	MainWindow *gWindow_;
	/** An event that occurs when the Mouse button clicks on the GUITile
	@param event The event of the mouse getting clicked*/
	void mousePressEvent ( QGraphicsSceneMouseEvent* event );
	
	





};

#endif// GUITILE_H
