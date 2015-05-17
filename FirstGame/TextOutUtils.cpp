#include "TextOutUtils.h"
#include "RenderEngine.h"

TextOutUtils* TextOutUtils::_instance = nullptr;

TextOutUtils* TextOutUtils::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new TextOutUtils();
	}
	return _instance;
}
