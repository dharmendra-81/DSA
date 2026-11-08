class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int ind = -1;
        int i;

        for(i = n-1; i >= 0 ; i--){
          if( (num[i] - '0') % 2 == 1){
            ind = i;
            break;
          }
        }   
        //skip leading zeroes
        i = 0;
        while( i <= ind && num[i] == '0') i++;
        //return substr from i to ind
        return num.substr(i, ind-i+1);
    }
};