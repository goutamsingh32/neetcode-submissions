class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0)
            return 0;

        Set<Integer> set = new HashSet<>();
        for (int i : nums) {
            set.add(i);
        }
        int count = 1;
        int ans = 1;
        
        for(int s: set){
            if(!set.contains(s-1)){
                int curr = s;
                int streak = 1;
                while(set.contains(curr + 1)){
                    curr++;
                    streak++;
                }
                ans = Math.max(ans, streak);
            }
        }

        return ans;
    }
}
