#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero_counter = 0;
        for (int num: nums) {
            if (num != 0) {
                product *= num;
            } else {
                zero_counter++;
            }
        }
        vector<int> products;
        for (int num: nums) {
            if (zero_counter > 0) {
                if (num != 0 || zero_counter > 1) {
                    products.push_back(0);
                } else {
                    products.push_back(product);
                }
            } else {
                products.push_back(product / num);
            }
        } 
        return products;
    }

};


int main() {
    Solution sol;

    vector<int> test_1{1,2,4,6};
    vector<int> test_1_solution{48,24,12,8};
    assert(sol.productExceptSelf(test_1) == test_1_solution);

    vector<int> test_2{-1,0,1,2,3};
    vector<int> test_2_solution{0,-6,0,0,0};
    assert(sol.productExceptSelf(test_2) == test_2_solution);
    
    return 0;
}
