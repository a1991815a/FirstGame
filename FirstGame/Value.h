#ifndef __VALUE__
#define __VALUE__
#include "stdafx.h"

class Value{
public:
	enum ValueType{
		None,Int,Float,CharArray,Char
	};

	Value(){
		_type = None;
	}

	Value(const char* value){
		_value._string = value;
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
		const char* _string;
		float _float;
		char _char;
	} _value;
	ValueType _type;

	inline void reset(){
		_type = None;
	};
	
public:
	inline ValueType getType() const{return _type;};
	inline bool isInt() const{if(_type == Int) return true;return false;};
	inline bool isFloat() const{if(_type == Float) return true;return false;};
	inline bool isCharArray() const{if(_type == CharArray) return true;return false;};
	inline bool isNone() const{if(_type == None) return true;return false;};
	inline bool isChar() const { if (_type == Char) return true; return false; };

	inline int asInt() const{ return _value._int; };
	inline float asFloat() const{ return _value._float; };
	inline const char* asCharArray() const{ if (!isCharArray()) { char rollback[] = { _value._char }; return rollback; }; return _value._string; };
	inline char asChar() const{return _value._char; };

};
#endif