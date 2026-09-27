class Solution {
public:
    string reverseParentheses(string s) {
        while (true) {
            int j = s.find(')');
            if (j == string::npos) break; 
            
            int i = j - 1;
            while (s[i] != '(') i--;  
            
            string temp = s.substr(i + 1, j - i - 1);
            reverse(temp.begin(), temp.end());
            
            s = s.substr(0, i) + temp + s.substr(j + 1);
        }
        return s;
    }
};