class Solution {
public:
    int ans = 0;
    int countSubstrings(string s) {
        int n = s.length();
        for(int i=0;i<n;i++){
            solve(i,i,s);
            solve(i,i+1,s);
        }
        return ans;
    }

    void solve(int i, int j, string s){
        while(i>= 0 && j<s.length() && s[i] == s[j]){
            ans++;
            i--;j++;
        }
        return;
        
    }
};
