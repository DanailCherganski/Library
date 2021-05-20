#include "Library.h"

Library::Library()
{
	setBooks(Vector<Book>::Vector());
	setUsers(Vector<User>::Vector());
}

void Library::setBooks(const Vector<Book>& newBooks)
{
	this->books = newBooks;
}

void Library::setUsers(const Vector<User>& newUsers)
{
	this->users = newUsers;
}

const Vector<Book>& Library::getBooks() const
{
	return books;
}

const Vector<User>& Library::getUsers() const
{
	return users;
}

void Library::booksAll()
{
	for (size_t i = 0; i < books.getSize(); i++)
	{
		books[i].print();
	}
}

void Library::booksInfo(const int id) const
{

}

std::ostream& operator<<(std::ostream& out, const Library& other)
{

	out << "-----------------------" << std::endl;
	out << "|        Books      |" << std::endl;
	out << "-----------------------" << std::endl;
	for (size_t i = 0; i < other.books.getSize(); i++)
	{
		out << "-----------------------" << std::endl;
		other.books[i].print();
	}
	out << "-----------------------" << std::endl;
	/*out << "|        Users     |" << std::endl;

	for (size_t i = 0; i < other.users.getSize(); i++)
	{
		out << "-----------------------" << std::endl;
		other.users[i].print();
	}
	out << "-----------------------" << std::endl;*/
	return out;
}

bool Library::hasBook(const String& book) const
{
	size_t size = books.getSize();
	for (int i = 0; i < size; i++)
	{
		if (books[i].getTitle() == book)
		{
			return true;
		}
	}
	return false;
}

void Library::booksAdd(const Book& newBook)
{
	if (hasBook(newBook.getTitle()))
	{
		std::cout << "There is such book!" << std::endl;
		return;
	}
	this->books[books.getSize() + 1] = newBook.clone();
}

//void Library::booksRemove(const Book& book)
//{
//	for (int i = 0; i < books.getSize(); i++)
//	{
//		if (books[i].getTitle() == book.getTitle())
//		{
//			delete books[i];
//			team[i] = team[size--];
//
//			if (this->size < (this->capacity / 2))
//			{
//				resizeDown();
//			}
//			break;
//		}
//	}
//}
