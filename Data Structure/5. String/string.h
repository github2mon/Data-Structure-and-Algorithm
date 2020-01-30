#pragma once

class String
{
private:
	char* str;
	int len;
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
	int insert(int pos, String& s);
	int delete(int pos, int length);
};

String::String()
{
	str = new char[1];
	str[0] = '\0';
	len = 0;
}

String::String(String& s)
{
	str = new char[s.len + 1];
	len = s.len;
	str[len] = '\0';
	for (int i = 0; i < s.len; i++)
		str[i] = s.str[i];
}

String& String::operator=(String& s)
{
	if (this == &s) return *this;
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	str[len] = '\0';
	for (int i = 0; i < s.len; i++)
		str[i] = s.str[i];
	return *this;
}

String& String::operator=(char* s)
{
	int len = sizeof(s) / sizeof(char);
	str = new char[len + 1];
	str[len] = '\0';
	for (int i = 0; i < len; i++)
		str[i] = s[i];
	return *this;
}

int String::comp(String s)
{
	for (int i = 0; i < len && i < s.len; i++)
		if (str[i] != s.str[i])
			return str[i] - s.str[i];
	return len - s.len;
}

String* String::concat(String& s)
{
	String* p = new String();
	delete[] p->str;
	p->str = new char[len + s.len + 1];
	p->len = len + s.len;
	p->str[p->len] = '\0';
	for (int i = 0; i < len; i++)
		p->str[i] = str[i];
	for (int i = 0; i < s.len; i++)
		p->str[i + len] = s.str[i];
	return p;
}

String* String::subString(int pos, int length)
{
	if (pos<0 || pos>len || length<0 || length>len - pos + 1)
		return nullptr;
	String* sub = new String();
	delete[] sub->str;
	sub->str = new char[length + 1];
	sub->len = length;
	sub->str[length] = '\0';
	for (int i = 0; i < length; i++)
		sub->str[i] = str[i + pos];
	return sub;
}

int String::insert(int pos, String& s)
{
	if (pos < 0 || pos > len)
		return 0;
	char* p = new char[len + s.len + 1];
	if (!p) { cout << "memory overflow"; exit(0); }
	for (int i = 0; i < len; i++)
		p[i] = str[i];
	delete[] str;
	str = p;
	p = nullptr;
	for (int i = pos; i < len - 1; i++)
		str[i + s.len] = str[i];
	for (int i = 0; i < s.len; i++)
		str[pos + i] = s.str[i];
	len += s.len;
	str[len] = '\0';
	return 1;
}

int String::del(int pos, int length)
{
	if (pos < 0 || pos > len - 1 || length < 0 || length > len - pos)
		return 0;
	for (int i = pos + length; i <= len; i++)
		str[i - length] = str[i];
	return 1;
}
