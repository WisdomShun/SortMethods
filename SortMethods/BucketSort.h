//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_BUCKETSORT_H
#define SORT_BUCKETSORT_H

#include "ISort.h"

class BucketSort: public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;
};

#endif //SORT_BUCKETSORT_H
