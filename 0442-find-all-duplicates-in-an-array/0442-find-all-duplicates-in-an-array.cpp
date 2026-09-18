class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
int n = nums.size();
        vector<int>freq(n+1, 0);
        for(int x:nums){
            freq[x]++;
        }
set<int>s;
        for(int i =1 ; i<=nums.size();i++){
            if(freq[i]==2){
                s.insert(i);
            }
        }
        vector<int>ans(s.begin(), s.end());

        
        return ans ; 
    }
};