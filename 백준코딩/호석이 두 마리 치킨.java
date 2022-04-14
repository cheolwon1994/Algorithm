import java.io.*;
import java.util.*;

public class 호석이두마리치킨 {
	final static int MAX = 987654321;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num, edge, answer = MAX;
		StringTokenizer st = new StringTokenizer(br.readLine());
		num = Integer.parseInt(st.nextToken());
		edge = Integer.parseInt(st.nextToken());

		int arr[][] = new int[num+1][num+1];
		List<Integer> result = new ArrayList<>();

		for(int i=1;i<=num;i++)
			for(int j=i+1;j<=num;j++) {
				arr[i][j]=MAX;
				arr[j][i]=MAX;
			}
		
		for (int i = 0; i < edge; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[a][b]=1;
			arr[b][a]=1;
		}
		
		for(int k=1;k<=num;k++)
			for(int i=1;i<=num;i++)
				for(int j=1;j<=num;j++)
					arr[i][j] = Math.min(arr[i][j], arr[i][k]+arr[k][j]);
		
		for (int i = 1; i < num; i++) {
			for (int j = i + 1; j <= num; j++) {
				int sum = 0;
				for(int k=1;k<=num;k++) {
					if(k==i || k==j) continue;
					sum+=2*Math.min(arr[i][k], arr[j][k]);
				}
				if (sum < answer) {
					answer = sum;
					result = new ArrayList<>();
					result.add(i);
					result.add(j);
				}
			}
		}
		System.out.print(result.get(0) + " " + result.get(1) + " " + answer);
	}
}
