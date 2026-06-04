class Solution {
public:
    int ans = 0;
    int numDistinct(string s, string t) {
        solve(s,0,"",t);
        return ans;
    }

    void solve(string s, int idx, string temp, string t){
        if(idx > s.length()) return;
        if(temp.length() > t.length()) return;
        if(temp.length() == t.length()){
            if(temp == t) ans++;
            return;
        }
        solve(s, idx + 1, temp, t);
        solve(s,idx+1, temp+s[idx],t);
    }
};
