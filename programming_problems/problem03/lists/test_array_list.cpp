#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test Constructors;", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.isEmpty());
  REQUIRE(list.getLength() == 0);
  
}

TEST_CASE( "Test overloaded operator", "[ArrayList]" ) {

  ArrayList<int> list;
  ArrayList<int> list2;

  REQUIRE(list.getLength() == list2.getLength());

}

TEST_CASE( "Test", "[ArrayList]" ) {

  ArrayList<int> list;

}

TEST_CASE( "Test Insert", "[ArrayList]" ) 
{
  ArrayList<int> list;
  REQUIRE(list.insert(0,1));
  REQUIRE(list.insert(1,2));
  REQUIRE(list.insert(2,3));
  REQUIRE(list.getEntry(0) == 1);

}

TEST_CASE( "Test remove", "[ArrayList]" ) {

  ArrayList<int> list;
  list.insert(0,2);
  list.insert(1,1);
  REQUIRE(list.remove(1));

}

TEST_CASE( "Test Get and Set", "[ArrayList]" ) {

  ArrayList<int> list;
  list.insert(0,3);
  list.insert(1,4);
  list.insert(2,1);

  REQUIRE(list.getEntry(2) == 1);

  list.setEntry(2,2);

  REQUIRE(list.getEntry(2) == 2);
  
}