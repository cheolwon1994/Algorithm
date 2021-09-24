import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_bj_1753_최단경로{
	public static class Info implements Comparable<Info>{
		int idx, val;
		public Info(int idx, int val) {
			this.idx = idx;
			this.val = val;
		}
		@Override
		public int compareTo(Info o) {
			return Integer.compare(this.val, o.val);
		}
	}
	
	static List<Info> li[];
//	static boolean visit[];
	static int dist[];
	static int node,edge,start,s,e,v;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String ss = br.readLine();
		StringTokenizer st = new StringTokenizer(ss);
		node = Integer.parseInt(st.nextToken());
		edge = Integer.parseInt(st.nextToken());
		start = Integer.parseInt(br.readLine());
		
		li = new List[node+1];
		for(int i=1;i<=node;i++)
			li[i] = new ArrayList<>();
//		visit = new boolean[node+1];
		dist = new int[node+1];
		
		for(int i=1;i<=node;i++)
			dist[i]=Integer.MAX_VALUE;
		
		for(int i=1;i<=edge;i++) {
			String str = br.readLine();
			StringTokenizer st2 = new StringTokenizer(str);
			s = Integer.parseInt(st2.nextToken());
			e = Integer.parseInt(st2.nextToken());
			v = Integer.parseInt(st2.nextToken());
			li[s].add(new Info(e,v));
		}
		PriorityQueue<Info> pq = new PriorityQueue<>();
		pq.offer(new Info(start,0));
		dist[start]=0;
		Info ii;
		
		while(!pq.isEmpty()) {
			ii = pq.poll();
			int cidx = ii.idx;
			int cv = ii.val;
			if(dist[cidx]<cv) continue;
			for(int i=0;i<li[cidx].size();i++) {
				int next = li[cidx].get(i).idx;
				int nv = li[cidx].get(i).val;
				if(dist[next]>cv+nv) {
					dist[next]=cv+nv;
					pq.offer(new Info(next,nv+cv));
				}
			}
		}
		for(int i=1;i<=node;i++) {
			if(dist[i]==Integer.MAX_VALUE) System.out.println("INF");
			else System.out.println(dist[i]);
		}		
	}
}