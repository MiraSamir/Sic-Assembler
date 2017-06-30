#include <cstdlib>
#include <algorithm>
#include "Utility.h"

bool Utility::isLettersOnly(std::string &s) {
	for (unsigned int i = 0; i < s.size(); i++) {
		int uppercaseChar = toupper(s[i]); //Convert character to upper case version of character
		if (uppercaseChar < 'A' || uppercaseChar > 'Z') //If character is not A-Z
				{
			return false;
		}
	}
	//At this point, we have gone through every character and checked it.
	return true; //Return true since every character had to be A-Z
}

bool Utility::isHex(std::string &s) {
	//  return std::regex_match(s, std::regex("0x[0-9a-fA-F]+"));
	for (size_t i = 0; i < s.size(); i++) {
		char current = s[i];
		if (current >= '0' && current <= '9') {
			continue;
		}

		if (current >= 'A' && current <= 'F') {
			continue;
		}

		if (current >= 'a' && current <= 'f') {
			continue;
		}

		return false;
	}

	return true;
}

bool Utility::isWhiteSpacesOnly(std::string &s) {
	return (s.find_first_not_of(' ') == std::string::npos);
}

std::string Utility::to_upper(std::string s) {
	std::string copy = s;
	for (unsigned int l = 0; l < s.length(); l++) {
		copy[l] = toupper(copy[l]);
	}
	return copy;
}

bool Utility::isInteger(std::string &s) {
	if (s.empty() || ((!isdigit(s[0]) && s[0] != '-')))
		return false;
	char * p;
	strtol(s.c_str(), &p, 10);
	return (*p == 0);
}

bool Utility::isComment(std::string &s) {
	if (s[0] == '.' || s[0] == '*')
		return true;
	return false;
}

void Utility::eraseTrailingSpace(std::string &s) {
	s.erase(
			std::find_if(s.rbegin(), s.rend(),
					std::bind1st(std::not_equal_to<char>(), ' ')).base(),
			s.end());
}

void Utility::eraseLeadingSpace(std::string &s) {
	s.erase(s.begin(),
			std::find_if(s.begin(), s.end(),
					std::bind1st(std::not_equal_to<char>(), ' ')));
}
