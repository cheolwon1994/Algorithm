import java.util.*;
import java.io.*;

class Solution {
    final static int maxi = 987654321;
    final static int dx[] = {0,1,0,-1};
    final static int dy[] = {-1,0,1,0};
    
    static class Info{
        int y,x,val;
        public Info(int y, int x, int val){
            this.y=y;
            this.x=x;
            this.val=val;
        }
    };
    
    public int solution(int[][] maps) {
        int row = maps.length;
        int col = maps[0].length;
        int answer = -1;
        if(maps[0][0]==0 || maps[row-1][col-1]==0) return answer;
        
        boolean check[][] = new boolean[row][col];
        Queue<Info> q = new LinkedList<>();
        check[0][0]=true;
        q.offer(new Info(0,0,1));
        
        while(!q.isEmpty()){
            Info ii = q.poll();
            int cx = ii.x;
            int cy = ii.y;
            int cv = ii.val;
            if(cx==col-1 && cy==row-1){
                answer = cv;
                break;
            }
            for(int i=0;i<4;i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx>=0 && ny>=0 && nx<col && ny<row && maps[ny][nx]==1 && !check[ny][nx]){
                    check[ny][nx]=true;
                    q.offer(new Info(ny,nx,cv+1));
                }
            }
        }
        return answer;
    }
}
