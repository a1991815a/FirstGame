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
