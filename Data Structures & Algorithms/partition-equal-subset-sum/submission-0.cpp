class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i: nums){
            totalSum+=i;
        }
        if(totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        unordered_set<int> s;
        s.insert(0);
        for(auto i: nums){
            unordered_set<int> temp;
            for(int j: s){
                if(j + i == target) return true;
                temp.insert(j + i);
                temp.insert(j);
            }
            s = temp;
        }
        return false;
    }
};
