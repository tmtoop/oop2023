#ifndef __MYSTRING_INCLUDED__

class MyString
{
private:
	size_t m_Size;
	char* m_Arr;

	void copy(const MyString& other);
	void erase();

public:
	MyString();
	MyString(const char* str);

	MyString(const MyString& other);
	MyString& operator=(const MyString& rhs);
	~MyString();

	int length() const;
	char& at(size_t index);
	int find(char c, size_t from = 0);
	bool empty() const;
	MyString substr(size_t pos = 0, size_t n = 0);
	void append(const MyString& str);
	void print();

};

#endif // !__MYSTRING_INCLUDED__

