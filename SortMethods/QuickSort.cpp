//
// Created by Administrator on 2021/4/3.
//

#include <string>
#include "QuickSort.h"

std::vector<int> QuickSort::sort(const std::vector<int> &input) {
    std::vector<int> res = input;

    sort_inplace(res);

    return res;
}

void QuickSort::sort_inplace(std::vector<int> &input) {
    quickSort(input, 0, input.size() - 1);
}

void QuickSort::quickSort(std::vector<int> &arr, int left, int right) {
    if(left >= right)
        return;

    int pos = partition3(arr, left, right);
    quickSort(arr, left, pos - 1);
    quickSort(arr, pos + 1, right);
}

int QuickSort::partition1(std::vector<int> &arr, int left, int right) {
    // 对 [left, right] 进行快速排序
    int selected = arr[left];

    // 定义 [l+1,j] < t , [j+1, i) > t

    int j = left;

    for (int i = left + 1; i <= right; ++i) {
        if (arr[i] < selected)
        {
            std::swap(arr[j+1], arr[i]);
            j++;
        }
    }

    std::swap(arr[left], arr[j]);

    return j;
}

int QuickSort::partition2(std::vector<int> &arr, int left, int right) {
    // 定义 从[l+1, j] 均 < v, 从 [k, r] 均 >= v

    int selected = arr[left];

    printf("partition %d : ", selected);
    printArray("", arr, left, right);

    int j = left;
    int k = right + 1;

    for(int i = left + 1; i < k;)
    {
        if (j >= k)
            break;

        if(arr[i] < selected)
        {
            j++;
            i++;
        } else { // arr[i] >= selected
            std::swap(arr[k-1], arr[i]);
            k--;
        }
    }

    std::swap(arr[left], arr[j]);

    printArray("Partition OK : ", arr, left, right);

    return j;
}

int QuickSort::partition3(std::vector<int> &arr, int left, int right) {
    // 定义从 [l+1, j] < v, [j+1, i) == v, [k, r] > v

    int selected = arr[left];

    int j = left;
    int k = right + 1;

    for(int i = left + 1; i < k; )
    {
        if(j >= k)
            break;

        if (arr[i] < selected)
        {
            std::swap(arr[j + 1], arr[i]);
            j++;
            ++i;
        } else if (arr[i] > selected)
        {
            std::swap(arr[k-1], arr[i]);
            k--;
        } else {
            ++i;
        }
    }

    std::swap(arr[left], arr[j]);

    return j;
}

void QuickSort::printArray(const std::string & prefix, const std::vector<int> &input, int left, int right) {
    if (left > right)
        return;

    std::string str = prefix;

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