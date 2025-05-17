class Solution {
    public ArrayList<Integer> sortArray(int[] arr, int A, int B, int C) {
        // Code here
        int N = arr.length, x;
        for(int i=0; i<N; i++)
        {
            x = arr[i];
            arr[i] = (A*x*x + B*x + C);
        }
        Arrays.sort(arr);
        ArrayList<Integer> list = new ArrayList<>();
        for(int num:arr)
            list.add(num);
        return list;
    }
}
