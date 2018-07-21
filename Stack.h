#ifndef _STACK
#define _STACK
#include "Vector.h"

template <typename T>
class Stack : private Vector<T> {
public:
		Stack(const int size = 5);		
		virtual ~Stack();
		virtual void push(T value);
		virtual void pop();
		virtual T peek();
		virtual int get_size() override;
		virtual void show_stack();
 
};



template <typename T>
Stack<T>::Stack(const int size) : Vector<T>(size) {  }

template <typename T>
Stack<T>::~Stack(){
		Vector<T>::~Vector();
}

template <typename T>
void Stack<T>::push(T value) {
		Vector<T>::push_back(value);
}

template <typename T>
void Stack<T>::pop() {
		Vector<T>::pop_back();
}

template <typename T>
T Stack<T>::peek() {
		return Vector<T>::peek_back();
}

template <typename T>
int Stack<T>::get_size() {
		Vector<T>::get_size();
}

template <typename T>
void Stack<T>::show_stack() {
		Vector<T>::show_vector();
}

#endif
