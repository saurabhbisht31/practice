class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
for (char c : s) {
            if (c == '(') {
                st.push('(');
            }else {
    if (!st.empty()) {
                    st.pop();
        }
        else {
                    count++;
         }
            }
        }

        while (!st.empty()) {
            count++;
            st.pop();
        }

        return count;
    }
};