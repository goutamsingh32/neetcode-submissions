class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        // wordList.add(beginWord)
        int n = wordList.size();
        Map<String, Integer> mp = new HashMap<>();
        int nodeCount = 0;
        int source = -1;
        int dest = -1;

        mp.put(beginWord, nodeCount);
        source = nodeCount;
        nodeCount++;
        for (int i = 0; i < n; i++) {
            if(mp.containsKey(wordList.get(i))) continue;
            mp.put(wordList.get(i), nodeCount);
            if (wordList.get(i).equals(endWord)) {
                dest = nodeCount;
            }
            nodeCount++;
        }
        System.out.println(source);
        System.out.println(dest);
        if (dest == -1)
            return 0;

        System.out.println(mp);
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < nodeCount; i++) {
            adj.add(new ArrayList<>());
        }

        List<String> keyList = new ArrayList<>(mp.keySet());
        for (int i = 0; i < keyList.size(); i++) {
            for (int j = i + 1; j < keyList.size(); j++) {
                if (isValidEdge(keyList.get(i), keyList.get(j))) {
                    int p = mp.get(keyList.get(i));
                    int q = mp.get(keyList.get(j));

                    adj.get(p).add(q);
                    adj.get(q).add(p);
                }
            }
        }

        System.out.println(adj);
        int[] vis = new int[keyList.size()];

        Queue<Integer> queue = new LinkedList<>();
        int count = 1;

        // Base case: if source is already the destination
        if (source == dest)
            return count;

        queue.add(source);
        queue.add(null);
        vis[source] = 1;
        while (!queue.isEmpty()) {
            Integer node = queue.poll();
            if (node == null) {
                count++;
                if (!queue.isEmpty()) {
                    queue.add(null);
                }
            } else {
                for (int x : adj.get(node)) {
                    if (vis[x] == 0) {
                        if (x == dest) {
                            return count + 1;
                        }
                        vis[x] = 1;
                        queue.add(x);
                    }
                }
            }
        }
        return 0;
    }

    public boolean isValidEdge(String s1, String s2) {
        if (s1.length() != s2.length())
            return false;
        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diff++;
            }
            if (diff > 1)
                return false;
        }
        return true;
    }
}
