#define CATCH_CONFIG_MAIN
#include "iostream"
#include "cstdio"
#include <ctime>
#include "Stack.h"
#include <vector>
#include <algorithm>
#include <catch.hpp>
using namespace std;

//#include "../catch.hpp"
TEST_CASE("1","[tag1]")
{
Stack<int> s(5);
s.Push(10);
s.Push(10);
REQUIRE(s.Size()==2);
}

TEST_CASE("2", "[tag2]")
{
Stack<int> s(5);

REQUIRE(s.Size()==0);
}

TEST_CASE("3","[tag3]")
{
srand(time(NULL));

Stack<int> s(3);
for (int i =0;i<3;i++)
s.Push(rand() % 10);

s.Clear();
REQUIRE(s.Size()==0);

}

TEST_CASE("4", "[tag4]")
{
Stack<int> s(0);


REQUIRE(s.Pop()==false);

REQUIRE(s.Push(10)==false);
}

TEST_CASE("5","[tag5]")
{
srand(time(NULL));

Stack<int> s(5);
int i;
for (int i =0;i<5;i++)
s.Push(i);
for (int i =4;i>-1;i--)
REQUIRE(s.Pop()==i);


REQUIRE(s.Size()==0);

s.Pop();
REQUIRE(s.Pop()==false);
}

TEST_CASE("6","[tag6]")
{
srand(time(NULL));

Stack<int> s(5);
s.Clear();

REQUIRE("Stack is empty");

}

TEST_CASE("7","[tag7]")
{
srand(time(NULL));

Stack<int> s(5);
for (int i =0;i<4;i++)
s.Push(rand() % 10);
int a = rand()%100;
s.Push(a);
REQUIRE(s.Pop()==a);

}

TEST_CASE("8","[tag8]")
{
srand(time(NULL));

Stack<int> s(5);
for (int i =0;i<4;i++)
s.Push(rand() % 10);
s.Clear();
for (int i =0;i<4;i++)
s.Pop();

REQUIRE(s.Size()==0);

}

TEST_CASE("9","[tag9]")
{
Stack<int> s(2);
for (int i =0;i<3;i++)
s.Push(10);
REQUIRE(s.Push(10)==false);
REQUIRE(s.Size()==2);
}