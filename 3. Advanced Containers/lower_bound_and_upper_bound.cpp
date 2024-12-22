#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vec(10);
	for(int i = 0;i < 10;i++) {
		vec[i] = i * 10;
	}
	
	auto iter_lb = lower_bound(vec.begin(), vec.end(), 20); // smallest element >= 20
	auto iter_ub = upper_bound(vec.begin(), vec.end(), 20); // smallest element > 20				
	
	cout << "Element greater than or equal to 20 (lower_bound): " << *iter_lb << endl;
	cout << "Element greater than 20 (upper_bound): " << *iter_ub << endl;

	return 0;
}
