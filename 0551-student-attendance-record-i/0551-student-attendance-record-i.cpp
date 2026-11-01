class Solution {
public:
    bool checkRecord(string s) {
        
        unordered_map<char , int>freq; 
        for(char ch: s){
            freq[ch]++;

        }
        if(freq['A']>=2){
            return false; 

        }
        for(int i =0 ; i<s.size()-1 ; i++){
            if(s[i]=='L'&& s[i+1]=='L'&&s[i+2]=='L'){
                return false; 

            }
        }
        return true ; 
        

    }
};