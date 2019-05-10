#define CATCH_CONFIG_MAIN
#include "task2-3.h"
#include <vector>
#include <string>
#include "C:\Users\Ivan\Desktop\catch.hpp"
#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;
using namespace std::chrono;
TEST_CASE("1", "R-K"){
    vector<int> vector1;
    fstream in;
    in.open("C:/Users/Ivan/ClionProjects/task2-3/strings.txt");
    string s1;
    string s2;
    if(in.is_open()) {
        while (!in.eof()) {
            in >> s1;
            in >> s2;
            cout << s1 << endl << s2 << endl;
        }
    }
    vector1.push_back(Rabin_Karp_Matcher(s1, s2, 234,7));
    vector<int> vector2;
    vector2.push_back(Naive_String_Matcher(s1, s2));
    in.close();
    REQUIRE(vector1 == vector2);
}

TEST_CASE("2", "R-K - N"){
    vector<int> vector1;
    vector<int> vector2;
    fstream in;
    in.open("C:/Users/Ivan/ClionProjects/task2-3/long_strings.txt");
    string s1;
    string s2;
    if(in.is_open()) {
        while (!in.eof()) {
            in >> s1;
            in >> s2;
            cout << s1 << endl << s2 << endl;
        }
    }
    vector1.push_back(Rabin_Karp_Matcher(s1, s2, 31,31));
    vector2.push_back(Naive_String_Matcher(s1, s2));
    in.close();
    REQUIRE(vector1 == vector2);
}

TEST_CASE("3", "Time"){
    fstream in;
    in.open("C:/Users/Ivan/ClionProjects/task2-3/long_strings.txt");
    string s1;
    string s2;
    if(in.is_open()) {
        while (!in.eof()) {
            getline(in, s1);
            in >> s2;
            cout << s1 << endl << s2 << endl;
        }
    }
    auto start1 = steady_clock::now();
    Rabin_Karp_Matcher(s1, s2, 31, 10001);
    auto end1 = steady_clock::now();
    auto elapsed1 = duration_cast<nanoseconds>(end1 - start1);

    auto start2 = steady_clock::now();
    Naive_String_Matcher(s1, s2);
    auto end2 = steady_clock::now();
    auto elapsed2 = duration_cast<nanoseconds>(end2 - start2);

    REQUIRE(elapsed1<elapsed2);
}