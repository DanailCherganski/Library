#pragma once
#include<iostream>
#include"String.h"
class User
{
private:
	String username;
	String password;
	bool isAdmin;

public:
	User();
	User(String username, String pass, bool isAdmin);

	void setUsername(const String& newUsername);
	void setPassword(const String& newPassword);
	void setIsAdmin(bool newIsAdmin);

	String getUsername() const;
	String getPassword() const;
	bool getIsAdmin() const;

	void print() const;
};

