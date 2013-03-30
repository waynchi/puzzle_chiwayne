#ifndef PUZZLEMOVE_H
#define PUZZLEMOVE_H
#include <functional>
#include "board.h"
#include "puzzle_heur.h"

class PuzzleMove
{
 public:
  // Constructor for starting Board of an A* search
  /** Constructor for starting Board of an A* search 
  @param b Reference to the Board for the PuzzleMove*/
  PuzzleMove(Board &b);

  // Constructor for subsequent search boards 
  // (i.e. those returned by Board::potentialMoves() )
  /** Constructor for subsequent search boards 
     (i.e. those returned by Board::potentialMoves) ) 
     @param tile Tile passed in to become the tile of the PuzzleMove
     @param b Board passed in for PuzzleMove
     @param parent This puzzlemove's Parent PuzzleMove*/
  PuzzleMove(int tile, Board *b, PuzzleMove *parent);

  // Destructor
  /** Destructor */
  ~PuzzleMove();

  // Compare to PuzzleMoves based on f distance 
  /** Less than operator for PuzzleMove. Compared based on f distance(f score) */
  bool operator<(const PuzzleMove& p) const;
  /** Greater than operator for PuzzleMove. Compared based on f distance(f score) */
  bool operator>(const PuzzleMove& p) const;
  /** Equals comparison operator for PuzzleMove. Compared based on f distance(f score) */
  bool operator==(const PuzzleMove& p) const;

  // Data members can be public
 public:
  /** tile moved to reach the Board b */
  int tileMove_;  // tile moved to reach the Board b
  /** Pointer to a board representing the updated state */
  Board *b_;      // Pointer to a board representing the updated state
  /** distance from the starting board */
  int g_;         // distance from the start board
  /** heuristic distance to the goal */
  int h_;         // heuristic distance to the goal
  /** Pointer to the parent PuzzleMove */
  PuzzleMove *prev_;  // Pointer to parent PuzzleMove
};


// Leave this alone and don't touch it!
struct PuzzleMoveGreater : 
  public std::binary_function<const PuzzleMove*, const PuzzleMove*,bool>
{
  bool operator()(const PuzzleMove *m1, const PuzzleMove *m2) const
  {
    return *m1 > *m2;
  }
};

#endif
