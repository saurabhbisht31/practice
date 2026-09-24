class Solution {
public:
    int hammingDistance(int x, int y) {
       int diff= __builtin_popcount(x^y);

       return diff ; 
    }
};