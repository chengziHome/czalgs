//
// Created by chengzi on 18-7-17.
//

#include <iostream>
#include "sort.cpp"
#include "basic.cpp"
#include <vector>
#include <string>
#include <sstream>
#include "tree_test.cpp"

int main(){

    int a[20] = {5,3,90,122,1,6,8,3,4,5,23,1,33,55,78,12};
    int len = sizeof(a)/sizeof(a[0]);

//    Sort::insertionSort(a,sizeof(a)/sizeof(a[0]));
//    Sort::selectionSort(a, sizeof(a)/ sizeof(a[0]));
    std::vector<int> av(a,a+len);
//    std::vector<int> aux(len);
//    Divide::mergeSort(av,aux,0, len);
//    printVector(av,len);
//    printVector(aux,len);
//    Divide::testFindMaxSubarray();
//    Sort::testHeapSort();
//        Sort::testQuickSort();

    czalgs::TreeTest::testBST();



}

