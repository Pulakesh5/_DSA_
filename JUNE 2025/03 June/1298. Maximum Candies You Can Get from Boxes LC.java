class Solution {
        public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int res = 0;
        Queue<Integer> q = new LinkedList<>();
        for (int i : initialBoxes)
            if ((status[i] += 5000) > 5000)
                q.add(i);
        while (q.size() > 0) {
            int b = q.remove();
            res += candies[b];
            for (int i : keys[b])
                if ((status[i] += 5) == 5005)
                    q.add(i);
            for (int i : containedBoxes[b])
                if ((status[i] += 5000) > 5000)
                    q.add(i);
        }
        return res;
    }
}
