class Solution {
    public int mostBooked(int n, int[][] meetings) {
        // code here
        // sorting meetings in ascending order of start time
        Arrays.sort(meetings, (a,b)->Integer.compare(a[0], b[0]));
        
        PriorityQueue<Integer> availableRooms = new PriorityQueue<>();
        for(int i=0; i<n; i++)
            availableRooms.offer(i);
            
        // busyRooms maintains a priorityQueue with earliest available time and room number
        PriorityQueue<int[]> busyRooms = new PriorityQueue<>((a,b) -> {
            if(a[0]!=b[0])  return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });
        
        int[] meetingServed = new int[n];
        
        for(int[] meeting:meetings)
        {
            int start = meeting[0], end = meeting[1];
            int room, meetDuration = end-start;;
            while(!busyRooms.isEmpty() && busyRooms.peek()[0]<=start) // putting empty rooms into availableRooms
            {
                availableRooms.offer(busyRooms.poll()[1]);
            }
            
            if(!availableRooms.isEmpty()) // room is available
            {
                room = availableRooms.poll();
                busyRooms.offer(new int[]{end, room});
            }
            else
            {
                int[] nextFree = busyRooms.poll();
                room = nextFree[1];
                busyRooms.offer(new int[]{nextFree[0]+meetDuration, room});
            }
            meetingServed[room]++;
        }
        
        int roomServedMax = 0, countServedMax = meetingServed[0];
        for(int i=1; i<n; i++)
        {
            if(meetingServed[i]>countServedMax)
            {
                countServedMax = meetingServed[i];
                roomServedMax = i;
            }
        }
        return roomServedMax;
    }
}
