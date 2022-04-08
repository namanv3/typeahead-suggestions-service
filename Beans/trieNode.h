#ifndef __TRIE_NODE_INCLUDED__
#define __TRIE_NODE_INCLUDED__

const int ALPHABET_SIZE = 26;

class TrieNode {
	private:
		char letter;
		TrieNode* children[ALPHABET_SIZE];
	public:
		TrieNode(char c);

		char getLetter();

		TrieNode* getChild(char c);
};

#endif