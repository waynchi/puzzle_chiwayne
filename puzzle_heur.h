#ifndef PUZZLE_HEUR_H
#define PUZZLE_HEUR_H

/** A virtual function that is to be the parent of other Heuristic functions such as the Manhattan and the OutofPlace.

@author Wayne Chi
*/
class PuzzleHeuristic
{
 public:
  /** A virtual function. Implementation would include a heuristic to solve for the h_ score
  @param tiles tiles pointer of a Board. The tiles pointer is used in computation. 
  @param size size Size of the Board
  @return h_score Returns the h score as computed.*/
  virtual int compute(int *tiles, int size) = 0;
};

/** An implementation of the PuzzleHeuristic. It calculates the h score by seeing how far each tile is from its correct position. 
It assumes that tiles can jump over one another.

@author Wayne Chi
*/
class ManhattanHeuristic : public PuzzleHeuristic
{
 public:
  /** It calculates the h score by seeing how far each tile is from its correct position. 
It assumes that tiles can jump over one another.
  @param tiles tiles pointer of a Board. The tiles pointer is used in computation. 
  @param size size Size of the Board
  @return h_score Returns the h score as computed.*/
  int compute(int *tiles, int size);
};

/** An implementation of PuzzleHeuristic. It calculates the h score by seeing how many
tiles are out of place. */
class OutofPlaceHeuristic : public PuzzleHeuristic
{
 public:
  /** It calculates the h score by seeing how far each tile is from its correct position. 
  It assumes that tiles can jump over one another.
  @param tiles tiles pointer of a Board. The tiles pointer is used in computation. 
  @param size size Size of the Board
  @return h_score Returns the h score as computed.*/
  int compute(int *tiles, int size);
};
  

#endif
