#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"
#include "puzzle_move.h"
#include <vector>

using namespace std;

// Constructor (makes a copy of the Board and stores it in _b)
PuzzleSolver::PuzzleSolver(const Board &b)
{
 b_ = new Board(b);
 expansions_ = 0;
}

PuzzleSolver::~PuzzleSolver()
{
delete b_;
}


/*Add the start state (start move) to the open_list
Add the starting board to the closed_list
while(open_list is not empty and no solution has been found)
    move = remove min. f-value state from open_list
    Add move's board to the garbage list
    if move is goal node then trace path backwards & break
    Generate next potential moves (i.e. expansions)
    For each potential move (successor), s
      if the board of s is not in the closed set
        Compute f values for each potential move
        Add the board of s to the closed set
        Add s to the open_list
        Increment number of expansions
Cleanup and return appropriate values*/
int PuzzleSolver::run(PuzzleHeuristic *ph)
{

 int count = 0;
 PMMinList openlist;
 vector<PuzzleMove*> garbage;
 vector<Board*> garbageBoard;
 BoardSet closedlist;
 PuzzleMove *a = new PuzzleMove(*b_);
 garbageBoard.push_back(a->b_);
 a->h_ = ph->compute(a->b_->getTiles(), a->b_->getSize());
 openlist.push(a);
 garbage.push_back(a);
 closedlist.insert(a->b_);
 while(!(openlist.empty()))
 {
  PuzzleMove *move = new PuzzleMove(*openlist.top());
  garbage.push_back(move);
  move->h_ = ph->compute(move->b_->getTiles(), move->b_->getSize());
  openlist.pop();
  closedlist.insert(move->b_);
  if(move->h_ == 0)
  {  
   while(move->prev_ != NULL)
   {
    //garbage.push_back(move);
    count++;
    sequence.push_back(move->tileMove_);
    move = move->prev_;
   }
   
   break;
  }
  else
  {
   std::map<int, Board*> z = move->b_->potentialMoves();
   std::map<int, Board*>::iterator it;
   for(it = z.begin(); it !=z.end(); ++it)
   {
    PuzzleMove *temp = new PuzzleMove(it->first, it->second, move);
    garbageBoard.push_back(temp->b_);
    garbageBoard.push_back(it->second);
    garbage.push_back(temp);
    temp->h_ = ph->compute(temp->b_->getTiles(), temp->b_->getSize());
    if(closedlist.find(temp->b_) == closedlist.end())
    {
    
     openlist.push(temp);
     closedlist.insert(temp->b_);
     expansions_++;
    }
    else{ 
    }
   }
  }
 }
 for(unsigned int i = 0; i < garbage.size(); i++)
 {
 	delete garbage[i];
 }
 /*PuzzleMove *temppuzzle;
 while (!openlist.empty())
 {
 	temppuzzle = openlist.top();
 	openlist.pop();
 	delete temppuzzle;
 }*/
 for(unsigned int j = 0; j < garbageBoard.size(); j++)
 {
 	delete garbageBoard[j];
 }
 return count;
 
}

int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}

mylist<int>& PuzzleSolver::getSequence()
{
  return sequence;
}
