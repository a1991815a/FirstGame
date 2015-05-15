#include "TextOut.h"
#include "RenderEngine.h"

TextOut* TextOut::_instance = nullptr;

TextOut* TextOut::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new TextOut();
	}
	return _instance;
}
