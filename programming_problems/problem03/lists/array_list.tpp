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
  swap(rhs);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) 
{
  
std::swap(list, rhs.list);
std::swap(listSize, rhs.listSize);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept { return listSize == 0;}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept { return listSize ; }

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item)
{
  if (position <= listSize && position >= 0)
  {
    T* temp = new T[listSize + 1];
    for (int i = 0; i < listSize; i++)
    {
      temp[i] = list[i];
    }

    //shift to insert

    for (int i = listSize; i > position; i--)
    {
      temp[i] = temp[i - 1];
    }

    temp[position] = item;

    delete [] list;
    list = temp;
    listSize++;
    return true;

  } else 
  {
    return false;
  }
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){

  if (position < listSize && position >= 0)
  {
    T* temp = new T[listSize - 1];
    for (int i = 0; i < listSize; i++)
    {
      temp[i] = list[i];
    }

    //shift to insert

    for (int i = position + 1; i < listSize; i++)
    {
      temp[i - 1] = list[i];
    }

    delete [] list;
    list = temp;
    listSize--;
    return true;

  } else 
  {
    return false;
  }
}

template <typename T>
void ArrayList<T>::clear() 
{
   listSize = 0;
   delete [] list;
   list = new T[listSize];
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const 
{
  if (position < listSize && position >= 0)
    return list[position];
  else 
    return T();
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) 
{
  if (position < listSize && position >= 0)
    list[position] = newValue;
}
