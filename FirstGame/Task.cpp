#include "Task.h"

Task::~Task()
{
	for (int row = 0; row < height; row++)
	{
		delete[] texture[row];
	}

	delete[] texture;
}

bool Task::init()
{
	return true;
}

