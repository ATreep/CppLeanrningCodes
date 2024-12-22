#include <sstream>
#include <iostream>

using namespace std;

int stringToInteger(string str);
void printStateBits(istream& s);

int main(int argc, char *argv[]) {
	if(argc == 2) {
		int val = stringToInteger(argv[1]);
		cout << "You entered: " << val << endl;
		cout << "Half of that is: " << val/2 << endl;

		return 0;
	}
	return 1;
}

int stringToInteger(string str) {
	istringstream iss(str);
	
	cout << "Before read: ";
	printStateBits(iss);
	
	int num;
	iss >> num;

	cout << "After read: ";
	printStateBits(iss);

	return num;
}

void printStateBits(istream& s) {
	cout << "State bits: ";

	cout << (s.good() ? "G" : "-");
	cout << (s.fail() ? "F" : "-");
	cout << (s.eof() ? "E" : "-");
	cout << (s.bad() ? "B" : "-");
	
	cout << endl;
}
