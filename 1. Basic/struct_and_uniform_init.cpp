#include <iostream>
#include <vector>

using namespace std;

struct Time {
	int hour;
	int minute;
};

struct Name {
	string first;
	string last;
};

struct Course {
	string name;
	Time start;
	Time end;
	Name lecturer;
};

int main() {
	vector<int> vec{3, 1, 4, 1, 5, 9};
	Course now {"CS106L", {15, 30}, {16, 30}, {"Wang", "Zeng"}};
	return 0;
}
