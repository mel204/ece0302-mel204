#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

template<typename T> LinkedList<T> sort(LinkedList<T> list)
{
	// your code should go here.

	// implementing bubble sort

	int swaps;
	T temp, temp1;

	do {
		swaps = 0;
		for (int i = 0; i < list.getLength() - 1; i++) {
			//compare elements
			for (int j = 0; j < list.getLength() - 1; j++) {
				if (list.getEntry(j) > list.getEntry(j + 1))
				{
					//swap if greater than
					temp = list.getEntry(j);
					temp1 = list.getEntry(j + 1);

					list.setEntry(j, temp1);
					list.setEntry(j + 1, temp);

					swaps++;
				}
			}
		}
	} while (swaps > 0);

return list;

}

#endif
