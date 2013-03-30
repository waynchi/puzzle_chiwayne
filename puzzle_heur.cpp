#include "puzzle_heur.h"
#include <cmath>


int OutofPlaceHeuristic::compute(int *tiles, int size)
{
 int h_ = 0;
 int count = 0;
 for (int i = 0; i < size; i++)
 {
  if (tiles[i] == 0)
  {}
  else if (tiles[i] != i)
   count++;
 }  	
 h_ = count;
 return h_;
}



int ManhattanHeuristic::compute(int *tiles, int size)
{
 int h_ = 0;
 int dim = static_cast<int>(sqrt(size));
 int count = 0; 
 
 for (int i = 0; i < size; i++)
 {
  int temp = tiles[i];
  int temp2 = 0;
  if(temp != 0){
  if(temp < i){
   /*while (temp != i)
   {
    if(!((temp+dim) >= (i+1)))
    {
     temp+=dim;
     count++;
    }
    else //if(!((temp+1)>i))
    {
     temp++;
     count++;
    }
   }*/
   temp2 = i;
   while (temp2 != temp)
   {
    if(((temp2-dim) >= i))
    {
     temp2 = temp2-dim;
     count++;
    } 
    else //if((temp-1)>=i)
    {
     temp2--;
     count++;
    }
   }
  }
  else if(temp > i){
   while (temp != i)
   {
    if(((temp-dim) >= i))
    {
     temp = temp-dim;
     count++;
    } 
    else //if((temp-1)>=i)
    {
     temp--;
     count++;
    }
   }
  }
 }
 }
 h_ = count;
 return h_;
}
    
    
    
    
