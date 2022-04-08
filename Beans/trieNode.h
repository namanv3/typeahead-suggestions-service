#ifndef __TRIE_NODE_INCLUDED__
#define __TRIE_NODE_INCLUDED__

const int ALPHABET_SIZE = 26;

class TrieNode {
	private:
		char letter;
		TrieNode* children[ALPHABET_SIZE];
		bool isRootNode;
	public:
		TrieNode(char c);

		TrieNode();

		char getLetter();

		bool isRootNode();

		TrieNode* getChild(char c);
};

#endif