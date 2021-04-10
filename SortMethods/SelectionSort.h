//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_SELECTIONSORT_H
#define SORT_SELECTIONSORT_H

#include "ISort.h"

class SelectionSort : public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;

    void sort_inplace(std::vector<int> &input) override;
};

#endif //SORT_SELECTIONSORT_H
