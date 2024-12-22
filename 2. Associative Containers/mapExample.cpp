#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

string GetLine() {
	string response;
	getline(cin, response);
	return response;
}

int main() {
	// Use a map to count the occurrance of words in the user's typing sentence.
	map<string, int> frequencyMap;
	cout << "Enter words." << endl;
	while (true) {
		cout << "> ";
		string sentence = GetLine();
		if (sentence.empty()) break;
		
		string word;
		istringstream iss(sentence);
		while (iss >> word) {
			frequencyMap[word]++;
		}

		map<string, int>::iterator iter;
		for (iter = frequencyMap.begin(); iter != frequencyMap.end(); iter++) {
			cout << iter->first << ": " << iter->second << endl;
		}

		cout << endl;
	}
	return 0;
}
