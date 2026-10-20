class Solution {
public:
    vector<int> buildLPS(vector<int>& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } 
            else if (len > 0) {
                len = lps[len - 1];
            } 
            else {
                lps[i++] = 0;
            }
        }

        return lps;
    }

    bool isRotation(vector<int>& a, vector<int>& b) {
        int k = a.size();

        vector<int> lps = buildLPS(b);

        int i = 0, j = 0;

        while (i < 2 * k - 1) {
            if (a[i % k] == b[j]) {
                i++;
                j++;

                if (j == k) {
                    return true;
                }
            } 
            else if (j > 0) {
                j = lps[j - 1];
            } 
            else {
                i++;
            }
        }

        return false;
    }

    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        long long result = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                vector<int> a(nums.begin() + start,
                              nums.begin() + start + k);

                vector<int> b(sorted.begin() + start,
                              sorted.begin() + start + k);

                if (!isRotation(a, b)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result += k;
            }
        }

        return result;
    }
};