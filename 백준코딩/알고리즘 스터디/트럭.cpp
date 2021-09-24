#include <iostream>
#include <deque>
using namespace std;

int main() {
	int truck[1000];
	int num, len, maxi, unitTime = 0;
	deque <int> bridge;
	cin >> num >> len >> maxi;
	for (int i = 0; i < num; i++)
		cin >> truck[i];
	int bridge_weight = 0;
	int mv_truck = 0;
	int arr_truck = 0;
	while(num-arr_truck>0) {
		if(!bridge.empty()) {
			for (int i = 0; i < bridge.size(); i++)
				bridge[i] -= 1;
			int cnt = 0;
			for (int i = 0; i < bridge.size(); i++) {
				if (bridge[i] == 0) {
					bridge_weight -= truck[arr_truck++];
					cnt++;
				}
			}
			while (cnt > 0) {
				bridge.pop_front();
				cnt--;
			}
		}
		if (truck[mv_truck] + bridge_weight <= maxi && bridge.size() + 1 <= len) {
			bridge.push_back(len);
			bridge_weight += truck[mv_truck++];
		}
		unitTime++;
	}	
	cout << unitTime;
	system("pause");
	return 0;
}