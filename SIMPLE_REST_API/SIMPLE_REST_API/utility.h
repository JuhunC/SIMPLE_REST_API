#pragma once
#include"library.h"
///<summary>Utility for REST API</summary>
namespace util {
	utility::string_t s2st(std::string str); // string to utility::string_t
	std::string st2s(utility::string_t str); // utility::string_t to string
	void printJsonValue(json::value value);
}
///	<summary>Print Json Data Visually.</summary>
/// <param name ="value">json::value</param>
/// <returns>no return</returns>
void util::printJsonValue(json::value value) {
	utility::string_t str = value.to_string();
	int size = 0;
	for (int i = 0; i < str.length(); i++) {
		switch (str.at(i)) {
		case '{':
		case '[':
			wcout << endl;
			for (int s = 0; s < size; s++) wcout << '\t';
			size++;
			wcout << str.at(i) << endl;
			for (int s = 0; s < size; s++) wcout << '\t';
			break;
		case '}':
		case ']':
			size--;
			wcout << endl;
			for (int s = 0; s < size; s++) wcout << '\t';
			wcout << str.at(i) << endl;
			for (int s = 0; s < size; s++) wcout << '\t';
			break;
		case ',':
			wcout << str.at(i) << endl;
			for (int s = 0; s < size; s++) wcout << '\t';
			break;
		default:
			wcout << str.at(i);
			break;
		}
	}
}

///	<summary>Convert utility::string_t into std::string.</summary>
/// <param name ="str">string to convert</param>
/// <returns>Converted string_t</returns>
utility::string_t util::s2st(std::string str) {
	utility::string_t res;
	res.resize(str.length());
	for (int i = 0; i < str.length(); i++) {
		res.at(i) = str.at(i);
	}
	return res;
}
///	<summary>Convert std::string into utility::string_t.</summary>
/// <param name ="str">stirng_ to convert</param>
/// <returns>Converted string</returns>
std::string util::st2s(utility::string_t str) {
	std::string res;
	res.resize(str.length());
	for (int i = 0; i < str.length(); i++) {
		res.at(i) = str.at(i);
	}
	return res;
}