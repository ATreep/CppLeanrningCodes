// This code shows a simple example about multithreading and mutex.
#include <iostream> 
#include <sstream>
#include <vector>
#include <string>
#include <chrono>  // Use duration types of chrono header for approprite time type for std::this_thread::sleep_for
#include <mutex>  // Lock guard and locking mutex sign & unlocking mutex sign manually
#include <thread>  // Create multithreading

using std::cout, std::cin, std::endl, std::vector, std::string;

std::mutex mtx;
const int max_thread = 10;

void greet(string name) { 
	// Why need mutex lock? The `cout` statement is not an atomic statement, so there may be exceptions in multithreading.

	// std::lock_guard<std::mutex> lg(mtx);  // You can use lock_guard to lock mutex at the beginning of function and unlock mutex at the end of function.
	mtx.lock();  // Lock mutex manually.
	std::this_thread::sleep_for(std::chrono::seconds(1));  // Sleep for 1s.
	cout << "Hello " << name << endl;
	mtx.unlock();
}

int main() {
	vector<std::thread> threads;
	cout << "Start..." << endl;
	for(int i = 0;i < max_thread;i++) {
		std::ostringstream oss;
		oss << "T" << i;
		threads.push_back(std::thread(greet, oss.str()));
		// Should not thread[i].join() here, or else it will be a sequent task.
	}

	// The reference notation here is necessary
	for(std::thread& t : threads) {
		t.join();
	}

	cout << "Finished!" << endl;
	return 0;
}
