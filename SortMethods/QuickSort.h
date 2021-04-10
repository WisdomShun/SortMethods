//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

#include "ISort.h"

class QuickSort : public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;

    void sort_inplace(std::vector<int> &input) override;

private:
    void quickSort(std::vector<int> & arr, int left, int right);

    int partition1(std::vector<int>& arr, int left, int right);
    int partition2(std::vector<int>& arr, int left, int right);
    int partition3(std::vector<int>& arr, int left, int right);


    void printArray(const std::string & prefix, const std::vector<int> & input, int left, int right);
};

#endif //SORT_QUICKSORT_H
