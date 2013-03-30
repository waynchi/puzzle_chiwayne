#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H
#include <queue>
#include <vector>
#include <deque>
#include <set>
#include "board.h"
#include "puzzle_move.h"
#include "puzzle_heur.h"
#include "mylist.h"

class PuzzleSolver
{
 public:
  //*** Typedef for the closed-list set.  Declare your closed list variable as
  //***   BoardSet closedlist; 
  //*** when you write your code for the run() funciton
  typedef std::set<Board *, BoardLessThan> BoardSet;

  // Constructor (makes a copy of the Board and stores it in _b
  /** Constructor (makes a copy of the Board and stores it in _b) 
  @param b Reference of the Board passed in to be stored*/
  PuzzleSolver(const Board &b);

  // Destructor
  /**Destructor. Deletes the original Board*/
  ~PuzzleSolver();

  // Run the A* search returning -1 if no solution exists or
  //  the number of moves in the solution
  /** Run the A* search returning -1 if no solution exists or
    the number of moves in the solution
    @param *ph The type of Heuristic that PuzzleSolver::run will end up using
    @return count The amount of steps required to reach the goal */
  int run(PuzzleHeuristic *ph);

  //**** Return the solution List
 

  // Return how many expansions were performed in the search
  /** Returns how many expansions were performed in the search
  @return Expansions The number of expansions that were performed in the search */
  int getNumExpansions();
  /** Returns the sequence derived from the search 
  @return Sequence The Sequence list that leads to a solved puzzle */
  mylist<int>& getSequence();

 private:
  /** The original and starting board that is to be solved*/
  Board *b_;
  /** The number of expansions performed in the search */
  int expansions_;
  //**** Declare a List to store your solutions sequence of tiles to move
  /** The Sequence list that leads to a solved puzzle */
  mylist<int> sequence;
  
};

#endif
