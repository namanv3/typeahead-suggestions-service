#ifndef __STRING_UTILS__
#define __STRING_UTILS__

#include <vector>
#include <string>

using namespace std;

vector<string> splitString(string content, char splitter) {
	vector<string> split;
	string temp = "";
	for (size_t i = 0; i < content.size(); i++) {
		if (content[i] != splitter) {
			temp += content[i];
		} else {
			split.push_back(temp);
			temp = "";
		}
	}
	if (temp.size() != 0) {
		split.push_back(temp);
	}
	return split;
}

bool isLowerCase(char c) {
	return c >= 'a' && c <= 'z';
}

#endif