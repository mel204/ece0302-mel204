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
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //TODO
  listSize = x.listSize;

  //use insert to initialize list
  for (int i = 0; i < listSize; i++)
  {
    insert(i, x.getEntry(i));
  }

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{

}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  //TODO

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

  listSize++;

  return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  Node<T> * entryNodePtr = getPointerTo(anEntry);
  bool canRemove = !isEmpty() && (entryNodePtr != nullptr);


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
