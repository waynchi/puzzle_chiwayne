#include "puzzle_move.h"
#include <iostream>

using namespace std;
// Constructor for starting Board of an A* search
PuzzleMove::PuzzleMove(Board &b)
{
	tileMove_ = 0;
	prev_ = NULL;
	b_ = new Board(b);
	g_ = 0;
	h_ = -1;
}
  	

  // Constructor for subsequent search boards 
  // (i.e. those returned by Board::potentialMoves() )
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent)
{
	tileMove_ = tile;
	prev_ = parent;
	b_ = new Board(*b);
	g_ = (parent->g_)+1;
	h_ = -1;
}

  // Destructor
PuzzleMove::~PuzzleMove()
{
}

  // Compare to PuzzleMoves based on f distance 
bool PuzzleMove::operator==(const PuzzleMove& p) const
{
	if((g_+h_) == (p.g_+p.h_))
	{ return true; }
	else
	{ return false; }
}


// Compare to PuzzleMoves based on f distance (needed for priority queue
bool PuzzleMove::operator<(const PuzzleMove& p) const
{
  if((g_ + h_) < (p.g_ + p.h_)){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ > p.g_)){
    return true;
  }
  else {
    return false;
  }
}
bool PuzzleMove::operator>(const PuzzleMove& p) const
{
  if( (g_ + h_) > (p.g_ + p.h_) ){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ < p.g_) ){
    return true;
  }
  else {
     return false;
  }
  
}

