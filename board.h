#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <iomanip>
#include <map>
#include <functional>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
/**
A Board Class that creates a Board object which stores tiles, can scramble the board, and can generate potential moves.

@author Wayne Chi
*/
class Board
{
 public:
  /**  default constructor */
  Board(); 

  /** Init a board of given size and scramble it with numInitMoves 
   * by moving the space tile with a randomly chosen direction N, W, S, E
   * some of which may be invalid, in which case we skip that move */
  Board(int size, int numInitMoves, int seed);

  /** Copy constructor */
  Board(const Board &b);

  /** Another kind of "copy" constructor */
  Board(int *tiles, int size); 

  /** Destructor */
  ~Board();

  /** Swaps the blank with the specified tile 
   *  @param tile The tile that is to be swapped
  */
  
  void move(int tile);
  
  //Prints out the current board
  /** Prints out the current Board */
  void printBoard();

  /** Generate potential moves and returns new boards
   * Key=tile, Value=Ptr to corresponding Board */
  std::map<int, Board*> potentialMoves(); 

  /** Returns true if the board is solved, false otherwise */
  bool solved();
  //Note 1: STL Classes may only be used where explicitly stated.
//Note 2: Use Doxygen style comments in all of your classes
//Note 3: Although no points are dedicated to the proper use of git & GitHub, submissions not following the workflow will be penalized. That includes the proper closing of issues on your private tracker.


  // Operators
  /** Friend operator in order to print out the board */ 
  friend std::ostream& operator<<(std::ostream &os, const Board &b);
  /** Equals comparison for Board */
  bool operator==(const Board& rhs) const;
  /** Less than comparison for Board */
  bool operator<(const Board& rhs) const;
  /** Does not Equal comparison for Board */
  bool operator!=(const Board& rhs) const;
  
  // Accessors 
  /** Accesses the Board's Tiles */
  int* getTiles();
  /** Accesses the Board's Size */
  int getSize();
  // Add any accessors


 private:
 
  /** The tiles of the board */
  int *tiles_;
  /** The size (amount of tiles) of the board */
  int size_;
  // Add Data members

};

// Leave this alone and don't touch it!
struct BoardLessThan : 
  public std::binary_function<const Board*, const Board*,bool>
{
  bool operator()(const Board *b1, const Board *b2) const
  {
    return *b1 < *b2;
  }
};




#endif
