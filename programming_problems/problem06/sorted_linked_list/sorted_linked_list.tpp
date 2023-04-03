#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) 
{
  // TODO
  // implement bubble sort to sort unsorted list

  for(int i = 0; i < unsorted_list.getLength(); i++)
  {
    insert(unsorted_list.getEntry(i));
  }

}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
  clear();
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  // bool to check if inserted
  bool success = false;
  int i = 0;
  // while its not inserted
  while(!success)
  {
    if ( i == getLength())
    {
      LinkedList<T>::insert(i, item);
      success = true;
    }
    if ( item < getEntry(i))
    {
      LinkedList<T>::insert(i, item);
      success = true;
    }

    i++;
  }
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw (std::range_error("empty list in remove"));
  // TODO
  // iterate to find position using linked list getEntry
  int position = getPosition(item);
  if(isEmpty())
    throw (std::range_error("out of range"));
  for(int i = 0; i < LinkedList<T>::getLength(); i++)
  {
    if(item == LinkedList<T>::getEntry(i))
      LinkedList<T>::remove(position);
  }

}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw (std::range_error("empty list in remove"));
  // TODO
  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
  // TODO
  
  for (int i = 0; i < LinkedList<T>::getLength(); i++)
  {
    if(item == LinkedList<T>::getEntry(i))
    {
      return i;
    }
  }

  return -1;
}
