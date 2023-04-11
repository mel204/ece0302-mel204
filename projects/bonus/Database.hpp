
#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <string>
#include "binary_search_tree.hpp"
#include "list.hpp"




template <typename T>
class Database
{
public:
  Database();

  // determine if the database is empty
  bool isEmpty();

  // return current number of entries
  std::size_t getNumberOfEntries();

  // insert entry 
  bool add(std::string key1, std::string key2, const T& item);

  // remove entry 
  bool remove(std::string key);

  // remove all entries
  void clear();

  // retrieve the value of the entry associated with the input key
  T getValue(std::string key);

  // return true if an entry exists associated with the input key
  bool contains(std::string key);

private:

  // TODO:

  struct Entry 
{
    std::string title;
    std::string author;
    int pubYear;
    bool operator==(const Entry&) const;

    bool Entry::operator==(const Entry& e) const 
    { return (title == e.title) && (author == e.author) && (pubYear == e.pubYear);}
};

  // binary search tree to store the values
  BinarySearchTree<std::string, T> key1;
  BinarySearchTree<std::string, T> key2;

  // list to store data
  List<T> explored;

  // number to store entries
  std::size_t numEntries;

};

#include "Database.tpp"
#endif // _DATABASE_H_
