#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 3){
    cerr << "Usage: ./puzzle size initMoves seed" << endl;
    return 1;
  }

  
  int size, initMoves, seed;
  
  size = atoi(argv[1]);
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);

  Board b(size,initMoves,seed);
  PuzzleHeuristic *pm = new ManhattanHeuristic();
  
  int input;
  while(!b.solved())
  {
  b.printBoard();
  cout << "Enter tile number to move or -1 for a cheat:  ";
  cin >> input;
  cout << " " << endl;
  if(input == -1)
  {
   PuzzleSolver solver(b);
   int count = solver.run(pm);
   cout << "Try this sequence:  ";
   for(int j = (count-1); j >=0; j--)
   {
    cout << solver.getSequence().at(j) << " ";
   }
   cout << " " << endl;
   cout << "(Expansions) = " << solver.getNumExpansions() << endl;
   cout << " " << endl;
  }
  else
  {
   b.move(input);
  }
    }
  b.printBoard();
  cout << "Congratulations! You've solved the puzzle!" << endl;
  delete pm;


  //**** Implement the gameplay here
  
 //Used this to test PMMinlist
 
 /*Board a(9,5,200);
 Board b(9,15,200);
 Board c(9,20,200);
 Board d(9,35,200);
 Board e(9,1,200);

 PuzzleMove *v = new PuzzleMove(a);
 PuzzleMove *w = new PuzzleMove(b);
 PuzzleMove *x = new PuzzleMove(c);
 PuzzleMove *y = new PuzzleMove(d);
 PuzzleMove *z = new PuzzleMove(e);

 PMMinList mlist; 

 mlist.push(v);
 mlist.push(w);
 mlist.push(x);
 mlist.push(y);
 mlist.push(z);
 
 for(int i = 0 ; i < 5; i++)
 {
  cout << (mlist.top()->g_ + mlist.top()->h_) << endl;
  mlist.pop();
 }*/
 







  return 0;
}
