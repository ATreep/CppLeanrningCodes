#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

// 1. Introducing std::vector::emplace_back, which allows you push new element directly instead of copying it first to the back of the vector.

struct President
{
    std::string name;
    std::string country;
    int year;
 
    // This is a default constructor.
    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << "I am being constructed.\n";
    }
 
    // This is a move constructor. (Pay attention to the double ampersands.)
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being moved.\n";
    }
 
    President& operator=(const President& other) = default;
};

void emplace_back_example() {
	std::vector<President> elections;
	elections.emplace_back("Nelson Mandela", "South Africa", 1994); // emplace_back can create the object directly in the vector's memory.
	elections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936)); // push_back should we create a temporary object first, and it will be copying this object to vector's memory and destory the temporary object.
}


// 2. When copy constructor or destructor is called (Lifecycle of Class)

// Give you code like this, counting when the copy constructor or destructor is called. (Before c++17)

class StrVector {
public:
	// Defauly constructor
	StrVector();

	// Fill constructor
	StrVector(int size, const std::string& text);

	// Copy constructor
	StrVector(const StrVector& other);

	// Destructor
	~StrVector();

	// Copy assignment
	StrVector& operator=(const StrVector& other);
};

StrVector readNames(int size);
void class_lifecycle_example() {
	
	// 1. Copy constructor: Copy object from function's return to `name1`, noting: NOT assignment!
	// 2. Destructor: Destory the returned object.
	StrVector name1 = readNames(54321234);  

	StrVector name2;  // Default constructor
	
	// 1. Copy assignment
	// 2. Destructor: Destory the returned object.
	name2 = readNames(54321234);

	return; // Destructor: Destory `name1` and `name2`.
}

StrVector readNames(int size) {
	// Fill constructor
	StrVector names(size, "Ito");

	// In the return process
	// 1. Copy constructor: Copy `names` to return memory.
	// 2. Destructor: Destory `names` in the end of function.
	return names;
}

// Conclusion:
// fill->copy->des->copy->des->default->fill->copy->des->copy assignment->des->des->des

// However, in c++17, there are some optimization
// Half destructors will be gone and all copy constructor will be gone!
// But one copy assignment also exists.
// We will optimize it using Move Semantic!

// 3. Introducing l-values & r-values (This part is a simplification of a complicated topic!)

// l-values
// - An expression that has a name (identity).
// - Can find address using ampersand (address-of) operator (such as &var).

// r-values
// - An expression that does not have a name (identity).
// - Temporary values
// - Cannot find address using address-of operator.

// TIPS of INTUITION: l-values can appear on both sides of assignment, but r-values can only appear on the right side of an assignment.

// For examples
void lvalues_rvalues_instance() {
	int val = 2;  // `val` is an l-value; `2` is an r-value
	std::vector<int> v1{1, 2, 3};  // `v1` is an l-value
	std::vector<int> v2{1, 2, 3};  // `v1` is an l-value
	auto v4 = v1 + v2;  // `v4` is an l-value; `v1 + v2` is an r-value
	v1[1] = 4 * val;  // `v1[1]` is an l-value; `4 * val` is an r-value
	int *ptr = &val;  // `ptr` is an l-value; `&val` is an r-value

	return;
}

void lvalues_rvalues_ref_instance() {
	int val = 2;
	int* ptr = &val;
	std::vector<int> v1{1, 2, 3};

	auto& ptr2 = ptr;  // `ptr2` is an l-value reference
	auto&& v4 = v1 + v2;  // `v4` is an r-value reference (double ampersands). After binding to a reference, the r-value will not be destoryed for the duration of the reference's scope.

	auto& ptr3 = &val;  //  ERROR: cannot bind l-val ref to r-val
	auto&& val2 = val;  // ERROR: cannot bind r-val ref to l-val
	
	const auto& ptr4 = ptr + 5;  // OKAY: CAN bind const l-val ref to r-val
	
	return;
}

// 4. Move constructor and assignment
class StrVectorMovable {
private:
	std::string value;
public:
	// Defauly constructor
	StrVectorMovable();

	// Fill constructor
	StrVectorMovable(int size, const std::string& text);

	// Copy constructor
	StrVectorMovable(const StrVector& other);

	// Move constructor
	StrVectorMovable(StrVectorMovable&& other) {
		value = std::move(other.value);  // std::move can transfer an r-value to an l-value, i.e. changing the address of the temporary memory.
		other.value = nullptr;  // Destory `other`

	}

	// Move assignment
	StrVectorMovable& operator=(StrVectorMovable&& other) {
		if (this != &other) {
			value = std::move(other.value);
			other.value = nullptr;
		}
	}

	// Destructor
	~StrVectorMovable();

	// Copy assignment
	StrVectorMovable& operator=(const StrVector& other);
};

// 5. Write a swap function with std::move

// Here is a generic swap function
template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

// swap with std::move can avoid allocating a new memory
template <typename T>
void swap_move(T& a, T& b) {
	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}
