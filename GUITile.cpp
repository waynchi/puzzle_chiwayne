#include "GUITile.h"
#include "MainWindow.h"

GUITile::GUITile(double nx, double ny, double w, double h,int tile, MainWindow *gWindow) :  QGraphicsRectItem(nx, ny, w, h)
{
    x = nx;
    y = ny;
    width = w;
    height = h;
    tile_ = tile;
    gWindow_ = gWindow;
}

GUITile::~GUITile()
{
}

void GUITile::mousePressEvent ( QGraphicsSceneMouseEvent* event ) {
gWindow_->moveTile( this );
event = event;
}

