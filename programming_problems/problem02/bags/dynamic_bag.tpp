#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() { bag = new T[bagSize]; }

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T> & x)
{
  bagSize = x.getCurrentSize();
  bag = new T[bagSize];

  for (int i = 0; i < bagSize; i++)
  {
    bag[i] = x.bag[i];
  }

}
    
template<typename T>
DynamicBag<T>::~DynamicBag() { delete [] bag; }

template<typename T>
void DynamicBag<T>::clear() { bagSize = 0; }

template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  
  if (this != &x) 
  { 
    delete [] bag; 

    if (bagSize != x.getCurrentSize())
    {
      bagSize = x.bagSize;
      bag = new T[bagSize];
    } else 
    {
      bag = new T[bagSize];
    }

    for (int i = 0; i < bagSize; i++)
    {
      bag[i] = x.bag[i];
    }
  }

  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x)
{
  T *temp; //temp variable to hold the paramater
  for (int i = 0; i < bagSize; i++)
  {
    temp[i] = x.bag[i]; // set the input equal to temp
  }

  for (int i = 0; i < bagSize; i++)
  {
    x.bag[i] = bag[i]; // move the bag to the input.
  }

  for (int i = 0; i < bagSize; i++)
  {
    bag[i] = temp[i]; // move the input to the bag
  }

  delete [] temp;

}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  bag[bagSize] = item;
  ++bagSize;
  
  return bag[bagSize-1] == item;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
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
bool DynamicBag<T>::isEmpty() const
{
  return bagSize == 0;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return bagSize;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  return (getFrequencyOf(item) != 0);
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  
  std::size_t freq = 0;

  for(std::size_t i = 0; i < bagSize; ++i)
  {
    if(bag[i] == item) ++freq;
  }
  
  return freq;
};
