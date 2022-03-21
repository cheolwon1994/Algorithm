import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st = new StringTokenizer(br.readLine());
	    int a = Integer.parseInt(st.nextToken());
	    int b = Integer.parseInt(st.nextToken());
	    HashSet<String> set = new HashSet<>();
	    for(int i=0;i<a;i++){
	        set.add(br.readLine());
	    }
	    for(int i=0;i<b;i++){
	        String str = br.readLine();
	        st = new StringTokenizer(str,",");
	        int cnt=0;
	        while(st.hasMoreTokens()){
	            String ss = st.nextToken();
	            if(set.contains(ss)){
	                set.remove(ss);
	            }
	        }
	        System.out.println(set.size());
	    }
	}
}
