class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())return 0;
        return solve(s1,s2,s3,"",0,0,0) || solve(s1,s2,s3,"",0,0,1);
    }

    bool solve(string s1, string s2, string s3, string temp, int idx1, int idx2, bool flag){
        if(temp.length() > s3.length()) return 0;
        if(temp == s3) return 1;
        if(idx1 > s1.length() || idx2 > s2.length()) return 0;
        bool check = 0;
        if(flag){
            for(int i=1; i<=s1.length() - idx1; i++){
                string str = s1.substr(idx1,i);
                check = check || solve(s1, s2, s3, temp + str, idx1 + i, idx2, flag ^ 1);
                if(check)break;
            }
        } else{
            for(int i=1; i<=s2.length()-idx2; i++){
                string str = s2.substr(idx2,i);
                check = check || solve(s1, s2, s3, temp + str, idx1, idx2 + i, flag ^ 1);
                if(check) break;
            }
        }
        return check;

    }
};
