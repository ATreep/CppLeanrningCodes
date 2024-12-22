#include <vector>
#include <cstdlib> // for rand
#include <iostream> // for cout
#include <algorithm> // for generate, sort, copy
#include <iterator> // for ostream_iterator

using namespace std;

int main() {
	vector<int> vec(10);
	generate(vec.begin(), vec.end(), rand);
	sort(vec.begin(), vec.end());
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}
