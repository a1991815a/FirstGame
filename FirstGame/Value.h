#ifndef __VALUE__
#define __VALUE__
#include "stdafx.h"
#include "Ref.h"

class Value: public Ref{
public:
	enum ValueType{
		None,Int,Float,CharArray,Char
	};

	Value(){
		_type = None;
	}

	Value(const char* value){
		strcpy_s(_value._string, 128, value);
		_type = CharArray;
	}

	Value(int value){
		_value._int = value;
		_type = Int;
	}

	Value(float value){
		_value._float = value;
		_type = Float;
	}

private:
	union{
		int _int;
		char _string[128];
		float _float;
		char _char;
	} _value;
	ValueType _type;

	inline void reset(){
		_type = None;
	};
	
	inline ValueType getType() const{return _type;};
	inline bool isInt() const{if(_type == Int) return true;return false;};
	inline bool isFloat() const{if(_type == Float) return true;return false;};
	inline bool isCharArray() const{if(_type == CharArray) return true;return false;};
	inline bool isNone() const{if(_type == None) return true;return false;};
	inline bool isChar() const { if (_type == Char) return true; return false; };

	inline int asInt() const{ if (!isInt()) return 0; return _value._int; };
	inline float asFloat() const{ if (!isFloat()) return 0; return _value._float; };
	inline const char* asCharArray() const{ if (!isCharArray()) return nullptr; return _value._string; };
	inline char asChar() const{ if (!isChar()) return '\0'; return _value._char; };

};
#endif