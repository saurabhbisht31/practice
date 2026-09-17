class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int>freq; 
        for(int i =0 ; i<s.size(); i++){
            freq[s[i]]++;

        }

vector<pair<int,int>>v(freq.begin(), freq.end());
sort(v.begin(), v.end() , [](auto&a, auto&b){
    return a.second > b.second  ; 

});

string temp="";
for(int i =0 ; i<v.size(); i++){
while(v[i].second){
    temp.push_back(v[i].first);
    v[i].second-- ; 


}
}
return temp ; 
    }
};