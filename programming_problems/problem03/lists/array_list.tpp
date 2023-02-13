#include "array_list.hpp"

// Constructor/Destructor

template <typename T>
ArrayList<T>::ArrayList() { listSize = 0; list = new T[listSize]; }

template <typename T>
ArrayList<T>::~ArrayList() {delete [] list; }

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs)
{
  listSize = rhs.getLength();
  list = new T[listSize];

  for (int i = 0; i < listSize; i++)
  {
    list[i] = rhs.list[i];
  }
}

// overloaded operator

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs)
{
  if (this != &rhs)
  {
    delete [] list;

    //delete previously stored data in the array
    //make sizes equal

    if (listSize != rhs.listSize)
    { listSize = rhs.listSize; }

    for (int i = 0; i < listSize; i++)
    {
      list[i] = rhs.list[i];
    }

  }
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) 
{
  
  T *temp; //temp variable to hold the paramater
  for (int i = 0; i < listSize; i++)
  {
    temp[i] = rhs.list[i]; // set the input equal to temp
  }

  for (int i = 0; i < listSize; i++)
  {
    rhs.list[i] = list[i]; // move the bag to the input.
  }

  for (int i = 0; i < listSize; i++)
  {
    list[i] = temp[i]; // move the input to the bag
  }

  delete [] temp;


}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept { return listSize == 0;}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept { return listSize ; }

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item)
{
  if (position == listSize)
  {list[listSize] = item; ++listSize;}

  std::size_t idx = position;

  for (int i = idx; i < listSize; i++)
  {
    list[i] = list[i + 1];
  }
  ++listSize;

  list[position] = item;

  if (list[position] == item)
  { return true;}
  else
  {return false;}

}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){

   if(listSize == 0 || listSize == position) return false;

  std::size_t idx = position;


  --listSize;
  for(std::size_t i = idx; i < listSize; ++i){
    list[i] = list[i+1];
  }

  return true; 
}

template <typename T>
void ArrayList<T>::clear() { listSize = 0; }

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const 
{
  return list[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) 
{
  list[position] = newValue;
}
