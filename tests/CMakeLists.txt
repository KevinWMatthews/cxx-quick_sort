add_executable(test_quick_sort
    test_quick_sort.cpp
)
target_link_libraries(test_quick_sort
    PRIVATE QuickSort::QuickSort
    PRIVATE GTest::GTest GTest::Main
)
add_test(
    NAME test_quick_sort
    COMMAND test_quick_sort
)
