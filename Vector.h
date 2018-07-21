#ifndef _VECTOR
#define _VECTOR

#include <iostream>

template <typename T>
class Vector{

public:		
	Vector(const int size = 5);
	Vector(const Vector& rhs);
	virtual ~Vector();
	virtual Vector& operator=(const Vector& rhs);

	virtual bool push_back(T value);
	virtual bool pop_back();
	virtual T peek_back();
	virtual T get_at(const int index);
	virtual int get_size();
	virtual void show_vector();
	virtual void copyFrom(const Vector& rhs);
	virtual void resizeVector();

private:
	T* m_vector;	
	int m_current;
	int m_size;

};

template <typename T>
Vector<T>::Vector(const int size) {
		if(size > 0) {
				m_size = size;
		} else {
				std::cout << "value is less than 1 ";
				return;
		}
		m_vector = new T[m_size]; 
		m_current = 0;
}

template <typename T>
Vector<T>::~Vector() {
		delete [] m_vector;
		m_vector = nullptr;
}

template <typename T>
void Vector<T>::copyFrom(const Vector& rhs) {
		m_current = rhs.m_current;
		m_size = rhs.m_size;
		m_vector = new T[m_size];
		for(int ix = 0; ix < m_size; ++ix) {
				m_vector[ix] = rhs.m_vector[ix];
		}

}

template <typename T>
Vector<T>::Vector(const Vector& rhs) {
		copyFrom(rhs);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs) {
		if(this == &rhs) {
				return *this;
		}
		delete [] m_vector;
		copyFrom(rhs);
		return * this;
}

template <typename T>
void Vector<T>::resizeVector() {
		int* tmpPtr = new T[2 * m_size];
		for(int ix = 0; ix < m_size; ++ix) {
				tmpPtr[ix] = m_vector[ix];
		}
		delete [] m_vector;
		m_vector = tmpPtr;
		tmpPtr = nullptr;
		m_size *= 2;
}

template <typename T>
bool Vector<T>::push_back(T value) {
		if(m_size == m_current)
				resizeVector();
		m_vector[m_current++] = value;
		return true;
}

template <typename T>
bool Vector<T>::pop_back() {
		if(m_current == 0) 
				return 0;
		--m_current;
		return true;
}

template <typename T>
T Vector<T>::get_at(const int index) {
		return (index <= m_current) ? m_vector[index] : -1;
}

template <typename T>
T Vector<T>::peek_back() {
		return m_vector[m_current - 1];
}

template <typename T>
int Vector<T>::get_size() {
		return m_current;
}

template <typename T>
void Vector<T>::show_vector() {
		for(int ix = 0; ix < m_current; ++ix) {
				std::cout << m_vector[ix] << "  ";
		}
}

#endif
