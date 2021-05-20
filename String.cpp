#include "String.h"

String::String()
{
	this->size = 0;
	this->data = nullptr;
}

String::String(const String& other)
{
	this->size = other.size;
	delete[] this->data;
	this->data = new char[this->size];
	strcpy_s(this->data, this->size, other.data);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[] this->data;
		this->size = other.size;
		this->data = new char[this->size];
		strcpy_s(this->data, this->size, other.data);
	}
	return *this;
}

String::String(size_t size) : String()
{
	this->size = size;
	this->data = new char[this->size];
}

String::String(const char* data) : String()
{
	this->size = strlen(data);
	this->data = new char[this->size];
	strcpy_s(this->data, strlen(data) + 1, data);
}

String::~String()
{
	delete[] this->data;
}

String& String::concat(const String& other)
{
	char* tmp = new char[this->size];
	strcpy_s(tmp, this->size,this->data);

	int i = strlen(tmp);
	int k = 0;

	this->size += other.size;

	delete[] this->data;
	this->data = new char[this->size];

	strcpy_s(this->data, this->size, tmp);

	for (i; i < this->size; i++)
	{
		this->data[i] = other.data[k];
		k++;
	}

	return *this;
}
String* String::split(const char* delimiter)
{
	String* result = new String[delimitersCounter(*this, delimiter) + 1];

	size_t counter = 0;
	size_t i = 0;

	int currentIndex = this->findWithIndex(i, delimiter);

	while (currentIndex != -1) {
		result[counter++] = generateStr(i, currentIndex);

		i += strlen(delimiter);
		currentIndex = this->findWithIndex(i, delimiter);
	}

	result[counter] = generateStr(i, size);

	return result;
}
String String::generateStr(size_t& i, int endIndex)
{
	String result;
	result.size = endIndex - i;
	result.data = new char[endIndex - i + 1];

	size_t counter = 0;
	for (i; i < endIndex; ++i)
	{
		result.data[counter++] = this->data[i];
	}
	result.data[counter] = '\0';

	return result;
}

int String::findWithIndex(int index, const char* subString)
{
	for (size_t i = index; i < size; ++i)
	{
		if (data[i] == subString[0]) {
			bool contains = true;
			for (size_t j = 1; subString[j]; ++j)
			{
				if (data[i + j] != subString[j]) {
					contains = false;
					break;
				}
			}
			if (contains) {
				return i;
			}
		}
	}
	return -1;
}

size_t String::delimitersCounter(const String& str, const char* delimiter)
{
	size_t count = 0;
	for (size_t i = 0; i < str.getSize(); ++i)
	{
		if (str.getData()[i] == delimiter[0]) {
			bool contains = true;
			for (size_t j = 1; delimiter[j]; ++j)
			{
				if (str.getData()[i + j] != delimiter[j]) {
					contains = false;
					break;
				}
			}
			if (contains) {
				++count;
			}
		}
	}

	return count;
}

char* String::getData() const
{
	return this->data;
}

size_t String::getSize() const
{
	return this->size;
}

bool String::operator==(const String& newString)
{
	for (size_t i = 0; i < this->size; ++i)
	{
		if (data[i] != newString.data[i]) 
		{
			return false;
		}
	}
	return true;
}

void String::print() const
{
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << this->data[i];
	}
	std::cout << std::endl;
}
