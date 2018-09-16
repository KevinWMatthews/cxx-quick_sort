#include "quick_sort.h"
#include <gtest/gtest.h>

using namespace std;

class QuickSortZeroElementsTest : public ::testing::Test
{
protected:
    using data_type = array<int, 0>;
};

TEST_F(QuickSortZeroElementsTest, DoNotCrashWithNoElements)
{
    data_type expected = {};
    data_type actual   = {};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

class QuickSortOneElementTest : public ::testing::Test
{
protected:
    using data_type = array<int, 1>;
};

TEST_F(QuickSortOneElementTest, SingleElementIsAlreadySorted)
{
    data_type expected = {10};
    data_type actual   = {10};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}
