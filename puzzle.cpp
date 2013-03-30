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
  //PuzzleHeuristic *pm = new ManhattanHeuristic();
  //testing out the OutofPlaceHeuristic
  PuzzleHeuristic *pm = new OutofPlaceHeuristic();
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
   cout << "(Expansions = " << solver.getNumExpansions() << ")" << endl;
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
 
 /*Board a(16,50,200);
 Board b(16,150,300);
 Board c(16,30,600);
 Board d(16,20,800);
 Board e(16,74,10000);
 PuzzleHeuristic *pm = new ManhattanHeuristic();

 PuzzleMove *v = new PuzzleMove(a);
 v->h_ = pm->compute(v->b_->getTiles(), v->b_->getSize());
 PuzzleMove *w = new PuzzleMove(b);
 w->h_ = pm->compute(w->b_->getTiles(), w->b_->getSize());
 PuzzleMove *x = new PuzzleMove(c);
 x->h_ = pm->compute(x->b_->getTiles(), x->b_->getSize());
 PuzzleMove *y = new PuzzleMove(d);
 y->h_ = pm->compute(y->b_->getTiles(), y->b_->getSize());
 PuzzleMove *z = new PuzzleMove(e);
 z->h_ = pm->compute(z->b_->getTiles(), z->b_->getSize());

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
