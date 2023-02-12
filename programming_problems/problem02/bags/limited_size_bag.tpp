#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {bag = new T[bagSize];}


  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  // check if bag is too big

  if (bagSize > maxsize){ return false; }
  
  bag[bagSize] = item;
  ++bagSize;
  
  return bag[bagSize-1] == item;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  if(bagSize == 0) return false;

  std::size_t idx = 0;
  for(std::size_t i = 0; i < bagSize; ++i){
    if(bag[i] == item) break;
    ++idx;
  }

  if(idx == bagSize) return false;

  --bagSize;
  for(std::size_t i = idx; i < bagSize; ++i){
    bag[i] = bag[i+1];
  }

  return true;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return bagSize == 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return bagSize;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  return (getFrequencyOf(item) != 0);
}

template<typename T>
void LimitedSizeBag<T>::clear(){bagSize = 0;}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq = 0;

  for(std::size_t i = 0; i < bagSize; ++i)
  {
    if(bag[i] == item) ++freq;
  }
  
  return freq;
};
