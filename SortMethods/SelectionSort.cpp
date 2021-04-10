//
// Created by Administrator on 2021/4/3.
//

#include "SelectionSort.h"

std::vector<int> SelectionSort::sort(const std::vector<int> &input) {
    std::vector<int> res = input;

    sort_inplace(res);

    return res;
}

void SelectionSort::sort_inplace(std::vector<int> &input) {
    for(int i = 0; i < input.size(); ++i)
    {
        // 找到当前位置最小的值得index号，之后交换
        int minimum_index = i;

        for(int j = i; j < input.size(); ++j)
        {
            if(input[minimum_index] > input[j])
            {
                minimum_index = j;
            }
        }

        std::swap(input[minimum_index], input[i]);
    }
}
