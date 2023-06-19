import java.util.*;

class Solution {
    static class Info {
        int y,x;
        public Info(int y, int x){
            this.y=y;
            this.x=x;
        }
    }
    static int row,col,answer;
    static int destX[], destY[];        //S,L,E 순서
    static final int dx[]={0,1,0,-1};
    static final int dy[]={-1,0,1,0};
    
    public boolean canGo(int sy,int sx, int ty, int tx, String[] maps){
        int flag[][] = new int[row][col];
        for(int i=0;i<row;i++)
        	Arrays.fill(flag[i],100*100+1);
        flag[sy][sx] = 0;
        Queue<Info> q = new LinkedList<>();
        q.offer(new Info(sy,sx));
        
        while(!q.isEmpty()){
            Info ii = q.poll();
            int cx = ii.x;
            int cy = ii.y;
            int cv = flag[cy][cx];
            if(cx==tx && cy==ty){
                answer += cv;
                return true;
            }
            for(int i=0;i<4;i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx>=0 && ny>=0 && nx<col && ny<row && flag[ny][nx]>cv+1){
                    char nc = maps[ny].charAt(nx);
                    if(nc=='X') continue;
                    flag[ny][nx]=cv+1;
                    q.offer(new Info(ny,nx));
                }
            }
        }
        return false;
    }
    
    public int solution(String[] maps) {
        //초기화
        answer = 0;
        row = maps.length;
        col = maps[0].length();
        destY = new int[3];
        destX = new int[3];
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                char c = maps[i].charAt(j);
                if(c=='S'){
                    destY[0]=i;
                    destX[0]=j;
                }
                else if(c=='L'){
                    destY[1]=i;
                    destX[1]=j;
                }
                else if(c=='E'){
                    destY[2]=i;
                    destX[2]=j;
                }
            }
        }
        if(canGo(destY[0],destX[0],destY[1],destX[1],maps)){
            if(!canGo(destY[1],destX[1],destY[2],destX[2],maps))
                answer = -1;
        }
        else {
        	answer = -1;
        }
        
        return answer;
    }
}
