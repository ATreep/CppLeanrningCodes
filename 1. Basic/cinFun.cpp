#include <iostream>
#include <sstream>

using namespace std;

int getInteger(string prompt = "Enter an integer: ", string reprompt = "Illegal numeric format. Try again.");

int main() {
	cout << "What is your name?" << endl;
	string name;
	getline(cin, name);

	int age = getInteger("What is your age?");

	cout << "Where are you from? " << endl;
	string home;
	getline(cin, home);

	cout << "Hello, " << name << ". You are " << age << " and come from " << home << "." << endl;
}

int getInteger(string prompt, string reprompt) {
	cout << prompt << endl;
	while(true) {
		string line;
		if(!getline(cin, line)) {
			throw domain_error("...");
		}

		istringstream iss(line);
		int val; 
		string remain;
		if(iss >> val && !(iss >> remain)) 
			return val;
		cout << reprompt << endl;
	}
	return 0;
}
