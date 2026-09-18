class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<bool> isvalid(26, true);
        vector<string> result;

    
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if (start[idx] == -1) {
                start[idx] = i;
            }

            end[idx] = i;
        }

    
        for (int c = 0; c < 26; c++) {
            if (start[c] == -1)
                continue;

            int l = start[c];
            int r = end[c];

            for (int i = l; i <= r; i++) {
                int idx = s[i] - 'a';

            
                if (start[idx] < l) {
                    isvalid[c] = false;
                    break;
                }

         
                r = max(r, end[idx]);
            }

            end[c] = r;
        }

        int lastTakenStart = n;

        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (!isvalid[c])
                continue;

            if (i == start[c] && end[c] < lastTakenStart) {
                result.push_back(s.substr(i, end[c] - i + 1));
                lastTakenStart = i;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};