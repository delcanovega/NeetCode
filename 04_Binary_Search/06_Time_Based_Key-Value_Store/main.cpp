#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> values = store[key];
        string result = "";

        int l = 0;
        int r = values.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            pair<int, string> val = values[m];
            if (val.first < timestamp) {
                result = val.second;
                l = m + 1;
            } else if (val.first > timestamp) {
                r = m - 1;
            } else {
                return val.second;
            }
        }
        return result;
    }
private:
    unordered_map<string, vector<pair<int, string>>> store;
};

int main() {
    TimeMap tm = TimeMap();
    tm.set("alice", "happy", 1);
    assert(tm.get("alice", 1) == "happy");
    assert(tm.get("alice", 2) == "happy");
    tm.set("alice", "sad", 3);
    assert(tm.get("alice", 3) == "sad");

    return 0;
}
