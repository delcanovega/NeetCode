#include <cassert>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:

    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        if (!node_by_key.contains(key)) {
            return -1;
        }
        recently_used.erase(node_by_key[key].second);
        recently_used.push_back(key);
        node_by_key[key].second = --recently_used.end();
        return node_by_key[key].first;
    }
    
    void put(int key, int value) {
        if (node_by_key.contains(key)) {
            recently_used.erase(node_by_key[key].second);
        } else if (node_by_key.size() == max_size) {
            node_by_key.erase(recently_used.front());
            recently_used.pop_front();
        }
        recently_used.push_back(key);
        node_by_key[key] = {value, --recently_used.end()};
    }

private:

    list<int> recently_used;  // recently used keys
    unordered_map<int, pair<int,list<int>::iterator>> node_by_key;  // {key, <value, &node>}
    size_t max_size;

};

int main() {
    LRUCache cache(2);

    cache.put(1, 10);               // cache: {1=10}
    assert(cache.get(1) == 10);     // return 10
    cache.put(2, 20);               // cache: {1=10, 2=20}
    cache.put(3, 30);               // cache: {2=20, 3=30}, key=1 was evicted
    assert(cache.get(2) == 20);     // returns 20 
    assert(cache.get(1) == -1);     // return -1 (not found)

    return 0;
}