#include "trieNode.h"

TrieNode::TrieNode (char c) {
	letter = c;
	isRootNode = false;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		children[i] = 0;
	}
}

TrieNode::TrieNode () {
	letter = "!";
	isRootNode = true;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		children[i] = 0;
	}
}

char TrieNode::getLetter() {
	return letter;
}

bool TrieNode::isRootNode() {
	return isRootNode;
}

TrieNode* TrieNode:: getChild(char c) {
	return children[c - 'a'];
}