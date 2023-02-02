#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset{
public:

  // default constructor
  Bitset();

  // constructor
  Bitset(intmax_t size);

  // constructor to take a string
  Bitset(const std::string & value);

  // destructor
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // get the size of the vector
  intmax_t size() const;

  // check if its valid or not
  bool good() const;

  // set the index of the bit vector to 1
  void set(intmax_t index);

  // set the index of the bit vector to 0
  void reset(intmax_t index);

  // toggle the selected bit
  void toggle(intmax_t index);

  // TODO COMMENT
  bool test(intmax_t index);

  // TODO COMMENT
  std::string asString() const;

private:

  // TODO
  // private member to store bitset in an array by a pointer

  uint8_t *bitVector = nullptr;

  // vector size

  intmax_t bitSize;

  //private member variable to check if bitset is valid

  bool valid = true;

};

#endif
