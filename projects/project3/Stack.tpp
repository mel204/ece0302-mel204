//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() 
{
	headPtr = nullptr;
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	while (!isEmpty()) { pop(); }
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return headPtr == nullptr;
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, headPtr);
	headPtr = newNodePtr; // preserve position of new node ptr
	newNodePtr = nullptr; // clear new node ptr
	++currentSize;

	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	if (isEmpty())
	{
		throw std::logic_error("Stack is Empty");
	}

	return headPtr->getItem();
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	bool result = false;

	if (!isEmpty())
	{
		//delete top of stack while its not empty
		Node<ItemType>* popNode = headPtr;
		headPtr = headPtr -> getNext();

		//delete top node
		popNode -> setNext(nullptr);
		delete popNode;
		popNode = nullptr;

		//decrement size and update result
		--currentSize;
		result = true;
	}

	return result;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	while (!isEmpty()) { pop(); }
}  // end clear

