//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

#include "ISort.h"

class HeapSort : public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;
};

#endif //SORT_HEAPSORT_H
