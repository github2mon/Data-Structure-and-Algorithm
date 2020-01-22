#pragma once

class String
{
private:
	char* str;
	int len;
	int* getNext();
public:
	String();
	String(String& s);
	String(char* s) { *this = s; }
	~String() { delete str; }
	String& operator=(String& s);
	String& operator=(char* s);
	int isEmpty() { return len == 0; }
	int length() { return len; }
	int comp(String s);
	String* concat(String& s);
	String* subString(int pos, int length);
	int replace(String& s1, String& s2);
	int insert(int pos, String& s);
	int delete(int pos, int length);
};

