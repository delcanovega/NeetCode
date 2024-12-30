#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "_" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        istringstream iss(s);

        while (true) {
            int len;
            if (!(iss >> len)) {
                break;
            }
            iss.ignore(1);  // Ignore the separator
            if (len == 0) {
                decoded.push_back("");
            } else {
                char decoded_str[len + 1];
                iss.get(decoded_str, len + 1);
                decoded.push_back(decoded_str);
            }
        }
        return decoded;
    }

};


int main() {
    Solution sol;

    vector<string> test_1{"neet","code","love","you"};
    assert(sol.decode(sol.encode(test_1)) == test_1);

    vector<string> test_2{"we","say",":","yes"};
    assert(sol.decode(sol.encode(test_2)) == test_2);

    vector<string> test_3{"","   ","!@#$%^&*()_+","LongStringWithNoSpaces","Another, String With, Commas"};
    assert(sol.decode(sol.encode(test_3)) == test_3);
    
    return 0;
}
