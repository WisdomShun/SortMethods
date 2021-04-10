//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_SHELLSORT_H
#define SORT_SHELLSORT_H

#include "ISort.h"

class ShellSort : public ISort
{
public:
    std::vector<int> sort(const std::vector<int> &input) override;
};

#endif //SORT_SHELLSORT_H
