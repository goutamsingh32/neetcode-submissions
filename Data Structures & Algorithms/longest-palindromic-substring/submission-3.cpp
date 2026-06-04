class Solution {
public:
    int maxStart = 0;
    int maxLen = 1;
    string longestPalindrome(string s) {
        int n = s.length();
        for(int i = 0;i<n-1;i++){
            solve(i,i,s);
            solve(i,i+1,s);
        }
        return s.substr(maxStart,maxLen);
    }

    void solve(int i ,int j,string s){
        int len = 0;
        if(i==j) len-=1;
        while(i>=0 && j <s.length()  && s[i] == s[j]){
            i--;j++;
            len+=2;
        }
        
        if(len > maxLen){
            maxLen = len;
            maxStart = i + 1;
        }
    }

};
