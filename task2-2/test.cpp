#define CATCH_CONFIG_MAIN
#include<C:\Users\Ivan\Desktop\catch.hpp>
#include"tree.h"

TEST_CASE("TEST 1", "[tag1]"){
    //проверка на максимальный элемент
    int keys[] = {35, 7, 69, 100, 96, 25, 69, 15};
    Heap<int> heap;
    for(int i = 0; i< 8; i++){
        heap.insert(keys[i], 0);
    }
    REQUIRE(heap.extract() == make_pair(100, 0));
}

TEST_CASE("TEST 2", "[tag2]"){
    //попытка вытолкнуть из пустой кучи
    Heap<int> heap;
    REQUIRE_THROWS(heap.extract());
}

TEST_CASE("TEST 3", "[tag3]"){
    Heap<int> A;
    int keys[] = {35, 7, 69, 100, 96, 25, 65, 15};
    int values[] = {1, 1, 1, 1, 1, 1, 1, 1};
    vector<pair<int, int>> v;

    for(int i=0; i<8; i++){
        v.push_back(make_pair(keys[i], values[i]));
    }

    int sort_keys[] = {100, 96, 69, 65, 35, 25, 15, 7};
    vector<pair<int, int>> true_v;
    for(int i=0; i<8; i++){
        true_v.push_back(make_pair(sort_keys[i], values[i]));
    }
    REQUIRE(A.heapsort(v) == true_v);
}