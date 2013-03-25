#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>
#include <typeinfo>
#include <stdexcept>
using namespace std;

template <typename T>
class mylist{
	private:
	T* array;
	int size_; //this is the "capacity"
	int loc_;  //this is the "actual size" Sorry for any confusion
	public:
	mylist();
	mylist(int size);
	~mylist();
	void push_back(T word);
	int size() const;
	T& at(int loc) const;
	bool remove(T val);
	T pop(int loc);
	T& operator[](int loc) const;
	void reset();
};

//constructors and destructors
template <typename T>
mylist<T>::mylist()
{
	size_ = 100;
	loc_ = 0;
	array = new T[size_];
}

template <typename T>
mylist<T>::mylist(int size)
{
	size_=size;
	loc_ = 0;
	array = new T[size_];
}
	
template <typename T>
mylist<T>::~mylist()
{
	delete[] array;
}

//pushback function to add variables
template <typename T>
void mylist<T>::push_back(T word)
{
	
	if (size_ == loc_)
	{
		size_ = size_*2;
		T* temp = new T[size_];
		for (int i = 0; i < size_/2; i++)
		temp[i] = array[i];
		delete[] array;
		array = temp;
		/*string *array = new string[size_];
		for (int k =0; k < size_/2; k++)
		array[k] = temp[k];*/
	}
	array[loc_] = word;
	loc_++;
}

template <typename T>
void mylist<T>::reset()
{
	loc_ = 0;
}
//size and at functions
template <typename T>
int mylist<T>::size() const
{
	return loc_;
}

template <typename T>
T& mylist<T>::at(int loc) const
{
	return array[loc];
}

//[] operator function
template <typename T>
T& mylist<T>::operator[](int loc) const
{
	return array[loc];
}


// If "val" occurs in the list, remove the first
// occurrence of "val" and return true. Throws an
// error otherwise.
template <typename T>
bool mylist<T>::remove(T val)
{
	for (int i = 0; i <size_; i++)
	{
		if(array[i] == val)
		{
			for(int ii = i; ii < size_-1; ii++)
			{
				array[ii] = array [ii+1];
			}
			array[loc_] = 0;
			loc_ --;
			return true;
		}
	}
	
	throw std::out_of_range("The value is not in this list!");
}

/*// remove and return the value at location "loc"
template <typename T>	
T mylist<T>::pop(int loc)      
{
	if(loc > loc_)
	{
		throw std::out_of_range("It is out of bounds!");
	}
	if(loc < 0)
	{
		throw std::out_of_range("It is out of bounds!");
	}
	T temp = array[loc];
	for( int i = loc; i < size_-1; i++)
		{
			array[i] = array [i+1];
		}
		array[size_] = 0;
		loc_--;
	return temp;
}*/



#endif



