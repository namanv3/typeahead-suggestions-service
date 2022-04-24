#ifndef __WORD_FINDER_TRIE__
#define __WORD_FINDER_TRIE__

#include "../Beans/wordSearchStatus.h"
#include "../Beans/trieNode.h"
#include "../Commons/stringUtils.h"

TrieNode* wordFinderTrie;

WordSearchStatus checkInTrieNode(string query, TrieNode* trieNode);

WordSearchStatus checkForWord(string query) {
	if (query == "" || !isLowerCase(query[0])) {
		return NOT_FOUND;
	}
	TrieNode* startingNode = wordFinderTrie->getChild(query[0]);
	return checkInTrieNode(query, startingNode);
}

WordSearchStatus checkInTrieNode(string query, TrieNode* trieNode) {
	if (trieNode == NULL) {
		return NOT_FOUND;
	}
	char currentChar = query[0];
	char nodeLetter = trieNode->getLetter();
	if (query.size() == 1 && trieNode->isEndOfWord()) {
		return FOUND;
	} else if (query.size() == 1) {
		return NOT_A_WORD;
	}
	char nextChar = query[1];
	if (!isLowerCase(nextChar)) {
		return NOT_FOUND;
	}
	TrieNode* nextNode = trieNode->getChild(nextChar);
	return checkInTrieNode(query.substr(1), nextNode);
}

#endif