//
// Created by Administrator on 2021/4/3.
//

#ifndef SORT_TESTMAIN_H
#define SORT_TESTMAIN_H

#include <vector>
#include <functional>

using sort_func_type = std::function<std::vector<int>(const std::vector<int> &)>;
using sort_inplace_func_type = std::function<void(std::vector<int> &)>;

class Test{
public:
    static void main();


public:
    static std::vector<int> generate_random_array(int minimum, int maximum, int number);
    static std::vector<int> generate_ordered_array(int minimum, int maximum, int number);

    static bool is_array_ordered(const std::vector<int> & input);
    static void print_array(const std::string & prefix, const std::vector<int>& input);

public:
    static std::vector<int> sort(const std::vector<int>& input, const sort_func_type& func);
    static void sort_inplace(std::vector<int>& input, const sort_inplace_func_type& func);
};

#endif //SORT_TESTMAIN_H
