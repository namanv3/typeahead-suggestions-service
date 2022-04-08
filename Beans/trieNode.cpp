#include "trieNode.h"

TrieNode::TrieNode (char c) {
	letter = c;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		children[i] = 0;
	}
}

char TrieNode::getLetter() {
	return letter;
}

TrieNode* TrieNode:: getChild(char c) {
	return children[c - 'a'];
}