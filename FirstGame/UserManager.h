#ifndef __USERMANAGER__
#define __USERMANAGER__
#include "stdafx.h"

#define _userManager UserManager::getInstance()

struct User{
	string name;
	string password;
};

class UserManager{
public:
	static UserManager* getInstance();
	static void destroyThis();
private:
	static UserManager* _instance;
public:
	bool login();
	bool registerUser();
	void loadUserFromFile();
private:
	vector<User> _user_lsit;
};
#endif