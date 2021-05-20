#pragma once
#include <iostream>
class String
{
private:
	char* data;
	size_t size;

public:
	String(); 
	String(const String& other); 
	String& operator=(const String& other);
	String(size_t size); 
	String(const char* data); 
	~String(); 

	String& concat(const String& other);
	String* split(const char* delimiter);
	String generateStr(size_t& i, int endIndex);
	int findWithIndex(int index, const char* subString);
	size_t delimitersCounter(const String& str, const char* delimiter);

	char* getData() const;
	size_t getSize() const;

	bool operator==(const String&);

	void print() const;
	
	friend std::istream& operator>>(std::istream& in, String& other)
	{
		std::cout << "Enter string length: ";
		in >> other.size;
		std::cout << "\nEnter the string: ";
		in.getline(other.data, other.size);
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const String& other) 
	{
		for (size_t i = 0; i < other.size; ++i) 
		{
			out << other.data[i];
		}
		return out;
	}
};


