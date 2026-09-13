class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n = img1.size();
int ans = 0 ;
        for(int rowshift = -(n-1); rowshift<=n-1 ; rowshift++){
            for(int colshift = -(n-1) ; colshift<= n-1 ; colshift++){
                int overlap = 0 ; 
for(int i = 0 ; i<n ; i++){
    for(int j = 0 ; j<n ; j++){

       
if(img1[i][j]==1){
    int newrow = i+rowshift ;
     int newcol = j+colshift ; 



if(newrow>=0 && newrow<n &&newcol>=0 && newcol<n){
    if(img2[newrow][newcol]==1){
        overlap++;

    }
}
   
    }
}
            }
            ans = max(ans , overlap);

        }
        
    }

return ans ; 
    }

};