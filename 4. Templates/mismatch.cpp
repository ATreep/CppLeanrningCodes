#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <typename InputIt1, typename InputIt2>
pair<InputIt1, InputIt2> mismatch_it(InputIt1 first1, InputIt1 last1,
					InputIt2 first2) {
	while (first1 != last1 && *first1 == *first2) {
		first1++;
		first2++;
	}
	return {first1, first2};
}

int main() {
	vector<int> vec1 = {1, 2, 3, 4, 5};
	vector<int> vec2 = {1, 2, 3, 5}; 
	auto [vec1_mismatch, vec2_mismatch] = mismatch_it(vec1.begin(), vec1.end(), vec2.begin());
	cout << "Mismatch: " << endl;
	cout << "vec1: " << *vec1_mismatch << endl;
	cout << "vec2: " << *vec2_mismatch << endl;
	return 0;
}
