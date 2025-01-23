#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int largest = 0;
        for (int pile: piles) {
            largest = max(pile, largest);
        }

        int l = 1;
        int r = largest;
        int k = largest;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (is_valid_solution(piles, h, m)) {
                k = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return k;
    }

private:
    bool is_valid_solution(vector<int>& piles, int h, int k) {
        int t = 0;
        for (int pile: piles) {
            t += ceil(pile / (double) k);
        }
        return t <= h;
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {1,4,3,2};
    assert(sol.minEatingSpeed(test_1, 9) == 2);

    vector<int> test_2 = {25,10,23,4};
    assert(sol.minEatingSpeed(test_2, 4) == 25);

    return 0;
}
