#define CATCH_CONFIG_MAIN
#include "task2-3.h"
#include <vector>
#include <string>
#include "C:\Users\Ivan\Desktop\catch.hpp"
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
TEST_CASE("1", "R-K"){
    vector<int> vector1;
    vector1.push_back(Rabin_Karp_Matcher("abcabaabcabac", "abaa", 234, 7));
    vector<int> vector2;
    vector2.push_back(Naive_String_Matcher("abcabaabcabac", "abaa"));
    REQUIRE(vector1 == vector2);
}

TEST_CASE("2", "R-K - N"){
    vector<int> vector1;
    vector<int> vector2;
    string s1;
    s1.resize(100);
    srand(time(NULL));
    for(int i=0; i!=s1.size(); ++i){
        s1[i] = (char)(21 + rand()%234);
    }
    string s2;
    s2.resize(3);
    for(int i=0; i!=s2.size(); ++i){
        s2[i] = (char)( rand()% 234 +21);
    }
    vector1.push_back(Rabin_Karp_Matcher(s1, s2, 31, 31));
    vector2.push_back(Naive_String_Matcher(s1, s2));
    REQUIRE(vector1 == vector2);
}

TEST_CASE("TEST 3", "[tag3]"){
    string s1;
    s1.resize(500);
    for(int i=0; i!=s1.size(); ++i){
        s1[i] = (char)(21 + rand()%234);
    }
    string s2;
    s2.resize(3);
    for(int i=0; i!=s2.size(); ++i){
        s2[i] = (char)( rand()% 234 +21);
    }

    auto start1 = steady_clock::now();
    Rabin_Karp_Matcher(s1, s2, 1, 1000);
    auto end1 = steady_clock::now();
    auto elapsed1 = duration_cast<nanoseconds>(end1 - start1);

    auto start2 = steady_clock::now();
    Naive_String_Matcher(s1, s2);
    auto end2 = steady_clock::now();
    auto elapsed2 = duration_cast<nanoseconds>(end2 - start2);

    REQUIRE(elapsed1<elapsed2);
}