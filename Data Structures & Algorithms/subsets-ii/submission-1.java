class Solution {
    Set<List<Integer>> set = new HashSet<>();
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        set.clear();

        Arrays.sort(nums);
        List<Integer> list = new ArrayList<>();

        solve(nums, 0, list);

        List<List<Integer>> ans = new ArrayList<>();

        for (List<Integer> subset : set) {
            ans.add(subset);
        }
        return ans;
    }

    public void solve(int[] nums, int start, List<Integer> curr) {
        int n = nums.length;
        set.add(new ArrayList<>(curr));
        for (int i = start; i < n; i++) {
            curr.add(nums[i]);
            solve(nums, i + 1, curr);
            curr.remove(curr.size() - 1);
        }
    }
}
