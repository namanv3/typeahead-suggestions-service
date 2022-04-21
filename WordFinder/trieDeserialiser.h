#ifndef __TRIE_DESERIALISER__
#define __TRIE_DESERIALISER__

#include "../Beans/trieNode.h"
#include "../Commons/stringUtils.h"
#include "../Commons/trieFileConstants.h"

using namespace std;

TrieNode* deserialiseTrieFile(string trieFileContent) {
	vector<string> nodes = splitString(trieFileContent, END_OF_NODE[0]);
	return NULL;
}

#endif