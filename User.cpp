#include "User.h"
#include<regex>

User::User()
{
	setUsername("Default Username");
	setPassword("Default Password");
	setIsAdmin(false);
}

User::User(String username, String pass, bool isAdmin)
{
	setUsername(username);
	setPassword(pass);
	setIsAdmin(isAdmin);
}

void User::setUsername(const String& newUsername)
{
	this->username = newUsername;
}

void User::setPassword(const String& newPassword)
{
	this->password = newPassword;
}

void User::setIsAdmin(bool newIsAdmin)
{
	this->isAdmin = newIsAdmin;
}

String User::getUsername() const
{
	return this->username;
}

String User::getPassword() const
{
	return this->password;
}

bool User::getIsAdmin() const
{
	return this->isAdmin;
}

void User::print() const
{
	std::cout << "           User" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Username: " << this->username << std::endl;
	std::cout << "Password: " << this->password << std::endl;
	switch (this->isAdmin)
	{
	case false: std::cout << "---User---" << std::endl; break;
	case true: std::cout << "---Admin---" << std::endl; break;
	std::cout << "----------------------------" << std::endl;
	}
}
