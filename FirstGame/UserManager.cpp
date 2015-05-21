#include "UserManager.h"
#include "FileIO.h"

UserManager* UserManager::_instance = nullptr;

UserManager* UserManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new UserManager();
	}
	return _instance;
}

void UserManager::destroyThis()
{
	SAFE_DELETE(_instance);
}

bool UserManager::login()
{
	system("cls");
	string uName, uPwd;
	cout << "请输入用户名和密码" << endl;
	cin >> uName >> uPwd;
	for (int i = 0; i < _user_lsit.size(); i++)
	{
		if (_user_lsit.at(i).name == uName)
		{
			if (_user_lsit.at(i).password == uPwd)
				cout << "登陆成功！" << endl;
				return true;
		}
	}
	cout << "登陆失败！" << endl;
	return false;
}

bool UserManager::registerUser()
{
	system("pause");
	string uName, uPwd;
	cout << "请输入注册用户名和密码,用户名为6-16纯字符,密码为6-16字符数字组合" << endl;
	cin >> uName >> uPwd;
	if (uName.size() < 6 || uName.size() > 16 || uPwd.size() < 6 || uPwd.size() > 16)
	{
		cout << "用户名不和规范" << endl;
		return false;
	}
	for (int i = 0; i < uName.size(); i++)
	{
		if (isdigit(uName.at(i)))
		{
			cout << uName.at(i) <<"用户名不和规范" << endl;
			return false;
		}
	}

	bool containsNum, containsAlpha;
	containsAlpha = containsNum = false;

	for (int i = 0; i < uPwd.size(); i++)
	{
		if (!containsNum && isdigit(uPwd.at(i)))
		{
			containsNum = true;
		}

		if (!containsAlpha && isalpha(uPwd.at(i)))
		{
			containsAlpha = true;
		}
	}

	if (!(containsAlpha && containsNum))
	{
		cout << "密码不符合规范" << endl;
		return false;
	}

	cout << "注册成功！" << endl;
	return true;
}

void UserManager::loadUserFromFile()
{
	_user_lsit = _fileIO->loadUserFromFile(USER_FILE_NAME);
}

