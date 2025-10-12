#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = 0;
        int slen =  s.length();
        int left = 0;
        unordered_map<char, int> count;

        for(int right = 0; right < slen; ++right) {
            char c = s.at(right);
            count[c] += 1;
            while (count[c] > 1) {
                char lchar = s.at(left);
                count[lchar] -= 1;
                left++;
            }
            size = max(size, right - left + 1);
        }

        return size;  
    }
};
