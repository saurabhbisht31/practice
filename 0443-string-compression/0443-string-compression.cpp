class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        vector<char>ans ; 



int count = 1;
    for(int i = 1; i<n ; i++){
     
        if(chars[i-1]==chars[i]){
count++;

        }
        else{
ans.push_back(chars[i-1]);
if(count>1){
    string s= to_string(count);

    for(char c :s){
        ans.push_back(c);

    }
}
count = 1; 
        }
    }

    ans.push_back(chars[n-1]);
    if(count>1){
        string s= to_string(count);
        for(char c:s){
            ans.push_back(c);
        }
    }
    chars = ans ; 
    return ans.size();


    
        
    }
};