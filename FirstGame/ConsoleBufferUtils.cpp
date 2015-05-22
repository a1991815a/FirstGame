#include "ConsoleBufferUtils.h"
#include "RenderEngine.h"

ConsoleBufferUtils* ConsoleBufferUtils::_instance = nullptr;

ConsoleBufferUtils* ConsoleBufferUtils::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ConsoleBufferUtils();
		_instance->init();
	}
	return _instance;
}

void ConsoleBufferUtils::init()
{
	_out = _renderEngine->getOutText();
	_display = GetStdHandle(STD_OUTPUT_HANDLE);

	_surface = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
		);

	if (_surface == INVALID_HANDLE_VALUE)
	{
		throw "´´½¨»º³åÇøÊ§°Ü£¡";
	}

	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(_surface, coord);

	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(_display, &curInfo);
	curInfo.bVisible = FALSE;

	SetConsoleCursorInfo(_display, &curInfo);
	SetConsoleCursorInfo(_surface, &curInfo);

	COORD dwSize = {MAX_WIDTH, MAX_HEIGHT};

	SetConsoleScreenBufferSize(_display, dwSize);
	SetConsoleScreenBufferSize(_surface, dwSize);

	

	GetConsoleScreenBufferInfo(_display, &_info);
	
}

void ConsoleBufferUtils::swap()
{
	HANDLE tmp_handle = _display;
	_display = _surface;
	_surface = tmp_handle;
	SetConsoleActiveScreenBuffer(_display);
}

void ConsoleBufferUtils::printf(char** in_data, int width, int height)
{
	for (int row = 0; row < width; row++)
	{
		*_out += in_data[row];
	}
	*_out += '\0';
}

void ConsoleBufferUtils::printf(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	char out_buf[MAX_HEIGHT * MAX_WIDTH] = {0};
	vsprintf_s(out_buf, max_size, format, ap);
	va_end(ap);
	*_out += out_buf;
}

void ConsoleBufferUtils::renderAll()
{
	COORD coord = { 0, 0 };
	WriteConsole(_surface, _out->c_str(), _out->size(), &_out_len, NULL);
	SMALL_RECT rect;
	CHAR_INFO cInfo;
	ScrollConsoleScreenBuffer(_surface, &rect, &rect, coord, &cInfo);
	swap();
	cls(_surface);
}

void ConsoleBufferUtils::cls(HANDLE handle)
{
	_out->clear();
	COORD coord = { 0, 0 };
	FillConsoleOutputCharacter(handle, ' ', max_size, coord, &_out_len);
	FillConsoleOutputAttribute(handle, _info.wAttributes, max_size, coord, &_out_len);
	SetConsoleCursorPosition(handle, coord);
}



