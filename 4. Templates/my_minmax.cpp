#include <iostream>

using namespace std;

template <typename T>
/*
pair<T, T> my_minmax(T a, T b) {
	return a < b ? {a, b} : {b, a}; // Do not use this way to express pair, because {a, b} and {b, a} can be regarded as initializer_list.
}
*/

pair<T, T> my_minmax(T a, T b) {
	if (a < b) return {a, b};
	else return {b, a};
}

template <typename T>
void printMinAndMax(T min, T max) {
	cout << "Min: " << min << endl;
	cout << "Max:" << max << endl;
	cout << endl;
}

int main() {
	auto [min1, max1] = my_minmax<double>(4.7, -7.9);
	printMinAndMax(min1, max1);		
	auto [min2, max2] = my_minmax<int>(3, 4);
	printMinAndMax(min2, max2);
	auto [min3, max3] = my_minmax<string>("Avery", "Anna");
	printMinAndMax(min3, max3);
	auto [min4, max4] = my_minmax("Avery", "Anna"); // Without declaring type string, a and b will be regarded as C-string, which won't be compared one by one char.
	printMinAndMax(min4, max4);

	return 0;
}

