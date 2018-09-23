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

        auto pkey = begin;
        auto ikey = begin;
        auto jkey = end + 1;        // Starting out off the array!

        do
        {
            left_partition(ikey, end, pkey);
            right_partition(jkey, begin, pkey);
            if (have_iterators_crossed(ikey, jkey))
            {
                break;
            }
            std::iter_swap(ikey, jkey);
        } while(1);
        std::iter_swap(pkey, jkey);

        auto new_pkey = jkey;
        // Sort before and after the partition element's new position.
        // The partition element is already in the correct location,
        // so don't include it in the sort.
        quick_sort(begin, new_pkey-1);
        quick_sort(new_pkey+1, end);
    };
    void left_partition(iter_type& left, const iter_type& end, const iter_type& partition) {
        do
        {
            ++left;
            if (left == end)
            {
                break;
            }
        } while (*left < *partition);
    };
    void right_partition(iter_type& right, const iter_type& begin, const iter_type& partition) {
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
