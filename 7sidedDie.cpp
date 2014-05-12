/*

5 sided die to 7 sided die:

Using a function that uniformly generates a randomly between 1 and 5, 
create a function that uniformly generates a number between 1 and 7.

*/

#include <iostream>
#include <math.h>

int random5() {
	//we will assume that this function is uniformly distributed.
	return floor(rand() * 5) + 1;
}

int random7() {
	int num = 0;
	for (int i = 0; i < 7; i++) {
		num += random5();
	}
	return (num % 7) + 1;
}

int main() {
	for (int i = 0; i < 100; i++) {
		std::cout << random7() << std::endl;
	}
	//system("pause");
	return 0;

}