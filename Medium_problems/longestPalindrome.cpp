
/*

	Example 1:

	Input: s = "babad"
	Output: "bab"
	Explanation: "aba" is also a valid answer.

	Example 2:

	Input: s = "cbbd"
	Output: "bb"

	 

	Constraints:

	    1 <= s.length <= 1000
	    s consist of only digits and English letters.



THOUGHTS : 
	the palindrome can't be bigger then the (s.length / 2)
	

	the hard coded solution will have a large time complexity where you would have to check for every char 

*/


#include <string>

using namespace std;

class Solution {

	private: 
		string expandPalindrome(string &s, int len, int right, int left) {
			while(left >= 0 && right <= len && s[right] == s[left])
			{
				--left;
				++right;
			}
			return s.substr(left + 1, right - left - 1);
		}
	
	public:
		string longestPalindrome(string s) {
			string largestStr;
			int len = s.length();
			if (len <= 1)
				return s;
			for (int i = 0; i < len; ++i) {
				string odd = expandPalindrome(s, len, i, i);
				string even = expandPalindrome(s, len, i, i + 1);

				if (odd.length() > largestStr.length())
					largestStr = odd;
				if (even.length() > largestStr.length())
					largestStr = even;
			}
			return largestStr;
		}
};





