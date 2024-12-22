#include <iostream>

using namespace std;

pair<int, int> findPriceRange(int dist) {
	int min = static_cast<int>(dist * 0.08 + 100);
	int max = static_cast<int>(dist * 0.36 + 750);
	return make_pair(min, max);
}

int main() {
	int dist = 6452;
	auto [min, max] = findPriceRange(dist);
	cout << "You can find prices between: " << min << " and " << max << endl;
	return 0;
}
