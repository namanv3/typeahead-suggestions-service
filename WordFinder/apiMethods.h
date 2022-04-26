#ifndef __API_METHODS__
#define __API_METHODS__

#include <string>

using namespace std;

string findWord(string query) {
	switch (checkForWord(query)) {
		case FOUND:
			return "Word Found\n";
		case NOT_FOUND:
			return  "Word Not Found\n";
		case NOT_A_WORD:
			return "Not a full word\n";
	}
    return "Invalid request\n";
}

#endif