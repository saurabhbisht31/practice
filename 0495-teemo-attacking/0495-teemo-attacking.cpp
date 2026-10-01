
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        if(duration == 0) {
            return 0;
        }

        int sum = duration;

        for(int i = 1; i < timeSeries.size(); i++) {

            int diff = timeSeries[i] - timeSeries[i-1];

if(diff >= duration) {
sum += duration;
            }
    else {
     sum += diff;
            }
        }

        return sum;
    }
};