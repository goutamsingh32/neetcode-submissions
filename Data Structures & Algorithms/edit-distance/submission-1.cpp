class Solution {
public:
    int ans;
    int minDistance(string word1, string word2) {
        ans = INT_MAX;
        solve(word1, word2, "",0,0,0);
        return ans;
    }

    void solve(string word1, string word2, string temp, int idx, int idx2, int cnt){
        if(temp.length() == word2.length()){
            cnt += word1.length() - idx;
            if(word2 == temp){
                ans = min(ans,cnt);
                return;
            } else return;
        }
        if(idx == word1.length()){
            cnt+= word2.length() - idx2;
            ans = min(ans,cnt);
        }
        if(idx > word1.length() || idx2 > word2.length()) return;

        int tempIdx = 0;
        while(tempIdx < temp.length()){
            if(temp[tempIdx] != word2[tempIdx]) return;
            tempIdx++;
        }

        if(word2[idx2] == word1[idx]){
            solve(word1, word2, temp + word1[idx], idx+1, idx2+1, cnt);
        } else{
            solve(word1, word2, temp, idx+1, idx2, cnt+1); // Delete
            solve(word1, word2, temp + word2[idx2], idx, idx2 + 1, cnt+1);
            solve(word1, word2, temp + word2[idx2], idx + 1, idx2 + 1, cnt+1);
        }
    }
};
