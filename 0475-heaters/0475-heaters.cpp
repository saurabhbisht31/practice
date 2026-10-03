class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;

        for (int i = 0; i < houses.size(); i++) {
            int mini = INT_MAX;

            for (int j = 0; j < heaters.size(); j++) {
                int dist = abs(houses[i] - heaters[j]);
                mini = min(mini, dist);
            }

            ans = max(ans, mini);
        }

        return ans;
    }
};