#include <iostream>
#include "Collection.h"

using namespace std;

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

namespace sdds 
{
    template<typename t1, typename t2>
    bool check(t1* array, int index, t2 key)
    {
        return array[index] == key;
    }

    template<typename t1, typename t2>
    bool search(t1* array, int size, t2 key, Collection<t1>& c)
    {
        bool res = false;
        for (int i = 0; i < size; i++)
        {
            if (check(array, i, key))
            {
                c.add(array[i]);
                    res = true;
            }
        }
        return res;
    }

    template <typename t>
    void listArrayElements(const char* title, t* array, int size)
    {
        cout << title << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ": " << array[i] << endl;
        }
    }

    template <typename t1>
    bool sizeCheck(Collection<t1>& c1, Collection<t1>& c2)
    {
        return c1.size() > c2.size();
    }
}
#endif // !SDDS_SEARCH_H_

