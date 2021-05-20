#pragma once
#include"Vector.h"
#include"String.h"

enum class TypeGenre {
	Undefined,
	Romance,
	Mystery,
	Classic,
	Fantasy, 
	Historical,
	Adventure
};

class Book
{
private:
	String author;
	String title;
	TypeGenre genre;
	String describtion;
	int publicationYear;
	Vector<String> tag;
	double rating;
	static int nextID;

public:
	int id;
	Book();
	Book(const String& newTitle, const String& newAuthor, TypeGenre newGenre, const String& newDescribtion,
		const int newPublicationYear, const Vector<String>& newTag, const double newRating);

	Book& clone() const;

	void setAuthor(const String& newAuthor);
	String getAuthor() const;

	void setTitle(const String& newTitle);
	String getTitle() const;

	void setGenre(TypeGenre newGenre);
	TypeGenre getGenre() const;

	void setDescribtion(const String& newDescribtion);
	String getDescribtion() const;

	void setPublicationYear(const int newPublicationYear);
	const int getPublicationYear() const;

	void setTag(const Vector<String>& newTag);
	const Vector<String>& getTag() const;

	void setRating(const double newRating);
	const double getRating() const;

	void print() const;
	friend std::ostream& operator<<(std::ostream& out, const Book& other);

};

