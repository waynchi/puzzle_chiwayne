#include "GUITile.h"

GUITile::GUITile(double nx, double ny, double w, double h) :  QGraphicsRectItem(nx, ny, w, h)
{
    x = nx;
    y = ny;
    width = w;
    height = h;
}


