#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "board.h"
using namespace std;


/** Init a board of given size and scramble it with numInitMoves 
 * by moving the space tile with a randomly chosen direction N, W, S, E
 * some of which may be invalid, in which case we skip that move 
 * 
 *  @param size Number of tiles for the game.  \
 *      Should be a perfect square (4, 16, 25)
 *  @param numInitMoves Number of tile moves to attempt to scramble the board
 *  @param seed Use to seed the random number generator (srand) 
 */
Board::Board(int size, int numInitMoves, int seed )
{
  size_ = size;
  tiles_ = new int[size_];
  int dim = static_cast<int>(sqrt(size_));
  srand(seed);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  int blankLoc = 0;
  for(int i=0; i < numInitMoves; i++){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;
    }
  }
}


//Defaulted a board with 9 tiles.
/** Default constructor. provide documentation here */
Board::Board()
{
  size_ = 9;
  tiles_ = new int[size_];
  int dim = static_cast<int>(sqrt(size_));
  srand(1);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  /*int blankLoc = 0;
  for(int i=0; i < 10; i++){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;
    }
  }*/
}

//copy constructor 
Board::Board(const Board &b)
{
	size_ = b.size_;
	tiles_ = new int[size_];
	for(int i = 0; i < size_; i++)
	{
		tiles_[i] = b.tiles_[i];
	}
}

//other copy constructor		
Board::Board(int *tiles, int size)
{
	size_ = size;
	tiles_ = new int[size_];
	for(int i = 0; i < size_; i++)
	{
		tiles_[i] = tiles[i];
	}
}
/** Default destructor. provide documentation here */
Board::~Board()
{
  delete []tiles_;
}

void Board::printBoard()
{
	int dim = static_cast<int>(sqrt(size_));
	for (int i = 0; i < size_; i++)
	{
		if(i%dim == 0)
		cout << "" << endl;
		if(tiles_[i] == 0)
		{
			cout << setw(3) << " ";
		}
		else{	cout << setw(3) << tiles_[i];}
	}
	cout << "" << endl;
}

void Board::move(int tile)
{
	int temp = 0;
	int tempzero = 0;
	int dim = static_cast<int>(sqrt(size_));
	int neighbors[4];
	for (int a = 0; a <size_; a++)
	{
		if(tiles_[a] == 0)
		{ tempzero = a; 
		break;}
	}
	for (int i = 0; i < size_; i++)
	{
		if(tiles_[i] == tile)
		{		temp = i;
		break;}
	}
	if (temp >= dim)
	{
		neighbors[0] = tiles_[temp-dim];
	}
	if ((temp+1)%dim != 0)
	{
		neighbors[1] = tiles_[temp+1];
	}
	if (temp%dim != 0)
	{
		neighbors[2] = tiles_[temp-1];
	}
	if (temp < (size_ - dim))
	{
		neighbors[3] = tiles_[temp+dim];
	}
	for (int j = 0; j < 4; j++)
	{
		if(neighbors[j] == 0)
		{
			tiles_[tempzero] = tile;
			tiles_[temp] = 0;
			break;
		}
	}
}

bool Board::solved()
{
	int count = 0;
	for (int i = 0; i < size_; i++)
	{
		if (tiles_[i] == i)
		count++;
	}
	if (count == (size_))
	return true;
	else
	return false;
}

std::ostream& operator<<(std::ostream &os, const Board &b)
{
	int dim = static_cast<int>(sqrt(b.size_));
	for (int i = 0; i < b.size_; i++)
	{
		if(i%dim == 0)
		os << "" << endl;
		if(b.tiles_[i] == 0)
		{
			os << setw(3) << " ";
		}
		else{	os << setw(3) << b.tiles_[i];}
	}
	os << "" << endl;
	return os;
}

bool Board::operator==(const Board& rhs) const
{
	if(size_ != rhs.size_)
	{
		return false;
	}
	else{
	int count = 0;
	for(int i = 0; i < size_; i++)
	{
		if (tiles_[i] == rhs.tiles_[i])
		{
			count++;
		}
	}
	if(count == size_)
	{
	return true;
	}
	else{ return false;}
	}
}

bool Board::operator!=(const Board& rhs) const
{
	if(size_ != rhs.size_)
	{
		return true;
	}
	else{
	int count = 0;
	for(int i = 0; i < size_; i++)
	{
		if (tiles_[i] == rhs.tiles_[i])
		{
			count++;
		}
	}
	if(count == size_)
	{
	return false;
	}
	else{ return true;}
	}
}

  
bool Board::operator<(const Board& rhs) const
{
  if(size_ < rhs.size_){
    return true;
  }
  bool val = false;
  for(int i=0; i < size_; i++){
    if(tiles_[i] < rhs.tiles_[i]){
       //val = true;
       //break;
       return true;
     }
     else if(tiles_[i] > rhs.tiles_[i]){
       //break;
       return false;
     }
  }
  return val;
}

int* Board::getTiles()
{
  	return tiles_;
}


int Board::getSize()
{
	return size_;
}


