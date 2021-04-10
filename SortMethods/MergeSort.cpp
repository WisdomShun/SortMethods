//
// Created by Administrator on 2021/4/3.
//

#include "MergeSort.h"

#include <cstdio>
#include <string>

std::vector<int> MergeSort::sort(const std::vector<int> &input) {
    std::vector<int> res;

    sort_inplace(res);

    return res;
}

void MergeSort::sort_inplace(std::vector<int> &input) {
    mergeSort(input, 0, input.size()-1);
}

void MergeSort::merge(std::vector<int> &output, int left, int mid, int right) {
    // 对[left, mid] 和 [mid+1, right] 两部分进行归并

    std::vector<int> buffered(right - left + 1);
    std::copy(output.begin() + left, output.begin() + right + 1, buffered.begin());

    int j = left, k = mid + 1;

    // printf("l : %d, m : %d, r : %d\t", left, mid, right);
    for(int i = left; i <= right; ++i)
    {
        int j_offset = j - left;
        int k_offset = k - left;

        if(j > mid) // 左半部分归并完成
        {
            output[i] = buffered[k_offset];
            k++;
        } else if(k > right) // 右半部分归并完成
        {
            output[i] = buffered[j_offset];
            j++;
        } else if (buffered[j_offset] <= buffered[k_offset]){
            output[i] = buffered[j_offset];
            j++;
        } else {
            output[i] = buffered[k_offset];
            k++;
        }
    }

    // printSorted(output, left, right);
    // printSorted(output, 0, output.size() - 1);
}

void MergeSort::mergeSort(std::vector<int> &output, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(output, left, mid);
    mergeSort(output, mid + 1, right);
    if(output[mid] > output[mid + 1])
        merge(output, left, mid, right);
}

void MergeSort::printSorted(const std::vector<int> &input, int left, int right) {
    if (left > right)
        return;

    std::string str;

    for(int i = left; i <= right; ++i)
    {
        str += std::to_string(input[i]);
        str += " -> ";
    }

    if (!str.empty())
    {
        for(int i = 0; i < 4; ++i)
        {
            str.pop_back();
        }
    }

    printf("%s\n", str.c_str());
}
