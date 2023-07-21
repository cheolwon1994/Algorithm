class Solution {
public:
    double getPow(double x, int num){
        if(num==0) return 1;
        else if(num==1) return x;
        else if(num==-1) return (double)1/x;
        if(num%2==0){
            double temp = getPow(x,num/2);
            double ans = temp*temp;
            return ans;
        }
        else{
            double temp = getPow(x,num-1);
            double ans = temp*x;
            return ans;
        } 
    }

    double myPow(double x, int n) {
        double answer = getPow(x,n);
        return answer;
    }
};
