#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  //TODO
  // initialize pointer to first node and list size

  headPtr = nullptr;
  listSize = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //TODO
  delete [] headPtr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //TODO
  listSize = x.getLength();

  

  for (int i = 0; i < listSize; i++)
  {
    insert(i, x.getEntry(i))
  }

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  //TODO
    if (this != &x)
  {
    delete [] list;

    //delete previously stored data in the array
    //make sizes equal

    if (listSize != x.listSize)
    { listSize = x.listSize; }

    for (int i = 0; i < listSize; i++)
    {
      list[i] = x.list[i];
    }

  }
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  //TODO

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
bool LinkedList<T>::isEmpty() const noexcept
{
  //TODO
  return listSize == 0;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  //TODO
  return listSize;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //TODO
  Node<T> *newNodePtr = new Node<T>();
  newNodePtr -> setItem(item);
  newNodePtr -> setNext(headPtr);

  headPtr = newNodePtr;

  listSize++

  return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  //TODO
  
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //TODO
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
