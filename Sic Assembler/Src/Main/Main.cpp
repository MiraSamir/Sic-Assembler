#include <iostream>
#include <cstdlib>
#include "../Controller/Controller.h"

using namespace std;
bool isInteger(std::string &s) {
	if (s.empty() || ((!isdigit(s[0]) && s[0] != '-')))
		return false;
	char * p;
	strtol(s.c_str(), &p, 10);
	return (*p == 0);
}
int main() {
	cout << "Enter your src file path :-\n";
	string srcFilePath;
	getline(cin, srcFilePath);
	Controller *controller = new Controller();
	controller->assemble(srcFilePath);
	cout << "Assembling operation is done\n";

	return 0;
}

