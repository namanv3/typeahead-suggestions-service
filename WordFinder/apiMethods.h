#ifndef __API_METHODS__
#define __API_METHODS__

#include "../API/crow_all.h"
#include "wordFinder.h"
#include "suggestionsFinder.h"

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

crow::json::wvalue findSuggestions(string query) {
	vector<string> suggestions = checkForSuggestions(query);

	crow::json::wvalue response;
	response["suggestions"] = suggestions;
	return response;
}

#endif