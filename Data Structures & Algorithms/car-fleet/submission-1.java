class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        Map<Integer, Double> mp = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            double time = (double) (target - position[i]) / speed[i];
            mp.put(-position[i], time);
        }
        int ans = 0;
        double maxTime = 0;

        for (Map.Entry<Integer, Double> entry : mp.entrySet()) {
            double value = entry.getValue();
            if (maxTime < value) {
                ans++;
                maxTime = value;
            }
        }
        return ans;
    }
}
