class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size(); 
        vector<int>freq(n+1, 0);

        for(int x:nums){
            freq[x]++;
        }
        set<int>st;
        for(int i =0 ; i<n ; i++){
            if(freq[i]==2){
                st.insert(i);
            }
        }
        vector<int>ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans ; 
    }
};