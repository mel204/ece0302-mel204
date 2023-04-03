#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "abstract_list.hpp"

//define node class to use linked list
template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   
public:


  Node() : next(nullptr)
  {
  } // end default constructor

  Node(const ItemType& anItem) : item(anItem), next(nullptr)
  {
  } // end constructor

  Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
                  item(anItem), next(nextNodePtr)
  {
  } // end constructor

  void setItem(const ItemType& anItem)
  {
    item = anItem;
  } // end setItem

  void setNext(Node<ItemType>* nextNodePtr)
  {
    next = nextNodePtr;
  } // end setNext

  ItemType getItem() const
  {
    return item;
  } // end getItem

  Node* getNext() const
  {
    return next;
  } // end getNext

}; // end Node


template <typename T>
class List: public AbstractList<T>
{
public:
  
  // default constructor
  List();
  
  // copy constructor
  List(const List& x);
    
  // destructor
  ~List();
  
  // copy assignment
  List& operator=(List x);

  // swap
  void swap(List& x);
  
  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  std::size_t getLength() const noexcept;

  // insert item at position in the list 
  void insert(std::size_t position, const T& item);

  // remove item at position in the list 
  void remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position 
  T getEntry(std::size_t position) const;

  // set the value of the item at position 
  void setEntry(std::size_t position, const T& newValue);

private:

  //TODO
  //pointer to first node
  Node<T> *headPtr;

  //number of list items  
  std::size_t itemCount;

  //get node at position
  Node<T>* getNodeAt(int position) const;

};

#include "list.tpp"

#endif
