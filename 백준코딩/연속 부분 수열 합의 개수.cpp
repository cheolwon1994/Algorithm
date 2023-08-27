#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    int len = elements.size();
    
    for(int i=0;i<len;i++){
        int sum = 0;
        for(int j=i;j<i+len;j++){
            sum+=elements[j%len];
            s.insert(sum);
        }
    }
    
    return s.size();
}
