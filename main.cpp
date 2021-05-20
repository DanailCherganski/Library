#include"Library.h"
int main()
{
	String b1("lion"), b2("wardrobe"), b3("witch");
	Vector<String> tags_first_book;
	tags_first_book.push(b1);
	tags_first_book.push(b2);
	tags_first_book.push(b3);
	Book b("Narnia", "Lewis", TypeGenre::Fantasy, "action book", 1999, tags_first_book, 7.90);
	//b.print();

	User user1("Petko", "Petko123", false), user2;
	//user2.print();
	//user1.print();

	Library l1;
	l1.booksAdd(b);
	//l1.booksAll();


	return 0;
}