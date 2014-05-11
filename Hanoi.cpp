/*

Tower of Hanoi

Objective: There are three towers, the leftmost tower has N discs on it. 
Move the discs from the left tower to the right tower following these constraints:

1) Only move 1 disc at a time.

2) A larger disc can not be placed on top of a smaller disc.

3)

*/

#include <iostream>
#include <stack>

#include <assert.h>

void fillTower(std::stack<int> &tower, int n) {
	for (int i = n; i > 0; i--) {
		tower.push(i);
	}
}

void moveDisc(std::stack<int> &from, std::stack<int> &to) {
		
	int d = from.top();
	
	assert(d != NULL);

	from.pop();
	to.push(d);
}

void movePile(int n, std::stack<int> &from, std::stack<int> &to, std::stack<int> buffer) {
	
	assert(n >= 0);
	
	if (n == 0) return;

	movePile(n - 1, from, buffer, to);
	moveDisc(from, to);
	movePile(n - 1, buffer, to, from);

}

void print(std::stack<int> tower) {
	std::cout << "-";
	while (!tower.empty()) {
		std::cout << tower.top() << " ";
		tower.pop();
	}
	std::cout << "-|" << std::endl; 
}

int main() {
	std::stack<int> tower[3];
	int n = 9;

	std::cout << "How many discs would you like? " << std::endl;
	std::cin >> n;

	fillTower(tower[0],n);

	std::cout << "Before:\n" << std::endl;
	print(tower[0]);
	print(tower[1]);
	print(tower[2]);
	
	std::cout << "\nCalculating...";
	movePile(n, tower[0], tower[2], tower[1]);

	std::cout << "\n\nAfter:\n" << std::endl;
	print(tower[0]);
	print(tower[1]);
	print(tower[2]);

	system("PAUSE");
	return (0);
}
