#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <algorithm>

template<typename T>
class QuickSort
{
public:
    QuickSort(T& data) : data_{data} {};

    void sort() {
        if (data_.empty())
            return;
        if (data_.size() == 1)
            return;

        auto begin = data_.begin();
        auto end = data_.end() - 1;     // Stop while pointing to valid data
        quick_sort(begin, end);
    };
private:
    using iter_type = typename T::iterator;

    // Partition and sort the given range, following the quick sort algorithm
    // Recursive.
    void quick_sort(iter_type begin, iter_type end) {
        if (std::distance(begin, end) < 1)
            return;

        auto partition = begin;
        auto left = begin;
        auto right = end + 1;        // Starting out off the array!

        // Walk up from the left and down from the right,
        // swapping elements if they are out of order.
        do
        {
            walk_left_partition(left, partition, end);
            walk_right_partition(right, partition, begin);
            if (have_iterators_crossed(left, right))
            {
                break;
            }
            std::iter_swap(left, right);
        } while(1);
        std::iter_swap(partition, right);

        auto new_partition = right;
        // Sort before and after the partition element's new position.
        // The partition element is already in the correct location,
        // so don't include it in the sort.
        quick_sort(begin, new_partition-1);
        quick_sort(new_partition+1, end);
    };
    // Increment left until its value exceeds that of partition.
    // Stop if end is reached.
    void walk_left_partition(iter_type& left, const iter_type& partition, const iter_type& end) {
        do
        {
            ++left;
            if (left == end)
            {
                break;
            }
        } while (*left < *partition);
    };
    // Decrement right until its value exceeds that of the partition.
    // Stop if begin is reached.
    void walk_right_partition(iter_type& right, const iter_type& partition, const iter_type& begin) {
        do
        {
            --right;
            if (right == begin)
            {
                break;
            }
        } while (*right > *partition);
    };
    bool have_iterators_crossed(iter_type left, iter_type right) {
        return right <= left;
    };
    T& data_;
};

#endif
