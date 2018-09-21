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

        // What happens if size is 1? Aren't we off the array?
        auto pkey = data_.begin();
        auto ikey = pkey;
        auto jkey = data_.end();        // Starting out off the array!
        auto end = data_.end() - 1;     // Stop while pointing to valid data

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
    };
private:
    T& data_;
};

#endif
