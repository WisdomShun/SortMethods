//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_RADIXSORT_H
#define SORT_RADIXSORT_H

#include "ISort.h"

class RadixSort : public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;
};

#endif //SORT_RADIXSORT_H
