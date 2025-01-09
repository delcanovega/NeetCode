#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (!isalnum(s[i])) {
                i++;
            }
            while (!isalnum(s[j])) {
                j--;
            }
            if (i < j && tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


int main() {
    Solution sol;

    string test_1 = "Was it a car or a cat I saw?";
    assert(sol.isPalindrome(test_1));

    string test_2 = "tab a cat";
    assert(!sol.isPalindrome(test_2));

    return 0;
}
