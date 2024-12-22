#include <iostream>

// A class with all *pure* virtual functions = Interface
// A class with at least one *pure* virtual function = Abstract Class (Superset of Interface)

// This is an example of interface, which must be inheriting with all functions implemented
class Drink {
public:
	virtual void make() = 0;  // A pure virtual function. Means that the inheriting class must define this function.
};

// This is an example of abstract class
class Base {
public:
	virtual void foo() = 0;  // Pure virtual function
	virtual void foo2();  // Non-pure virtual function
	int bar() {  // Regular function
		return 42;
	};
};

class Tea : public Drink {  // Inherit class Drink. `public` here can also be `protected` to convert all `public` function into `protected` function. Note that `public` is the default modifier, so it can also be omitted here. 
public:
	void make() {
		// Implementation
	}
}
