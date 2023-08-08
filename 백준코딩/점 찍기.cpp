#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i=0;i<=d;i+=k){
        long long dist = (long long)d*d-(long long)i*i;
        answer += floor(sqrt(dist) / k) + 1;
    }
    return answer;
}
