#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test adding a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("Test add string", "[FindPalindrome]"){
	FindPalindrome b;
	REQUIRE(b.add("string"));
	REQUIRE(!b.add("string."));
	REQUIRE(!b.add("-string"));
	REQUIRE(!b.add("str+ing"));
}

TEST_CASE("Test add string vector", "[FindPalindrome]")
{
	FindPalindrome b;

	std::vector<std::string> v;
	v.push_back("dad");
	v.push_back("mom");            
	REQUIRE(b.add(v));

}

TEST_CASE("test cutTest2", "[FindPalindrome]")
{
	FindPalindrome b;

	std::vector<std::string> v1;
	v1.push_back("ddd");
	v1.push_back("aaa");

	std::vector<std::string> v2;
	v2.push_back("ada");
	v2.push_back("dad");

	REQUIRE(b.cutTest2(v1,v2));


	v1.pop_back();
	v2.pop_back();
	REQUIRE(!b.cutTest2(v2,v1));

}

TEST_CASE("test cutTest1", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> v;

	v.push_back("abab");
	v.push_back("cdcd");

	REQUIRE(b.cutTest1(v));

	v.pop_back();
	v.pop_back();
	v.push_back("abba");
	REQUIRE(b.cutTest1(v));

	v.push_back("bbbbba");
	REQUIRE(!b.cutTest1(v));


}
