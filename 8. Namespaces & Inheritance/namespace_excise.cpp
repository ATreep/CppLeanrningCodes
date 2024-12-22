#include <iostream>
#include <vector>

// Typically, we should avoid using the following statement:
// using namespace std;
// But declare `using` separately to prevent variables or function that we are unknown about are imported in the code.
using std::cout, std::cin, std::endl;

// We can also create our own namespaces
namespace Test {
	int count(const std::vector<int>& v, const int number) {
		int ctr = 0;
		for (auto i : v) {
			if (i == number) {
				++ctr;
			}
		}
		return ctr;
	}
}

int main() {
	std::vector<int> v{3, 1, 4, 1, 5, 9};
	cout << "Test count: " << Test::count(v, 1) << endl;
	return 0;
}
