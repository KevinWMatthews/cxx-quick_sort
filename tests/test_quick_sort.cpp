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

class QuickSortTwoElementsTest : public ::testing::Test
{
protected:
    using data_type = array<int, 2>;
};

TEST_F(QuickSortTwoElementsTest, IdentialElementsAreAlreadySorted)
{
    data_type expected = {10, 10};
    data_type actual   = {10, 10};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortTwoElementsTest, SortedElementsRemainSorted)
{
    data_type expected = {10, 11};
    data_type actual   = {10, 11};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortTwoElementsTest, UnsortedElementsGetSorted)
{
    data_type expected = {10, 11};
    data_type actual   = {11, 10};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}


class QuickSortThreeElementsTest : public ::testing::Test
{
protected:
    using data_type = array<int, 3>;
};

TEST_F(QuickSortThreeElementsTest, IdentialElementsAreAlreadySorted)
{
    data_type expected = {10, 10, 10};
    data_type actual   = {10, 10, 10};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortThreeElementsTest, RemainSortedIfFirstPairIdentical)
{
    data_type expected = {10, 10, 11};
    data_type actual   = {10, 10, 11};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortThreeElementsTest, RemainSortedIfSecondPairIdentical)
{
    data_type expected = {10, 12, 12};
    data_type actual   = {10, 12, 12};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortThreeElementsTest, UniqueElementsRemainSorted)
{
    data_type expected = {10, 11, 12};
    data_type actual   = {10, 11, 12};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortThreeElementsTest, SortsFirstPairOfElements)
{
    data_type expected = {10, 11, 12};
    data_type actual   = {11, 10, 12};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortThreeElementsTest, SortsSecondPairOfElements)
{
    data_type expected = {10, 11, 12};
    data_type actual   = {10, 12, 11};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortThreeElementsTest, MiddleElementMovesToBeginning)
{
    data_type expected = {10, 11, 11};
    data_type actual   = {11, 10, 11};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortThreeElementsTest, MiddleElementMovesToEnd)
{
    data_type expected = {10, 10, 12};
    data_type actual   = {10, 12, 10};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortThreeElementsTest, WorstCaseGetsSorted)
{
    data_type expected = {10, 11, 12};
    data_type actual   = {12, 11, 10};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

class QuickSortFourElementTest : public ::testing::Test
{
protected:
    using data_type = array<int, 4>;
};

TEST_F(QuickSortFourElementTest, WorstCaseGetsSorted)
{
    data_type expected = {10, 11, 12, 13};
    data_type actual   = {13, 12, 11, 10};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortFourElementTest, PairSort1)
{
    data_type expected = {10, 11, 12, 13};
    data_type actual   = {11, 10, 13, 12};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortFourElementTest, PairSort2)
{
    data_type expected = {10, 11, 12, 13};
    data_type actual   = {12, 13, 10, 11};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(QuickSortFourElementTest, PairSort3)
{
    data_type expected = {10, 11, 12, 13};
    data_type actual   = {10, 12, 13, 11};
    QuickSort<data_type> quick_sort = {actual};
    quick_sort.sort();
    ASSERT_EQ(expected, actual);
}
