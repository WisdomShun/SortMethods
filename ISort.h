//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_ISORT_H
#define SORT_ISORT_H

#include <vector>

class ISort
{
public:
    virtual std::vector<int> sort(const std::vector<int> &input) = 0;
    virtual void sort_inplace(std::vector<int> & input) = 0;
};

#endif //SORT_ISORT_H
