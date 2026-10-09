
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int yes = 0;
        vector<int> temp = score;

        sort(temp.begin(), temp.end(), greater<int>());
vector<string> ans;
for (int i = 0; i < score.size(); i++) {
            int target = score[i];
 for (int j = 0; j < temp.size(); j++) {
                if (temp[j] == target) {
                    yes = j + 1;
                    break;
                }
            }
    if (yes == 1) {
                ans.push_back("Gold Medal");
            }
              else if (yes == 2) {
                ans.push_back("Silver Medal");
            }
     else if (yes == 3) {
                ans.push_back("Bronze Medal");
            }
     else {
                ans.push_back(to_string(yes));
            }
        }

        return ans;
    }
};
