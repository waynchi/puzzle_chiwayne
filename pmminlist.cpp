#include "puzzle_move.h"
#include "pmminlist.h"
#include <iostream>

using namespace std;
/**
 * Default Constructor
 */
PMMinList::PMMinList() : slist_()
{

}

/**
 * Destructor
 */
PMMinList::~PMMinList()
{

}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest (if 
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::push(PuzzleMove* pm)
{
  list<PuzzleMove*>::iterator it = slist_.begin();
  it = slist_.begin();
  while(true)
  {
   if(slist_.empty())
   {slist_.push_back(pm); continue;
   }
   else{
   if (it == slist_.end())
   {
  	slist_.push_back(pm);
  	break;
   }
   else if(**it > *pm)
   {
  	slist_.insert(it, pm);
  	break;
   }
   }
   it++;
  }
  /*for(it = slist_.begin(); it != slist_.end(); it++)
  {
	if (*it > pm)
  	{
  		slist_.insert(it, pm);
  	}
  }
  if (it == slist_.end())
  {
  	slist_.push_back(pm);
  }*/
}
  			
 
  //---- Add your implementation to iterate through the list
  //---- to find the correct location to insert pm and then
  //---- use the insert() method of std::List to insert it
  //---- See http://www.cplusplus.com/reference/list/list/insert/


/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::pop()
{
  slist_.pop_front();
}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return reference to the minimum-scored PuzzleMove*
 */
PuzzleMove* PMMinList::top()
{
  return slist_.front();
}

