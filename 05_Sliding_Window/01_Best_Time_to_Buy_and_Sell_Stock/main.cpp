#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        size_t l = 0;
        size_t r = 1;
        while (r < prices.size()) {
            if (prices[l] > prices[r]) {
                l = r;
            }
            max_profit = max(max_profit, prices[r] - prices[l]);
            r++;
        } 
        return max_profit;
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {10,1,5,6,7,1};
    assert(sol.maxProfit(test_1) == 6);

    vector<int> test_2 = {10,8,7,5,2};
    assert(sol.maxProfit(test_2) == 0);

    return 0;
}
