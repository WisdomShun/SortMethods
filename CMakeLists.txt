cmake_minimum_required(VERSION 3.17)
project(Sort)

set(CMAKE_CXX_STANDARD 11)

include_directories(. SortMethods)

aux_source_directory(SortMethods SORT_LIBS)
add_library(MySort STATIC ${SORT_LIBS})

aux_source_directory(. SRCS)
add_executable(Sort ${SRCS})
target_link_libraries(Sort MySort)