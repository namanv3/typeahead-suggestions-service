#ifndef __TRIE_NODE_INCLUDED__
#define __TRIE_NODE_INCLUDED__

const int ALPHABET_SIZE = 26;
const char ROOT_NODE_CHAR = '!';

class TrieNode {
	private:
		char letter;
		TrieNode* children[ALPHABET_SIZE];
		bool rootNode;
		bool endOfWord;
	public:
		TrieNode(char c, bool isEndOfWord) {
			letter = c;
			rootNode = false;
			endOfWord = isEndOfWord;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				children[i] = 0;
			}
		}

		TrieNode() {
			letter = ROOT_NODE_CHAR;
			rootNode = true;
			endOfWord = false;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				children[i] = 0;
			}

		}

		char getLetter() {
			return letter;
		}

		bool isRootNode() {
			return rootNode;
		}

		bool isEndOfWord() {
			return endOfWord;
		}

		TrieNode* getChild(char c) {
			return children[c - 'a'];
		}

		void setChild(TrieNode* child, char c) {
			children[c - 'a'] = child; 
		}

		void makeEndOfWord() {
			endOfWord = true;
		}
};

#endif