#include <random>
#include <algorithm>
#include "TestMain.h"

#include "AllSortMethods.h"

#include "Timer.h"

#define SPEC_SORT(SORT_METHOD_NAME) \
{                                   \
    auto random_array = generate_random_array(random_minimum, random_maximum, random_number);                                \
    SORT_METHOD_NAME sorter;                                            \
    print_array("Before : ", random_array);   \
    {                                                                   \
        Timer t;                                                        \
        sort_inplace(random_array, std::bind(&SORT_METHOD_NAME::sort_inplace, sorter, std::placeholders::_1)); \
    }                                                                   \
    print_array("After : ", random_array);           \
    if (!random_array.empty() && is_array_ordered(random_array))                    \
    {                                                                   \
        printf("%s Succeed !\n", #SORT_METHOD_NAME);                        \
    } else {                                                            \
        printf("%s Failed !\n", #SORT_METHOD_NAME);                         \
    }                               \
    printf("---------------------\n");                                  \
}
std::vector<int> Test::generate_random_array(int minimum, int maximum, int number) {
    std::random_device r;
    std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937       eng(seed); // a source of random data

    std::uniform_int_distribution<int> dist;
    std::vector<int> v(number);

    std::generate(v.begin(), v.end(), bind(dist, eng));

    for(int & iter : v)
    {
        iter = minimum + (iter % (maximum - minimum));
    }

    return v;
}

std::vector<int> Test::generate_ordered_array(int minimum, int maximum, int number) {
    auto required_array = generate_random_array(minimum, maximum, number);

    std::sort(required_array.begin(), required_array.end());

    return required_array;
}

bool Test::is_array_ordered(const std::vector<int> &input) {
    if(input.empty() || 1 == input.size())
    {
        return true;
    }

    bool is_increase = false;

    // 找到第一个和arr[0]值为不同的值
    for (int i = 1; i < input.size(); ++i) {
        if(input[i] != input[0])
        {
            if (input[0] < input[i])
            {
                is_increase = true;
            }
            break;
        }
    }

    for(auto iter = input.begin(); iter != input.end() - 1; ++iter)
    {
        auto first = *iter;
        auto second = *(iter+1);
        if(is_increase)
        {
            if (first > second)
                return false;
        } else{
            if (first < second)
                return false;
        }
    }

    return true;
}

void Test::print_array(const std::string & prefix, const std::vector<int> &input) {
    std::string prt;

    for(const auto & each:input)
    {
        prt += std::to_string(each);
        prt += " -> ";
    }

    if(!prt.empty())
    {
        for (int i = 0; i < 4; ++i) {
            prt.pop_back();
        }
    }

    printf("%slen : %d, arr : %s\n", prefix.c_str(), input.size(), prt.c_str());
}

std::vector<int> Test::sort(const std::vector<int> &input, const sort_func_type& func) {
    return func(input);
}

void Test::sort_inplace(std::vector<int> &input, const sort_inplace_func_type &func) {
    func(input);
}

void Test::main() {
    int random_minimum = -100;
    int random_maximum = 100;
    int random_number = 20;

    SPEC_SORT(BubbleSort);
    SPEC_SORT(SelectionSort);
    SPEC_SORT(InsertionSort);
    SPEC_SORT(MergeSort);
    SPEC_SORT(QuickSort);
}


