#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>
#include <vector>

using std::cout, std::endl;

namespace basics {
	class Base {
	public:
		Base() = default;
		virtual ~Base() = default;  // If intend to make a class inheritable, necessary to make the destructor virtual. If not, memory will leaks, referring to 2nd example. Aside, virtual destructor is a sign whether a class can be inherited.
	};

	class Derived : public Base {
		Derived() : Base() {}
		~Derived();
		// Subclass always calls the superclass constructor, calling the default constructor of Base if not specified.
		// Derived() {} // This is equivalent to the upper line.
	};
}


// An example of Non-Virtual Destructor
namespace non_virtual_destructor {
	class Base {
	public:
		~Base() = default;  // A non-virtual destructor in Base class
	};

	class Derived : public Base {
		~Derived();
	};
	
	void test() {
		Base *b = new Derived();
		delete b;  // Never calls the destructor for Derived!
	}
}

// Access Specifiers
/*
 * private: Can only be accessed by *this* class.
 * protected: Can only be accessed by *this* or *derived* classes
 * public: Can be accessed by *anyone*
 * */

// Best practice of casting
namespace casting {
	void test() {
		// All of these are legal
		char b = 'a';
		int a1 = (int) b;
		int a2 = int(b);
		int a3 = static_cast<int>(b); // Recommended
	}
}

// Template class
namespace template_class {
	template <class T>
	class Priority_Q {
	public:
		Priority_Q() = default;
		~Priority_Q() = default;

		T top() const {
			assert(!_heap.empty());
			return _heap[0];
		}

		T pop() {
			assert(!_heap.empty());
			T top_elem = _heap[0];
			_heap.erase(std::remove(_heap.begin(), _heap.end(), top_elem), _heap.end());
			std::push_heap(_heap.begin(), _heap.end());
			return top_elem;
		}

		void push(T val) {
			_heap.push_back(val);
			std::push_heap(_heap.begin(), _heap.end());
		}

		T operator[](int index) const {
			return _heap[index];
		}

		int length() const {
			return _heap.size();
		}

		friend std::ostream& operator<<(std::ostream& os, const Priority_Q<T> queue) {
			os << "{";
			for(int i = 0, len = queue.length(); i < len; ++i) {
				if (i > 0) os << ", ";
				os << queue[i];
			}
			return os << "}";
		}

	private:
		std::vector<T> _heap;
	};

	void test() {
		Priority_Q<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);
		cout << "Print all: "  << queue << endl;
		cout << "Pop: " << queue.pop() << endl;
		cout << "Print after poping: " << queue << endl; 
	}
}

int main() {
	// Test Template Class: Priority Queue
	template_class::test();
}
