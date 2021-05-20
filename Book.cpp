#include "Book.h"

int Book::nextID = 1;

Book::Book()
{
	setAuthor("Default Default");
	setTitle("Default title");
	setGenre(TypeGenre::Undefined);
	setDescribtion("No describtion");
	setPublicationYear(1900);
	setTag(Vector<String>::Vector());
	setRating(0);
	id = ++nextID;
}

Book::Book(const String& newTitle, const String& newAuthor, TypeGenre newGenre, const String& newDescribtion, const int newPublicationYear, const Vector<String>& newTag, const double newRating)
{
	setTitle(newTitle);
	setAuthor(newAuthor);
	setGenre(newGenre);
	setDescribtion(newDescribtion);
	setPublicationYear(newPublicationYear);
	setTag(newTag);
	setRating(newRating);
	id = ++nextID;
}

void Book::setAuthor(const String& newAuthor)
{
	this->author = newAuthor;
}

String Book::getAuthor() const
{
	return this->author;
}

void Book::setTitle(const String& newTitle)
{
	this->title = newTitle;
}

String Book::getTitle() const
{
	return this->title;
}

void Book::setGenre(TypeGenre newGenre)
{
	this->genre = newGenre;
}

TypeGenre Book::getGenre() const
{
	return this->genre;
}

void Book::setDescribtion(const String& newDescribtion)
{
	this->describtion = newDescribtion;
}

String Book::getDescribtion() const
{
	return this->describtion;
}

void Book::setPublicationYear(const int newPublicationYear)
{
	this->publicationYear = newPublicationYear;
}

const int Book::getPublicationYear() const
{
	return this->publicationYear;
}

void Book::setTag(const Vector<String>& newTag)
{
	this->tag = newTag;
}

const Vector<String>& Book::getTag() const
{
	return this->tag;
}

void Book::setRating(const double newRating)
{
	this->rating = newRating;
}

const double Book::getRating() const
{
	return this->rating;
}

Book& Book::clone() const
{
	Book cloned;
	cloned.setTitle(this->title);
	cloned.setAuthor(this->author);
	cloned.setDescribtion(this->describtion);
	cloned.setGenre(this->genre);
	cloned.setPublicationYear(this->publicationYear);
	cloned.setRating(this->rating);
	cloned.setTag(this->tag);
	cloned.setRating(this->rating);
	cloned.id = this->id;
	return cloned;
}

void Book::print() const
{
	std::cout << "           " << this->title << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Author: " << this->author << std::endl;
	std::cout << "Genre: ";
	switch (this->genre)
	{
	case TypeGenre::Undefined: 
		std::cout << "Undefined";
		break;
	case TypeGenre::Romance: 
		std::cout << "Romance"; 
		break;
	case TypeGenre::Mystery:	
		std::cout << "Mystery"; 
		break;
	case TypeGenre::Classic:	
		std::cout << "Classic"; 
		break;
	case TypeGenre::Fantasy:	
		std::cout << "Fantasy"; 
		break;
	case TypeGenre::Historical:	
		std::cout << "Historical"; 
		break;
	case TypeGenre::Adventure:	
		std::cout << "Adventure"; 
		break;
	};
	std::cout << std::endl;
	std::cout << "Describtion: " << this->describtion << std::endl;
	std::cout << "Publication Year: " << this->publicationYear << std::endl;
	std::cout << "Key Words: ";
	std::cout << tag[0];
	for (size_t i = 1; i < tag.getSize(); ++i)
	{
		std::cout << ", ";
		std::cout << tag[i];
	}
	std::cout << std::endl;
	std::cout << "Rating: " << this->rating << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << std::endl;
	//std::cout << "----------------------------" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Book& other)
{
	out << "           " << other.title << std::endl;
	out << "----------------------------" << std::endl;
	out << "Author: " << other.author << std::endl;
	out << "Genre: ";
	switch (other.genre)
	{
	case TypeGenre::Undefined: 
		std::cout << "Undefined";
		break;
	case TypeGenre::Romance: 
		std::cout << "Romance"; 
		break;
	case TypeGenre::Mystery:	
		std::cout << "Mystery"; 
		break;
	case TypeGenre::Classic:	
		std::cout << "Classic"; 
		break;
	case TypeGenre::Fantasy:	
		std::cout << "Fantasy"; 
		break;
	case TypeGenre::Historical:	
		std::cout << "Historical";
		break;
	case TypeGenre::Adventure:	
		std::cout << "Adventure"; 
		break;
	};
	out << std::endl;
	out << "Describtion: " << other.describtion << std::endl;
	out << "Publication Year: " << other.publicationYear << std::endl;
	out << "Key Words: ";
	out << other.tag[0];
	for (size_t i = 1; i < other.tag.getSize(); ++i)
	{
		std::cout << ", ";
		std::cout << other.tag[i];
	}
	out << std::endl;
	out << "Rating: " << other.rating << std::endl;
	out << "ID: " << other.id << std::endl;
	out << std::endl;

	return out;
}
