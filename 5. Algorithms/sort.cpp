#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> vec{
		{0, 2},
		{0, 1},
		{0, 4},
		{0, 3},
		{0, 5}
	};
	auto comapreVec = [](vector<int>& v1, vector<int>& v2) {
		return v1[1] < v2[1];
	};
	sort(vec.begin(), vec.end(), comapreVec);
	
	for(auto v : vec) {
		cout << v[1] << endl;
	}

	return 0;
}
