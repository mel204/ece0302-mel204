#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

// test constructors

TEST_CASE("Test constructors", "[DynamicBag]"){
  DynamicBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
  
}

TEST_CASE("Test overloaded operator", "[DynamicBag]"){

  DynamicBag<int> b2;
  DynamicBag<int> b1 = b2;

  REQUIRE(b1.getCurrentSize() == b2.getCurrentSize());

}

TEST_CASE("Test swap", "[DynamicBag]"){

  DynamicBag<int> b2;
  DynamicBag<int> b1;


}

TEST_CASE("Test add", "[DynamicBag]"){

  DynamicBag<int> b;
  REQUIRE(b.add(1));
  REQUIRE(b.getCurrentSize() == 1 );

}

TEST_CASE("Test remove", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(1);
  b.add(2);
  b.add(3);
  REQUIRE(b.getCurrentSize() == 3 );
  REQUIRE(b.remove(3));
}

TEST_CASE("Test isEmpty", "[DynamicBag]"){
  DynamicBag<int> b;

  REQUIRE(b.isEmpty());

}

TEST_CASE("Test contains", "[DynamicBag]"){
   DynamicBag<int> b;
   b.add(3);
   b.add(5);
   REQUIRE(b.getCurrentSize() == 2 );
   REQUIRE(b.contains(3));
   REQUIRE(!b.contains(4));
}

TEST_CASE("Test getFrequencyOf", "[DynamicBag]"){
   DynamicBag<int> b;
   b.add(3);
   b.add(3);
   b.add(2);

   REQUIRE(b.getCurrentSize() == 3 );
   REQUIRE(b.getFrequencyOf(3) == 2);
   REQUIRE(b.getFrequencyOf(2) == 1);

}

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}
