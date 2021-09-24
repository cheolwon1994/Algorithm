import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_bj_2636_ДЎБо {
	public static class Info{
		int x,y;
		public Info(int y, int x) {
			this.y=y;
			this.x=x;
		}
	}
	static Queue<Info> q;
	static int arr[][],row,col,before,result=0;
	static boolean check[][];
	final static int dx[]= {0,1,0,-1};
	final static int dy[]= {-1,0,1,0};
	static boolean finish=false;
	
	static void cal() {
		int t_result = 0;
		for (int i = 0; i < row; i++) 
			for (int j = 0; j < col; j++)
				if (arr[i][j] == 1)
					t_result++;
		if (t_result == 0) finish = true;
		else before = t_result;
	}

	static void spread() {
		int len = q.size();
		for(int k=0;k<len;k++){
			Info ii = q.poll();
			int cx = ii.x;
			int cy = ii.y;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx]==1) {
					q.offer(new Info(ny,nx));
					arr[ny][nx] = 0;
				}
			}
		}
	}

	static void find_uncheck() {
		check = new boolean[row][col];
		Queue<Info> tq = new LinkedList<>();
		tq.offer(new Info(0,0));
		q.offer(new Info(0,0));
		check[0][0] = true;
		while (!tq.isEmpty()) {
			Info ii = tq.poll();
			int cx = ii.x;
			int cy = ii.y;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx] && arr[ny][nx] == 0) {
					check[ny][nx] = true;
					tq.offer(new Info(ny,nx));
					q.offer(new Info(ny,nx));
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());
		arr = new int[row][col];
		q = new LinkedList<>();
		
		for(int i=0;i<row;i++) {
			s = br.readLine();
			st = new StringTokenizer(s);
			for(int j=0;j<col;j++)
				arr[i][j]=Integer.parseInt(st.nextToken());
		}
		while(true) {
			result++;
			cal();
			if(finish) {
				result-=1;
				break;
			}
			find_uncheck();
			spread();
		}
		System.out.println(result);
		System.out.println(before);
	}
}
