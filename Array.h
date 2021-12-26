#pragma once
#include <string>

template <class T>
class Array
{
private:
	int size;
	T* data;

public:
	Array() : size(0), data(nullptr) {}
	Array(const Array<T>& myArray);
	~Array() { clear(); }

	void clear();
	const int getSize() { return size; }
	T& operator[](int);
	Array<T>& operator+=(const T& obj);
	Array<T>& operator-=(const int index);
	Array<T>& operator=(const Array<T>& myArray);
};

template <class T>
Array<T>::Array(const Array<T>& myArray)
{
	data = new T[myArray.size];
	size = myArray.size;
	for (int i = 0; i < myArray.size; i++)
		data[i] = myArray.data[i];
}

template <class T>
T& Array<T>::operator[](int index)
{
	std::string err = "Index " + std::to_string(index) + " does not exist";
	if (index < 0 || index >= size)
		throw err;
	return data[index];
}

template<class T>
Array<T>& Array<T>::operator+=(const T& obj)
{
	T* tmp = data;
	size++;
	data = new T[size];
	for (int i = 0; i < size - 1; i++)
		data[i] = tmp[i];
	data[size - 1] = obj;
	return *this;
}

template<class T>
Array<T>& Array<T>::operator-=(const int index) 
{
	std::string err = "Index " + std::to_string(index) + " does not exist";
	if (index < 0 || index >= size)
		throw err;
	T* tmp = new T[size - 1];
	int k = 0;
	for (int i = 0; i < size; i++)
		if (i != index)
			tmp[k++] = data[i];
	size--;
	data = tmp;
	return *this;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& myArray)
{
	if (this == &myArray)
		return *this;
	delete[] data;
	data = new T[myArray.size];
	size = myArray.size;
	for (int i = 0; i < myArray.size; i++)
		data[i] = myArray.data[i];
	return *this;
}

template <class T>
void Array<T>::clear() 
{
	delete[] data;
	data = nullptr;
	size = 0;
}
