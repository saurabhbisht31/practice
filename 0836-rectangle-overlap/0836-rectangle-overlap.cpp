class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        int left  = max(rec1[0], rec2[0]);
        int right = min(rec1[2], rec2[2]);

        int sum1 = right-left ; 
      
      int bottom = max(rec1[1], rec2[1]);
      int top = min(rec1[3], rec2[3]);

int sum2 = top-bottom ; 


return sum1>0&&sum2>0;
    }
};