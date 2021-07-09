class B{
    class Solution {
        class Node{
            int d,s;
            double time;
            public Node(int d,int s){
                this.d = d;
                this.s = s;
                this.time = d * 1.0 / s;
            }
        }
        public int eliminateMaximum(int[] dist, int[] speed) {
        int n = dist.length;
        Node[] nodes = new Node[n];
        for(int i = 0; i < n; i++){
            nodes[i] = new Node(dist[i], speed[i]);
        }
        Arrays.sort(nodes,(o1,o2) -> Double.compare(o1.time,o2.time);
        int ans = n;
        for(int i = 0; i <n ; i++){
            if(i <= nodes[i].time){
                ans = i;
                break;
            }
        }
        return ans;
        }
    }
}