//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_BINARYSORT_H
#define SORT_BINARYSORT_H

#include "ISort.h"

class BinarySort: public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;
};

#endif //SORT_BINARYSORT_H
