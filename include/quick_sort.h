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
        auto partition = quick_sort_partition(begin, end);
    };
private:
    using iter_type = typename T::iterator;

    // Partition and sort the given range, following the quick sort algorithm
    // Returns a pointer to the new location of the partition element.
    iter_type quick_sort_partition(iter_type begin, iter_type end) {
        //TODO need size check here as soon as we recurse...
        auto pkey = begin;
        auto ikey = begin;
        auto jkey = end + 1;        // Starting out off the array!

        do
        {
            do
            {
                ++ikey;
                if (ikey == end)
                {
                    break;
                }
            } while (*ikey < *pkey);
            do
            {
                --jkey;
                if (jkey == pkey)
                {
                    break;
                }
            } while (*jkey > *pkey);
            if (jkey < ikey)
            {
                break;
            }
        } while(0);
        std::iter_swap(pkey, jkey);
        return jkey;        // Return the new partition
    };
    T& data_;
};

#endif
