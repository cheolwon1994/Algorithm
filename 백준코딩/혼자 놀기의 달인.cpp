#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    bool visit[101] = { false, };
    int cardChecked = 0;
    int len = cards.size();
    vector<int> groupSize;

    while (cardChecked < len) {
        int idx = -1;
        for (int i = 0; i < len; i++) {
            int cardNum = cards[i];
            if (!visit[cardNum]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) break;
        //group 애들 저장
        int boxCnt = 0;

        while (!visit[cards[idx]]) {
            visit[cards[idx]] = true;
            cardChecked++;
            boxCnt++;
            idx = cards[idx] - 1;
            int nextBox = cards[idx];
            if (visit[nextBox]) break;
        }
        groupSize.push_back(boxCnt);
    }
    //group이 1개라면 0 RETURN;
    if (groupSize.size() == 1) return 0;
    sort(groupSize.begin(), groupSize.end(), greater<>());

    return groupSize[0] * groupSize[1];
}
