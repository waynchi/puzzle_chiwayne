#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

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
  int input;
  while(!b.solved())
  {
  b.printBoard();
  cout << "Please enter the number you would like to move" << endl;
  cin >> input;
  b.move(input);
  }
  b.printBoard();
  cout << "Congratulations! You've solved the puzzle!" << endl;


  //**** Implement the gameplay here







  return 0;
}
