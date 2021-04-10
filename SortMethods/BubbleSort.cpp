//
// Created by Administrator on 2021/4/3.
//

#include "BubbleSort.h"

#include <algorithm>

std::vector<int> BubbleSort::sort(const std::vector<int> &input) {
    std::vector<int> res = input;

    sort_inplace(res);

    return res;
}

void BubbleSort::sort_inplace(std::vector<int> &input) {
    for (int i = 0; i < input.size(); ++i) {
        for(int j = i; j < input.size(); ++j)
        {
            if(input[i] > input[j])
            {
                std::swap(input[i], input[j]);
            }
        }
    }
}
