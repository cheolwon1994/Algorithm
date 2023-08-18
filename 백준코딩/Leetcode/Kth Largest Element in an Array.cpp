class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        for(int num : arr)
            pq.push(num);
        while(--k>0){
            pq.pop();
        }
        return pq.top();
    }
};
