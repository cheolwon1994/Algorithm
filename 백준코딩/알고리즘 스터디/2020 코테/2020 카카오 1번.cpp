#include <string>
#include <vector>

using namespace std;
/*
1 2 3
4 5 6
7 8 9
10 0 11
*/
int arr[12][12]={
    {0,4,3,4,3,2,3,2,1,2,1,1},      //0
    {4,0,1,2,1,2,3,2,3,4,3,5},      //1
    {3,1,0,1,2,1,2,3,2,3,4,4},      //2
    {4,2,1,0,3,2,1,4,3,2,5,3},      //3
    {3,1,2,3,0,1,2,1,2,3,2,4},     //4
    {2,2,1,2,1,0,1,2,1,2,3,3},     //5
    {3,3,2,1,2,1,0,3,2,1,4,2},     //6
    {2,2,3,4,1,2,3,0,1,2,1,3},     //7
    {1,3,2,3,2,1,2,1,0,1,2,2},     //8
    {2,4,3,2,3,2,1,2,1,0,3,1},     //9
    {1,3,4,5,2,3,4,1,2,3,0,2},     //10
    {1,5,4,3,4,3,2,3,2,1,2,0},     //11
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l=10,r=11;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            l=numbers[i];
            answer+="L";
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            r=numbers[i];
            answer+="R";
        }
        else if(numbers[i]==2 || numbers[i]==5 || numbers[i]==8 || numbers[i]==0){
            int ld = arr[l][numbers[i]];//left_dist
            int rd = arr[r][numbers[i]];//right_dist
            if(ld<rd){      //왼쪽이 더 가깝다
                l=numbers[i];
                answer+="L";
            }
            else if(ld>rd){         //오른쪽이 더 가깝다
                r=numbers[i];
                answer+="R";
            }
            else{           //둘의 거리가 같을때
                if(hand=="right"){
                    r=numbers[i];
                    answer+="R";
                }
                else{
                    l=numbers[i];
                    answer+="L";
                }             
            }
        }
    }
    return answer;
}