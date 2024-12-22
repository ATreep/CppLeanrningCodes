#include <iostream>

using namespace std;

int main() {
	int limit = 3;  // A variable that is not included in lambda's domain
	
	// Formate of lambda: 
	// auto func = [capture-clause](parameters) -> return-value {
	//  	//body
	// };
	auto func = [limit](int num) -> int {
		return limit * num;
	};
	cout << "3 * 5 = " << func(5) << endl;
	return 0;
}
