class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() ; 
int sum = 0 ; 
        sort(nums.begin(), nums.end());

        int i =0 ; 
        int j = n-1;

        int mid = (i+j)/2 ;

        for(int i = 0 ; i<n ; i++){
            sum+=abs(nums[i]-nums[mid]);

        }
        return sum ; 

    }
};