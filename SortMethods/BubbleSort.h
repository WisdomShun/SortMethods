//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_BUBBLESORT_H
#define SORT_BUBBLESORT_H

#include "ISort.h"

class BubbleSort: public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;

    void sort_inplace(std::vector<int> &input) override;
};

#endif //SORT_BUBBLESORT_H
