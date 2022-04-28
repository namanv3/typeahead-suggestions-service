#ifndef __TRIE_DESERIALISER__
#define __TRIE_DESERIALISER__

#include "../Beans/trieNode.h"
#include "../Commons/stringUtils.h"
#include "../Commons/trieFileConstants.h"

using namespace std;

int getNumberOfNonNullChilden(string nodeString);

bool checkIfEndOfWord(string nodeString);

void addSuggestions(TrieNode* node, string nodeString);

TrieNode* deserialiseTrieNode(vector<string> nodes, int& currIdx, TrieNode* parent);

TrieNode* deserialiseTrieFile(string trieFileContent) {
	vector<string> nodes = splitString(trieFileContent, END_OF_NODE[0]);
	int idx = 0;
	return deserialiseTrieNode(nodes, idx, NULL);
}

TrieNode* deserialiseTrieNode(vector<string> nodes, int& currIdx, TrieNode* parent) {
	string nodeString = nodes[currIdx];
	char letter = nodeString[0];
	bool isEndOfWord = checkIfEndOfWord(nodeString);
	TrieNode* node = new TrieNode(letter, isEndOfWord ,parent);
	addSuggestions(node, nodeString);

	int numChildren = getNumberOfNonNullChilden(nodeString);
	for (int i = 0; i < numChildren; i++) {
		currIdx++;
		TrieNode* child = deserialiseTrieNode(nodes, currIdx, node);
		node->setChild(child, child->getLetter());
	}

	return node;
}

void addSuggestions(TrieNode* node, string nodeString) {
	int currIdx = 1;
	string currWord = "";
	string currCount = "";
	bool readingWord = true;
	while (currIdx < nodeString.size()) {
		if (readingWord) {
			if (nodeString[currIdx] == NO_SUGGESTION[0]) {
				return;
			}
			if (nodeString[currIdx] >= 'a' && nodeString[currIdx] <= 'z') {
				currWord += nodeString[currIdx];
			} else {
				currCount += nodeString[currIdx];
				readingWord = false;
			}
		} else {
			if (nodeString[currIdx] >= '0' && nodeString[currIdx] <= '9') {
				currCount += nodeString[currIdx];
			} else {
				int count = stoi(currCount);
				Suggestion* s = new Suggestion(currWord, count);
				node->insertSuggestion(s);
				if (nodeString[currIdx] == IS_END_OF_WORD_FLAG[0]
					|| nodeString[currIdx] == IS_NOT_END_OF_WORD_FLAG[0]) {
					return;
				}
				readingWord = true;
				currWord = nodeString[currIdx];
				currCount = "";
			}
		}
		currIdx++;
	}
}

int getNumberOfNonNullChilden(string nodeString) {
	int i = nodeString.size() - 1;
	string num = "";
	while (nodeString[i] >= '0' && nodeString[i] <= '9') {
		num = nodeString[i] + num;
		i--;
	}
	return stoi(num);
}

bool checkIfEndOfWord(string nodeString) {
	int i = nodeString.size() - 1;
	while (nodeString[i] >= '0' && nodeString[i] <= '9') {
		i--;
	}
	return nodeString[i] == IS_END_OF_WORD_FLAG[0];
}

#endif