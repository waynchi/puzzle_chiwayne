#include "puzzle_move.h"

// Constructor for starting Board of an A* search
PuzzleMove::PuzzleMove(Board &b)
{
	tileMove_ = 0;
	prev_ = NULL;
	b_ = new Board(b);
	g_ = 0;
	int count = 0;
	//calculating h_
	for (int i = 0; i < b.getSize(); i++)
	{
	if (b.getTiles()[i] != i)
		count++;
	}  	
	h_ = count;
}
  	

  // Constructor for subsequent search boards 
  // (i.e. those returned by Board::potentialMoves() )
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent)
{
	tileMove_ = tile;
	prev_ = parent;
	b_ = b;
	g_ = (parent->g_)+1;
	int count = 0;
	//calculating h_
	for (int i = 0; i < b->getSize(); i++)
	{
	if (b->getTiles()[i] != i)
		count++;
	}  	
	h_ = count;
}

  // Destructor
PuzzleMove::~PuzzleMove()
{delete b_;}

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

