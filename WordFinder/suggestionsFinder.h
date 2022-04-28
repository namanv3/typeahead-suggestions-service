#ifndef __SUGGESTIOS_FINDER__
#define __SUGGESTIOS_FINDER__

#include <vector>
#include <string>

#include "wordFinderTrie.h"

vector<string> checkForSuggestions(string query, TrieNode* node);

vector<string> checkForSuggestions(string query) {
	if (query == "") {
		return wordFinderTrie->getSuggestedWords();
	}

	TrieNode* startingNode = wordFinderTrie->getChild(query[0]);
	return checkForSuggestions(query, startingNode);
}

vector<string> checkForSuggestions(string query, TrieNode* trieNode) {
	vector<string> empty;
	if (trieNode == NULL) {
		return empty;
	}
	char currentChar = query[0];
	char nodeLetter = trieNode->getLetter();
	if (query.size() == 1) {
		return trieNode->getSuggestedWords();
	}

	char nextChar = query[1];
	if (!isLowerCase(nextChar)) {
		return empty;
	}
	TrieNode* nextNode = trieNode->getChild(nextChar);
	return checkForSuggestions(query.substr(1), nextNode);
}

#endif