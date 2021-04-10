//
// Created by Administrator on 2021/4/3.
//

#include "InsertionSort.h"

std::vector<int> InsertionSort::sort(const std::vector<int> &input) {
    std::vector<int> res = input;

    sort_inplace(res);

    return res;
}

void InsertionSort::sort_inplace(std::vector<int> &input) {
    if (input.size() <= 1)
    {
        return;
    }

    for (int i = 1; i < input.size(); ++i) {
        int current_value = input[i];

        int j = 0;
        for (j = i - 1; j >= 0; --j) {
            if(input[j] > current_value)
            {
                // 还未找到插入位置
                input[j+1] = input[j];
            } else {
                break;
            }
        }

        input[j+1] = current_value;
    }
}

int InsertionSort::find_position_2_insert(const std::vector<int> &input, int start_index, int end_index, int target2insert) {
    // 折半查找插入位置
    int low = input[start_index];
    int high = input[end_index];

    while (low <= high)
    {
        int middle_index = start_index + (end_index - start_index) / 2;
        int middle = input[middle_index];

        if(middle == target2insert)
        {
            return middle_index;
        } else if(middle < target2insert)
        {
            // 查找的中间值比较小，从右侧继续查找
            low = input[middle_index];
        } else {
            // 查找的中间值比较大，从左侧继续查找
            high = input[middle_index];
        }
    }

    return start_index;
}
