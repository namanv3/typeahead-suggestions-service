#ifndef __TRIE_NODE_INCLUDED__
#define __TRIE_NODE_INCLUDED__

const int ALPHABET_SIZE = 26;

class TrieNode {
	private:
		char letter;
		TrieNode* children[ALPHABET_SIZE];
		bool rootNode;
	public:
		TrieNode(char c) {
			letter = c;
			rootNode = false;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				children[i] = 0;
			}
		}

		TrieNode() {
			letter = '!';
			rootNode = true;
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

		TrieNode* getChild(char c) {
			return children[c - 'a'];
		}
};

#endif