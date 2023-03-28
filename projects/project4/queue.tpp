#include "queue.hpp"

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  // TODO
  internal_list.insert(internal_list.getLength(), item);
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  // TODO
  if(!isEmpty())
  {
    internal_list.remove(0);
  } else throw std::range_error("list is empty");
}

template <typename T, typename L>
T Queue<T,L>::peekFront()
{
  // TODO
  return internal_list.getEntry(0);
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
  // TODO
  return internal_list.isEmpty();
}

