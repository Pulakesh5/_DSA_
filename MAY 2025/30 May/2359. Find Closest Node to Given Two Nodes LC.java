class Solution {
    public int[] findDistance(int[] edges, int src)
    {
        int N = edges.length;
        int[] distance = new int[N];
        Arrays.fill(distance, -1);
        distance[src] = 0;
        int node = src, dist=0;

        while(true)
        {
            node = edges[node];
            System.out.println(node);
            if(node==-1 || distance[node]!=-1)
                break;
            distance[node] = ++dist;
        }
        return distance;
    }

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int[] distance1 = findDistance(edges, node1);
        int[] distance2 = findDistance(edges, node2);

        int N = edges.length;
        int meetingDistance = N+1, meetingNode = N+1;
        for(int i=0; i<N; i++)
        {
            if(distance1[i]==-1 || distance2[i]==-1)
                continue;
            
            // System.out.println(i+" "+distance1[i]+" "+distance2[i]);

            if(Math.max(distance1[i], distance2[i])<meetingDistance)
            {
                meetingDistance = Math.max(distance1[i], distance2[i]);
                meetingNode = i;
            }
            else if(Math.max(distance1[i], distance2[i])==meetingDistance)
            {
                meetingDistance = Math.max(distance1[i], distance2[i]);
                meetingNode = Math.min(meetingNode, i);
            }
        }
        return ( meetingNode==(N+1) ? -1 : meetingNode);
    }
}
