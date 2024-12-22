#include <iostream>
#include <memory>

// RAII stands for Resource Acquisition Is Initialization
// - All resources should be acquired in the constructor.
// - All resources should be released in the destructor.

class lock_guard {
private:
	mutex& acquired_lock;
public:
	lock_guard(mutex& lock) : acquired_lock(lock) {
		acquired_lock.lock();
	}
	~lock_guard() {
		acquired_lock.unlock();
	}
}

class Node {
public:
	Node() = default;
	~Node() = default;
}

// There are some smart pointers that are RAII-compliant.

// - std::unique_ptr: Delete resources it points when it is destructed. Cannot be copied.
int test_unique_ptr() {
	Node *node = new Node;
	std::unique_ptr<Node> x(node);
	std::unique_ptr<Node> y = x; // Copy of x (Invalid operation)
} // `delete Node;` will be executed automatically by unique_ptr x when finishing this function, and y pointed a deleted heap space, so it is wrong.
 
// - std::shared_ptr: Same resource can be stored by any number of shared_ptrs. Delete when none of them point to it.
int test_shared_ptr() {
	std::shared_ptr<Node> p1(new Node);
	// Use p1
	{
		std::shared_ptr<Node> p2 = p1;
		// Use p1 and p2
	}
	// Use p1
} // Freed

// - std::weak_ptr: Similar to std::shared_ptr, but it does not count for references, so it can avoid circle references.
