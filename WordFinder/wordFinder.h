#ifndef __WORD_FINDER__
#define __WORD_FINDER__

#include "wordFinderTrie.h"
#include "suggestionsUpdater.h"
#include "../Beans/wordSearchStatus.h"
#include "../Beans/trieNode.h"
#include "../Commons/stringUtils.h"

using namespace std;

WordSearchStatus checkInTrieNode(string query, TrieNode* trieNode, string fullWord);

WordSearchStatus checkForWord(string query) {
	if (query == "" || !isLowerCase(query[0])) {
		return NOT_FOUND;
	}
	TrieNode* startingNode = wordFinderTrie->getChild(query[0]);
	return checkInTrieNode(query, startingNode, query);
}

WordSearchStatus checkInTrieNode(string query, TrieNode* trieNode, string fullWord) {
	if (trieNode == NULL) {
		return NOT_FOUND;
	}
	char currentChar = query[0];
	char nodeLetter = trieNode->getLetter();
	if (query.size() == 1 && trieNode->isEndOfWord()) {
		updateSuggestionTillRoot(trieNode, fullWord);
		return FOUND;
	} else if (query.size() == 1) {
		return NOT_A_WORD;
	}
	char nextChar = query[1];
	if (!isLowerCase(nextChar)) {
		return NOT_FOUND;
	}
	TrieNode* nextNode = trieNode->getChild(nextChar);
	return checkInTrieNode(query.substr(1), nextNode, fullWord);
}

#endif