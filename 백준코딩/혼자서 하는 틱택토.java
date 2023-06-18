import java.util.*;

class Solution {
	static int calFinishNum(String[] board, char c) {
		int canFinish = 0;

		for (int i = 0; i < 3; i++) {
			// 가로
			if (board[i].charAt(0) == c && board[i].charAt(1) == c && board[i].charAt(2) == c)
				canFinish++;
			// 세로
			if (board[0].charAt(i) == c && board[1].charAt(i) == c && board[2].charAt(i) == c)
				canFinish++;
		}
		if (board[0].charAt(0) == c && board[1].charAt(1) == c && board[2].charAt(2) == c)
			canFinish++;
		if (board[0].charAt(2) == c && board[1].charAt(1) == c && board[2].charAt(0) == c)
			canFinish++;
		return canFinish;
	}
    
    public int solution(String[] board) {
		int answer = 0;
		int oNum = 0, xNum = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char c = board[i].charAt(j);
				if (c == 'O')
					oNum++;
				else if (c == 'X')
					xNum++;
			}
		}
		if (oNum == xNum || oNum == xNum + 1) {
			int oCanFin = calFinishNum(board, 'O');
			int xCanFin = calFinishNum(board, 'X');
			if (xCanFin == 0) {
				if (oCanFin == 2 && xNum == 4 && oNum == 5) {
					answer = 1;
				} else if (oCanFin == 1 && oNum == xNum + 1) {
					answer = 1;
				}
                else if(oCanFin==0) answer=1;
			} else if (xCanFin == 1 && oCanFin == 0 && oNum == xNum) {
				answer = 1;
			}
		}
		return answer;
    }
}
