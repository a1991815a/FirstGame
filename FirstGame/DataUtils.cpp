#include "DataUtils.h"


DataUtils* DataUtils::_instance = nullptr;

DataUtils* DataUtils::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new DataUtils();
	}
	return _instance;
}

void DataUtils::copyMatrix( char**& matrix_dst, char**& matrix_res, int width, int height)
{
	for (int row=0; row<height; row++)
	{
		for (int col=0; col<width; col++)
		{
			matrix_dst[row][col] = matrix_res[row][col];
		}
	}
}

std::string DataUtils::getFromDoubleChar(string& in_data, char left, char right, int& index, int offset /*= 0*/)
{
	string end = "";
	int left_index = 0;
	int right_index = 0;
	for (int i = offset; i < in_data.size(); i++)
	{
		if (in_data.at(i) == left)
		{
			left_index = i + 1;
		}
	}

	for (int i = offset; i < in_data.size(); i++)
	{
		if (in_data.at(i) == right)
		{
			index = i;
			right_index = i - 1;
		}
	}

	return in_data.substr(left_index, right_index - left_index + 1);
}

vector<string> DataUtils::splitString(string& in_data, char split_char, int& index, int offset /*= 0*/)
{
	vector<string> vs;

	int left_index = offset;

	for (int i = offset; i < in_data.size(); i++)
	{
		if (in_data.at(i) == split_char)
		{
			vs.push_back(in_data.substr(left_index, i - left_index + 1));
			left_index = i + 1;
		}
	}
	vs.push_back(in_data.substr(left_index, in_data.size - left_index));

	index = in_data.size() - 1;

	return vs;
}

std::string DataUtils::getFrontChar(string& in_data, char front_char, int& index, int offset /*= 0*/)
{
	for (int i = offset; i < in_data.size(); i++)
	{
		if (in_data.at(i) == front_char)
		{
			index = i;
			return in_data.substr(offset, i - offset + 1);
		}
	}
	return string();
}

void DataUtils::deleteCharFromString(string& in_data, char delete_char, int& index, int offset /*= 0*/)
{
	for (int i = offset; i < in_data.size(); i++)
	{
		if (in_data.at(i) == delete_char)
		{
			index = i;
			in_data.erase(in_data.begin() + i);
			i--;
		}
	}
}
