#ifndef __TRIE_GENERATOR_INCLUDED__
#define __TRIE_GENERATOR_INCLUDED__

#include <vector>

#include "../Beans/trieNode.h"

using namespace std;

void insertWord(TrieNode* rootNode, string wordToInsert, string fullWord);

TrieNode* generateTrieFromWords(vector<string>& words) {
	TrieNode* rootNode = new TrieNode();
	for (string wordToInsert : words) {
		insertWord(rootNode, wordToInsert, wordToInsert);
	}
	return rootNode;
}

void insertWord(TrieNode* trieNode, string wordToInsert, string fullWord) {
	bool isLastChar = wordToInsert.length() == 1;
	char childChar = wordToInsert[0];
	TrieNode* childNode = trieNode->getChild(childChar);
	if (childNode == NULL) {
		childNode = new TrieNode(childChar, isLastChar);
		trieNode->setChild(childNode, childChar);
	}

	if (isLastChar) {
		childNode->makeEndOfWord();
		childNode->insertSuggestion(new Suggestion(fullWord));
	} else {
		insertWord(childNode, wordToInsert.substr(1), fullWord);
	}
	trieNode->updateSuggestionsFromChild(childChar);
}

#endif