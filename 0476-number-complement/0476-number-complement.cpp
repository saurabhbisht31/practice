class Solution {
public:
    int findComplement(int num) {
        string binary = "";

        while(num > 0){
            binary += (num % 2) + '0';
            num = num / 2;
        }

        reverse(binary.begin(), binary.end());

        string convert = "";
 for(char c : binary){
            if(c == '0'){
                convert += '1';
            }
            else{
                convert += '0';
            }
        }

        int ans = 0;

        for(char c : convert){
            ans = ans * 2 + (c - '0');
        }

        return ans;
    }
};