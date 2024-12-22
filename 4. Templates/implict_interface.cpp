#include <iostream>
#include <vector>

using namespace std;

// Create some predicate functions and pass them to template functions as arguments

// Unary Predicate (one argument)
bool isEqualTo3(int val) {
	return val == 3;
}

// Binary Predicate (two arguments)
bool isDivisibleBy(int dividend, int divisor) {
	return dividend % divisor == 0;
}


// Create a template function
template <typename InputIterator, typename UniaryPredicate>
int countOccurances(InputIterator begin, InputIterator end, UniaryPredicate predicate) {
	int count = 0;
	for (auto iter = begin; iter != end; ++iter) {
		if (predicate(*iter)) ++count;  // We apply the predicate here
	}
	return count;
}

int main() {
	vector<int> vec = {1, 2, 3, 4, 5};
	cout << "3 occurred " << countOccurances(vec.begin(), vec.end(), isEqualTo3) << " times." << endl;
	return 0;
}
