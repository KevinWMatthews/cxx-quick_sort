add_library(quick_sort
    "${CMAKE_HOME_DIRECTORY}/include/quick_sort.h"
)
target_include_directories(quick_sort
    PUBLIC "${CMAKE_HOME_DIRECTORY}/include"
)
set_target_properties(quick_sort
    PROPERTIES LINKER_LANGUAGE CXX
)
add_library(QuickSort::QuickSort ALIAS quick_sort)
