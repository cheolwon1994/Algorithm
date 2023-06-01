import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        int num = players.length;
        String[] ranking = new String[num];
        HashMap<String, Integer> map = new HashMap<>();
        for(int i=0;i<num;i++){
            String s = players[i];
            map.put(s,i);
            ranking[i] = s;
        }
        for(int i=0;i<callings.length;i++){
            String player = callings[i];
            int curRank = map.get(player);
            String upperRankPlayer = ranking[curRank-1];
            
            map.put(player,curRank-1);
            map.put(upperRankPlayer,curRank);
            
            ranking[curRank]=upperRankPlayer;
            ranking[curRank-1]=player;
        }
        return ranking;
    }
}
