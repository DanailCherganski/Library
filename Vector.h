#pragma once
#include<iostream>
template<typename T>
class Vector
{
private:
	T* elements; // int, double, obj
	size_t size; // unsigned int
	size_t capacity;

	void copy(const Vector<T>& other);
	void erase(); // destroy; 

	void resize();
public:
	Vector();
	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);
	~Vector();
	void push(T element); // add back
	void pop(); // print first
	bool isEmpty()const;
	void print()const;
	T& operator[](size_t index)const;
	size_t getSize()const
	{
		return this->size;
	}
};

template<typename T>
Vector<T>::Vector()
{
	this->capacity = 8;
	this->size = 0;
	this->elements = new T[this->capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
	this->elements = new T[other.capacity];
	this->capacity = other.capacity;
	this->size = other.size;
	for (size_t i = 0; i < this->size; i++)
	{
		this->elements[i] = other.elements[i];
	}
}

template <typename T>
void Vector<T>::erase()
{
	delete[] this->elements;
}

template <typename T>
Vector<T>::~Vector()
{
	this->erase();
}

template <typename T>
void Vector<T>::resize()
{
	this->capacity *= 2;
	T* newElements = new T[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		newElements[i] = this->elements[i];

	}
	this->erase();
	this->elements = newElements;
}

template <typename T>
void Vector<T>::push(T element)
{
	this->size++;
	if (this->size > this->capacity)
	{
		this->resize();
	}
	this->elements[size - 1] = element;
}

template <typename T>
void Vector<T>::pop()
{
	this->size--; // 
}

template <typename T>
bool Vector<T>::isEmpty() const
{
	return this->size == 0;
}

template <typename T>
void Vector<T>::print() const
{
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << this->elements[i] << std::endl;
	}
}

template <typename T>
T& Vector<T>::operator[](size_t index)const
{
	return this->elements[index];
}

