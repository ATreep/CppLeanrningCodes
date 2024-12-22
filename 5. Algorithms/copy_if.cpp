#include <iostream>
#include <algorithm>
#include <iterator>
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

	string classA = "A";
	auto isClassA = [classA](string name) {
		return name.size() >= 1 && name.substr(0, 1) == classA;
	};

	vector<string> ACourses;
	
	// This code cannot compile properly, because you haven't assign spaces for vector ACourses:
	// copy_if(courses.begin(), courses.end(), ACourses, isClassA);  	
	
	// We can use back_inserter to allocate new space as new element is copied into ACourses.
	copy_if(courses.begin(), courses.end(), back_inserter(ACourses), isClassA);

	// `result` parameter received an output iterator, so we can also copy the vector to cout.
	copy_if(courses.begin(), courses.end(), ostream_iterator<string>(cout, "\n"), isClassA);

	return 0;
}
