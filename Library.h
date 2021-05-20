#pragma once
#include"Book.h"
#include"User.h"
#include<iostream>
#include<cstring>

class Library
{
private:
	Vector<Book> books;
	Vector<User> users;

public:
	Library();

	void setBooks(const Vector<Book>& newBooks);
	void setUsers(const Vector<User>& newUsers);
	const Vector<Book>& getBooks()const;
	const Vector<User>& getUsers()const;

	friend std::ostream& operator<<(std::ostream& out, const Library& other);

	void booksAll();

	void booksInfo(const int id) const;

	// � ����� String �� ������� ����� find, ����� �� ����� ���� ���������� ������ �� ������� � ���� ������ (����. ���� ��������� �� ����������� title
	// �� ������� � ����� �� ���������� �� ������� ��� ����� � �����)
	void booksFindTitle() const;
	void booksFindAuthor() const;
	void booksFindTag() const;

	bool hasBook(const String& book) const;
	void booksAdd(const Book& newBook);
	
	void booksRemove(const Book& book);

	void usersAdd();
	void usersRemove();

	// ��������� ���� ��������/ merge sort
	void sort(bool(*comparator)(const Book& first, const Book& second), bool isReversed);
	bool isReversed();
};

