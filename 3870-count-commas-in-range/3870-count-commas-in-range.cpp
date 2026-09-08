class Solution {
public:
    int countCommas(int n) {
        if(n<1000){
            return  0 ; 
        }

        int sum = n-1000 ; 
        return sum+1; 

       
    }
};