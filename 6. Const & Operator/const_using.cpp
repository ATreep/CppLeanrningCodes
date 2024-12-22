#include <iostream>
#include <vector>
using namespace std;
// Should NOT compile and run this .cpp file, just a lecture note for reading.

// Introducing Const Keyword
// 
// Why Const? 
// "There is no excuse for ignoring the safety mechanisms provided with a product, and there is particularly no excuse for programmers too lazy to write const-correct code."
// `const` allows us to reason about whether a variable will be changed.

// 1. Using const member functions
struct Planet {
	// A const member function can be called both by const and non-const, and it can only call const functions, and modify only static members.
	int countPopulation() const;

	// But a non-const member function can only be called by non-const.
	void deathStar();
};

void evil(const Planet &p) {
	// OK: countPopulation is const
	cout << p.countPopulation() << endl;

	// NOT OK: deathStar is not const
	p.deathStar();
}

int main() {
	// 2. Const Pointer: difficult to make sense!
	// Tip: When in doubt, read right to left.
	
	// a. constant pointer to a non-constant int
	// NO: p++, p--
	// OK: *p++, *p--
	int * const p;

	// b. non-constant pointer to a constant int
	const int* p;
	int const* p; // Two forms are equal
	
	// c. constant pointer to a constant int
	const int * const p;
	int const* const p;

	// For function arguments, pass by const reference is better than pass by value.

	// 3. Const Iterators
	// Remember: Iterators act like pointers!
	// To make an iterator read only, define a new const_iterator
	
	// a. Using `const` keyword
	vector<int> v(5);
	const vector<int>::iterator itr = v.begin();
	*itr = 5; // OK
	++itr; // BAD! Cannot modify itr
	
	// b. Using const_iterator
	vector<int>::const_iterator itr = v.begin();
	*itr = 5; // BAD!
	++itr; // OK
	int value = *itr; // OK
	
	// 4. Where does const work?
	// It can be used as a *qualifier* on any type. This works for everything from arguments to local variables.
	
	// Challenge: describe the following code
	const int* const myClassMethod(const int* const & param) const;
	

	return 0;
}
