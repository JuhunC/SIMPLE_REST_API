#pragma once
#include"utility.h"
///	<summary>My Header format containing only one set.</summary>
class my_header {
public:
	utility::string_t a, b;/// <value name="a">Header Key</value><value name="b">Header Data</value>
	my_header(utility::string_t a_, utility::string_t b_, bool cut);
	utility::string_t first() { return a; };
	utility::string_t second() { return b; };
	void print();
};
/// <summary>my_header Constructor</summary>
/// <param name="a_">header key value</param>
/// <param name="b_">header data value</param>
/// <param name="cut">Decide to cut 0, last idx character</param>
my_header::my_header(utility::string_t a_, utility::string_t b_, bool cut){
	a = a_;
	if (cut == true)
		b = b_.substr(1, b_.length() - 2);
	else b = b_;
}
/// <summary>Print my_header data</summary>
void my_header::print() {
	wcout << a << "\t:\t" << b << endl;
}
