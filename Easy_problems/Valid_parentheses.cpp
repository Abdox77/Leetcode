
#include <string>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
            stack<char> st;

            for (char curr : s){
                if (st.empty() == false){
                    char last = st.top();
                    if (is_pair(last,curr) == true){
                        st.pop();
                        continue;
                    }
                }
                st.push(curr);
            }
        return st.empty();
    }
    bool is_pair(char last, char curr){
        return ((last == '{' && curr == '}') ||
                (last == '(' && curr == ')') || 
                (last == '[' && curr == ']'));
    }
};




