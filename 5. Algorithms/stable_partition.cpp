#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> courses{
		"A100",
		"B100",
		"A200",
		"C200",
		"A300",
		"B300"
	};

	auto isClassA = [](string name) {
		return name.length() >= 1 && name.substr(0, 1) == "A";
	};
	stable_partition(courses.begin(), courses.end(), isClassA);

	for(string name : courses) {
		cout << name << endl;
	}
	
	return 0;
}
