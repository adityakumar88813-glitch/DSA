class Solution {
public:
       
       int start = 0, maxLength = 0;

       void expand(string &s , int left , int right){

        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        int len = right-left - 1;
        if(len > maxLength){
            maxLength = len;
            start = left+1;
        }
       }




    string longestPalindrome(string s) {
        int n = s.size();
        for(int i= 0 ; i <n ; i++){

            expand(s , i , i); // odd lemgth ke liye

             expand(s , i , i+1); // even length ke liye

        }

        return s.substr(start , maxLength);
    }
};