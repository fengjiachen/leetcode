// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

// The cache is initialized with a positive capacity.
#include <iostream>
#include <vector>

using namespace std;

class LRUCache
{
private:
    vector<int> k;
    vector<int> v;
    int cap;

public:
    LRUCache(int capacity) : k(capacity, -1), v(capacity, -1)
    {
        cap = capacity;
    }
    int find(int key)
    {
        for (int i = 0; i < (int)k.size(); i++)
        {
            if (k[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
    int get(int key)
    {
        int ans = -1;
        int index = find(key);
        if (index != -1)
        {
            ans = v[index];
            k.erase(k.begin() + index);
            v.erase(v.begin() + index);
            k.insert(k.begin(), key);
            v.insert(v.begin(), ans);
        }
        return ans;
    }

    void put(int key, int value)
    {
        int index = find(key);
        if (index == -1)
        {
            if ((int)k.size() < cap)
            {
                k.insert(k.begin(), key);
                v.insert(v.begin(), value);
            }
            else
            {
                k.pop_back();
                v.pop_back();
                k.insert(k.begin(), key);
                v.insert(v.begin(), value);
            }
        }
        else
        {
            k.erase(k.begin() + index);
            v.erase(v.begin() + index);
            k.insert(k.begin(), key);
            v.insert(v.begin(), value);
        }
    }
    void print()
    {
        for (int i = 0; i < (int)k.size(); i++)
        {
            cout << "i=" << i << " key=" << k[i] << " value=" << v[i] << endl;
        }
    }
};

int main()
{
    LRUCache cache(2);
    cache.put(2, 1);
    cache.print();
    cache.put(1, 1);
    cache.print();
    cout << cache.get(2) << endl; // returns 1
    cache.print();
    cache.put(4, 1); // evicts key 2
    cache.print();
    cout << cache.get(1) << endl;
    cache.print();
    cout << cache.get(2) << endl;
    cache.print();
}