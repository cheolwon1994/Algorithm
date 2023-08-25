#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
int answer, len;
vector<int> v;
string str;
bool flag[20];

void greedy(int idx, int matched, int sum, string name) {
    if (matched == len || name == str) {
        answer = min(answer, sum);
        return;
    }

    //go right
    int rightIdx = idx;
    int rightCnt = 0;
    while (1) {
        rightIdx = (rightIdx + 1) % len;
        if (rightIdx == idx) break;
        rightCnt++;
        if (!flag[rightIdx]) break;
    }
    if (rightIdx != idx) {
        //make flag true
        flag[rightIdx] = true;
        //add modify val
        int addVal = 0;
        char c = name[rightIdx];
        if (c != 'A') addVal = v[rightIdx];
        //change char
        name[rightIdx] = 'A';

        greedy(rightIdx, matched + 1, sum + addVal + rightCnt, name);

        //make flag false
        flag[rightIdx] = false;
        //rollback char
        name[rightIdx] = c;
    }

    //go left
    int leftIdx = idx;
    int leftCnt = 0;
    while (1) {
        leftIdx = (leftIdx + len - 1) % len;
        if (leftIdx == idx) break;
        leftCnt++;
        if (!flag[leftIdx]) break;
    }

    if (leftIdx != idx) {
        //make flag true
        flag[leftIdx] = true;
        //add modify val
        int addVal = 0;
        char c = name[leftIdx];
        if (c != 'A') addVal = v[leftIdx];
        //change char
        name[leftIdx] = 'A';

        greedy(leftIdx, matched + 1, sum + addVal + leftCnt, name);

        //make flag false
        flag[leftIdx] = false;
        //rollback char
        name[leftIdx] = c;
    }
}

int solution(string name) {
    //init
    answer = 26 * 100;
    len = name.size();
    str = "";

    for (int i = 0; i < len; i++) {
        //init
        flag[i] = false;
        str += "A";

        char c = name[i];
        int diff = c - 'A';
        int loop = 1 + ('Z' - c);
        v.push_back(min(abs(diff), loop));
    }
    flag[0] = true;
    name[0] = 'A';
    greedy(0, 1, v[0], name);
    
    return answer;
}
