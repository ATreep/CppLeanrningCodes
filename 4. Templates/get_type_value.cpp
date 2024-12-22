#include <iostream>
#include <sstream>
#include <stdexcept>
#include <typeinfo>

using namespace std;

template <typename T>
T getTypeValue() {
	cout << "Enter a(n) " << typeid(T).name() << ": ";
	string line; T result; char remain;
	if(!getline(cin, line)) throw domain_error("Unable to get line from cin.");
	istringstream iss(line);
	if(iss >> result && !(iss >> remain)) return result;
	cout << "Invalid format." << endl;

	return 0;
}

int main() {
	int val0 = getTypeValue<int>();
	cout << "int " << val0 << endl;

	double val1 = getTypeValue<double>();
	cout << "double " << val1 << endl;

	char val2 = getTypeValue<char>();
	cout << "char " << val2 << endl;


	return 0;
}
