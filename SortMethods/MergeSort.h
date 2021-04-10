//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

#include "ISort.h"

class MergeSort : public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;

    void sort_inplace(std::vector<int> &input) override;

private:
    void mergeSort(std::vector<int> & output, int left, int right);
    void merge(std::vector<int> & output, int left, int mid, int right);

    void printSorted(const std::vector<int> & input, int left, int right);
};

#endif //SORT_MERGESORT_H
