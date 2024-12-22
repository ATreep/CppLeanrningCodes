#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using std::string;
using std::cout;
using std::endl;

// We can use operator overloadding to let C++ know how to apply operators to user-defined classes.
// STL vector cannot be overloadded, so we need to define a class.

class StringVector {
private:
	std::vector<string> data;

public:
	// C++11 or higher supports initializer_list.
	StringVector(std::initializer_list<string> init) : data(init) {}

	// Constructor
	StringVector(const std::vector<string>& vec) : data(vec) {}

	// Copy constructor
	StringVector(const StringVector& other) : data(other.data) {}
	
	// Const variables try calling the const member function first if the non-const function exists.
	const std::vector<string>::const_iterator begin() const {
		return data.begin();
	}
	
	const std::vector<string>::const_iterator end() const {
		return data.end();
	}

	// Get vector data
	std::vector<string> copyAsVector() const {
		return data;
	}

	// Return the original vector
	StringVector& operator+=(const string& element) {
		data.push_back(element);
		return *this;
	}

	StringVector& operator+=(const StringVector& other) {
		for(const string& element : other) {
			data.push_back(element);
		}
		return *this;
	}
	
	StringVector operator+(const string& element) {
		StringVector result = *this;
		result.data.push_back(element);
		return result;
	}

	StringVector operator+(const StringVector& other) {
		StringVector result = *this; // Copy this to `result` with copy constructor
		for(const string& element : other) {
			result += element;
		}
		return result;
	}

	// operator<< must use `friend` keyword to be overloadded because it is NOT a member function of this class.
	friend std::ostream& operator<<(std::ostream& os, const StringVector& vec) {
		os << "[";
		for(const string& element : vec) {
			os << element << " ";
		}
		os << "]";
		return os;
	}
	
};

int main() {
	StringVector vec{
		"Australia",
		"Brazil",
		"Canada",
		"Dutch",
		"England",
		"France",
		"Germany"
	};
	
	cout << "Origin StringVector: " <<  vec << endl;

	vec += "Haiti";

	cout << "New StringVector: " << vec << endl;

	StringVector copy = StringVector(vec);

	copy += vec;

	cout << "Copy of StringVector: " << copy << endl;

	cout << "Iterating StringVector:" << endl;

	int index = 0;

	for(const string& element : vec) {
		cout << index <<  ": " << element << endl;
		index++;
	}
	
	
	return 0;
}
