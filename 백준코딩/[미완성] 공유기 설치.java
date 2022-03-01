import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;


public class  {
	
	static int num,plant;
	static int arr[];
	
	static boolean check(int mid) {
		int cnt=0;
		for(int i=0;i<num-1;i++) {
			if(arr[i+1]-arr[i]>mid) {
				cnt++;
				if(cnt>plant) return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		
		num = Integer.parseInt(st.nextToken());
		plant = Integer.parseInt(st.nextToken());
		arr = new int[num];
		
		for(int i=0;i<num;i++)
			arr[i] = Integer.parseInt(br.readLine().trim());
		Arrays.sort(arr);
		
		int l = 0, r=num,mid,answer=0;
		while(l<=r) {
			mid = l +(r-l)/2;
			if(check(mid)) {
				System.out.println("mid: "+mid);
				answer = mid;
				l = mid+1;
				
			}
			else r = mid-1;
		}
		System.out.println(answer);
	}
}
