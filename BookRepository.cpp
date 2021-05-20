//#include "BookRepository.h"
//#include<fstream>
//
//void BookRepository::copy(const BookRepository& other)
//{
//	setFilepath(other.filepath);
//}
//
//void BookRepository::destroy()
//{
//	delete[] this->filepath;
//}
//
//BookRepository::BookRepository()
//{
//	setFilepath("books.txt");
//}
//
//BookRepository::BookRepository(const BookRepository& other)
//{
//	copy(other);
//}
//
//BookRepository& BookRepository::operator=(const BookRepository& other)
//{
//	if (this != &other)
//	{
//		destroy(); 
//		copy(other);
//	}
//	return *this;
//}
//
//BookRepository::~BookRepository()
//{
//
//	destroy();
//}
//
//void BookRepository::setFilepath(const char* newFilepath)
//{
//	if (newFilepath != nullptr)
//	{
//		//destroy();
//		this->filepath = new char[strlen(newFilepath) + 1];
//		strcpy_s(this->filepath, strlen(newFilepath) + 1, newFilepath);
//	}
//}
//
//const char* BookRepository::getFilepath() const
//{
//	return this->filepath;
//}
//
//void BookRepository::addBook(Book& book)
//{
//	std::ofstream out(this->filepath, std::ios::app); 
//	out << book.getTitle() << std::endl
//		<< book.getAuthor() << std::endl
//		//<< book.getGenre() << std::endl
//		<< book.getDescribtion() << std::endl
//		<< book.getPublicationYear() << std::endl;
//	for (size_t i = 0; i < book.getTag().getSize(); i++)
//	{
//		out << book.getTag()[i];
//	}
//	out << book.getRating() << std::endl;
//	out.close();
//}
//
//void BookRepository::deleteBook(Book& book)
//{
//	std::ifstream in(this->filepath); // отварям books.txt
//	std::ofstream out("temp.txt", std::ios::app);// създаваме и отваряме файл temp.txt
//
//	Book* item = new Book();
//	char buffer[20];
//	while (!in.eof())
//	{
//		in.getline(buffer, 20);
//		item->setTitle(buffer);
//
//		in.getline(buffer, 20);
//		item->setAuthor(buffer);
//
//		//genre
//
//		in.getline(buffer, 20);
//		item->setDescribtion(buffer);
//
//		in.getline(buffer, 20); // buffer = "10" , atoi(buffer) = 10;
//		item->setPublicationYear(atoi(buffer));
//
//		in.getline(buffer, 20); // buffer = "1.2" , atof(buffer) = 1.2;
//		item->setRating(atof(buffer));
//
//		
//	}
//	in.close();
//	out.close();
//	remove(this->filepath);
//	rename("temp.txt", this->filepath);
//}
//
//Vector<Book>* BookRepository::getAll()
//{
//	return nullptr;
//}
