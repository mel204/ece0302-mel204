#include "sorted_list.hpp"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(SortedList<T, L> x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty() const noexcept
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength() const noexcept
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  // TODO
  // bool to check if inserted
  bool success = false;
  int i = 0;
  // while its not inserted
  while(!success)
  {
    if ( i == getLength())
    {
      plist.insert(i, item);
      success = true;
    }
    if ( item < getEntry(i))
    {
      plist.insert(i, item);
      success = true;
    }

    i++;
  }
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  // TODO
  if(isEmpty()) throw (std::range_error("empty list in remove"));
  // TODO
  // iterate to find position using linked list getEntry
  int position = getPosition(item);

  for(int i = 0; i < plist.getLength(); i++)
  {
    if(item == plist.getEntry(i))
      plist.remove(position);
  }

}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position) const
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  // TODO
  
  for (int i = 0; i < plist.getLength(); i++)
  {
    if(newValue == plist.getEntry(i))
    {
      return i;
    }
  }

  return -1;
}
