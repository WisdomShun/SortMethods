//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_INSERTIONSORT_H
#define SORT_INSERTIONSORT_H

#include "ISort.h"

class InsertionSort : public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;

    void sort_inplace(std::vector<int> &input) override;

    int find_position_2_insert(const std::vector<int> &input, int start_index, int end_index, int target2insert);
};

#endif //SORT_INSERTIONSORT_H
