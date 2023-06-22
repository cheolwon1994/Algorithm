import java.util.*;

class Solution {
    static class Info {
        int y,x;
        public Info(int y, int x){
            this.y=y;
            this.x=x;
        }
    }
    static final int dx[]={0,1,0,-1};
    static final int dy[]={-1,0,1,0};
    
    public int[] solution(String[] maps) {
        List<Integer> li = new LinkedList<>();
        int row = maps.length;
        int col = maps[0].length();
        boolean[][] flag = new boolean[row][col];
        Queue<Info> q = new LinkedList<>();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!flag[i][j]){
                    char c = maps[i].charAt(j);
                    flag[i][j]=true;
                    if(c=='X') continue;
                    int food = c-'0';
                    q.offer(new Info(i,j));
                    
                    while(!q.isEmpty()){
                        Info ii = q.poll();
                        int cx = ii.x;
                        int cy = ii.y;
                        for(int k=0;k<4;k++){
                            int nx = cx+dx[k];
                            int ny = cy+dy[k];
                            if(nx>=0 && ny>=0 && nx<col && ny<row && !flag[ny][nx]){
                                flag[ny][nx]=true;
                                char nc = maps[ny].charAt(nx);
                                if(nc=='X') continue;
                                food+=(nc-'0');
                                q.offer(new Info(ny,nx));
                            }
                        }
                    }
                    li.add(food);
                }
            }
        }
        int len = li.size();
        if(len==0){
            int[] answer = {-1};
            return answer;
        }
        Collections.sort(li);
        int[] answer = new int[len];
        for(int i=0;i<len;i++)
            answer[i]=li.get(i);
        
        return answer;
    }
}
