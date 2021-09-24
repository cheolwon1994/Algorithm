import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main_bj_1062_°¡¸£Ä§ {
	static int test,num,tmp,result=0;
	static int alpha[];
	static List<String> li;
	
	static void find(int start, int cnt) {
		if (cnt == num - 5) {
			int temp = 0;
			for (int i = 0; i < test; i++) {
				boolean flag = true;
				String str = li.get(i);
				for (int j = 0; j < li.get(i).length(); j++) {
					int idx = str.charAt(j)-'a';
					if (alpha[idx] != 1) {
						flag = false;
						break;
					}
				}
				if (flag)
					temp++;
			}
			result = Math.max(result, temp);
			return;
		}
		for (int i = start; i < 26; i++) {
			if (alpha[i] != 1) {
				alpha[i] = 1;
				find(i+1,cnt + 1);
				alpha[i] = 0;
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		alpha =new int[26];
		li = new ArrayList<>();
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		test = Integer.parseInt(st.nextToken());
		num = Integer.parseInt(st.nextToken());
		
		for (int t = 0; t < test; t++) {
			String ss = br.readLine().trim();
			String str_tmp = ss.substring(4);
			li.add(str_tmp);
		}
		
		alpha['a' - 'a'] = 1;
		alpha['c' - 'a'] = 1;
		alpha['i' - 'a'] = 1;
		alpha['n' - 'a'] = 1;
		alpha['t' - 'a'] = 1;
		find(0,0);
		System.out.println(result);
	}
}
