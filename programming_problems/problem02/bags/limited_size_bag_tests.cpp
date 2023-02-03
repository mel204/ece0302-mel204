#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

// test constructors

TEST_CASE("Test constructors", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
  
}

TEST_CASE("Test overloaded operator", "[LimitedSizeBag]"){

  LimitedSizeBag<int> b2;
  LimitedSizeBag<int> b1 = b2;

  REQUIRE(b1.getCurrentSize() == b2.getCurrentSize());

}

TEST_CASE("Test swap", "[LimitedSizeBag]"){

  LimitedSizeBag<int> b1;
  LimitedSizeBag<int> b2;


}

TEST_CASE("Test add", "[LimitedSizeBag]"){

  LimitedSizeBag<int> b;
  REQUIRE(b.add(1));
  REQUIRE(b.getCurrentSize() == 1 );

}

TEST_CASE("Test remove", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  b.add(1);
  b.add(2);
  b.add(3);
  REQUIRE(b.getCurrentSize() == 3 );
  REQUIRE(b.remove(3));
}

TEST_CASE("Test isEmpty", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.isEmpty());

}

TEST_CASE("Test contains", "[LimitedSizeBag]"){
   LimitedSizeBag<int> b;
   b.add(3);
   b.add(5);
   REQUIRE(b.getCurrentSize() == 2 );
   REQUIRE(b.contains(3));
   REQUIRE(!b.contains(4));
}

TEST_CASE("Test getFrequencyOf", "[LimitedSizeBag]"){
    LimitedSizeBag<int> b;
   b.add(3);
   b.add(3);
   b.add(2);

   REQUIRE(b.getCurrentSize() == 3 );
   REQUIRE(b.getFrequencyOf(3) == 2);
   REQUIRE(b.getFrequencyOf(2) == 1);

}

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;    

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}
