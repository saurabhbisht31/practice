class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size() - 1;
        int idx = -1;

        for(int i = n; i >= 0; i--) {
      if(num[i] != '0') {
   idx = i;
                break;
            }
        }

        return num.substr(0, idx + 1);
    }
};