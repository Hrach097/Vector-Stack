#include <iostream>
#include "Stack.h"

int main() {
	Stack<int> stack(10);
	stack.push(4);
	stack.push(454);
	stack.push(224);
	stack.push(197);
	stack.push(125);
	stack.pop();
	std::cout << stack.peek();

}
