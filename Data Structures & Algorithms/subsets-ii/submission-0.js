class Solution {
    set = new Set();
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    subsetsWithDup(nums) {
        const n = nums.length;
        for (let i = 0; i < n; i++) {
            this.solve(nums, i, []);
        }
        return Array.from(this.set).map((item) => JSON.parse(item));
    }
    solve(nums, i, subset) {
        if (i > nums.length) return;
        const arr = subset.sort((a, b) => a - b);
        this.set.add(JSON.stringify(arr));
        this.solve(nums, i + 1, [...subset, nums[i]]);
        this.solve(nums, i + 1, [...subset]);
    }
}
