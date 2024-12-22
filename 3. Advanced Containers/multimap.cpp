#include <iostream>
#include <map>

using namespace std;

int main() {
	multimap<int, int> myMMap;
	myMMap.insert({3, 12});
	myMMap.insert({3, 11});

	// Three ways to traversal it.

	cout << "For Each:" << endl;
	for(auto pair : myMMap) {
		cout << "Key: " << pair.first << " Value: " << pair.second << endl;
	}

	cout << "Structured Binding (Only in C++17):" << endl;
	for(auto [key, value] : myMMap) {
		cout << "Key: " << key << " Value: " << value << endl;
	}

	cout << "Accessing with Specific Key:" << endl;
	auto range = myMMap.equal_range(3);
	for(auto it = range.first; it != range.second; it++) {
		cout << "Key: " << it->first << " Value: " << it->second << endl;
	}
	
	return 0;
}
