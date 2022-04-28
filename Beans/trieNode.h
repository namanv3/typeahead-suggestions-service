#ifndef __TRIE_NODE_INCLUDED__
#define __TRIE_NODE_INCLUDED__

#include <vector>

#include "commonConstants.h"
#include "suggestion.h"

class TrieNode {
	private:
		char letter;
		TrieNode* children[ALPHABET_SIZE];
		bool rootNode;
		bool endOfWord;
		Suggestion* topSuggestions[NUM_SUGGESTIONS];
		TrieNode* parent;
	public:
		TrieNode(char c, bool isEndOfWord, TrieNode* parentNode) {
			letter = c;
			rootNode = (c == ROOT_NODE_CHAR);
			endOfWord = isEndOfWord;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				children[i] = NULL;
			}

			for (int i = 0; i < NUM_SUGGESTIONS; i++) {
				topSuggestions[i] = NULL;
			}
			parent = parentNode;
		}

		TrieNode(char c, bool isEndOfWord) {
			letter = c;
			rootNode = (c == ROOT_NODE_CHAR);
			endOfWord = isEndOfWord;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				children[i] = NULL;
			}

			for (int i = 0; i < NUM_SUGGESTIONS; i++) {
				topSuggestions[i] = NULL;
			}
			parent = NULL;
		}

		TrieNode() {
			letter = ROOT_NODE_CHAR;
			rootNode = true;
			endOfWord = false;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				children[i] = NULL;
			}
			for (int i = 0; i < NUM_SUGGESTIONS; i++) {
				topSuggestions[i] = NULL;
			}
			parent = NULL;
		}

		char getLetter() {
			return letter;
		}

		Suggestion** getTopSuggestions() {
			return topSuggestions;
		}

		bool isRootNode() {
			return rootNode;
		}

		bool isEndOfWord() {
			return endOfWord;
		}

		TrieNode** getChildren() {
			return children;
		}

		TrieNode* getChild(char c) {
			return children[c - 'a'];
		}

		void setChild(TrieNode* child, char c) {
			children[c - 'a'] = child; 
		}

		TrieNode* getParent() {
			return parent;
		}

		void setParent(TrieNode* parentNode) {
			parent = parentNode;
		}

		int getNumberOfNonNullChilden() {
			int count = 0;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				if (children[i] != NULL) {
					count++;
				}
			}
			return count;
		}

		void makeEndOfWord() {
			endOfWord = true;
		}

		void insertSuggestion(Suggestion* suggestion) {
			if (suggestion == NULL) {
				return;
			}

			int insertAt = NUM_SUGGESTIONS;
			for (int i = 0; i < NUM_SUGGESTIONS; i++) {
				if (topSuggestions[i] == NULL || *suggestion > *topSuggestions[i]) {
					insertAt = i;
					break;
				}
				if (*suggestion == *topSuggestions[i]) {
					return;
				}
			}

			Suggestion* toInsert = suggestion;
			for (int i = insertAt; i < NUM_SUGGESTIONS; i++) {
				Suggestion* temp = toInsert;
				toInsert = topSuggestions[i];
				topSuggestions[i] = temp;
			}
		}

		void updateSuggestionsFromChild(char c) {
			int i = c - 'a';
			if (children[i] == 0) {
				return;
			}
			Suggestion** childTopSuggestions = children[i]->getTopSuggestions();
			for (int j = 0; j < NUM_SUGGESTIONS; j++) {
				insertSuggestion(childTopSuggestions[j]);
			}
		}

		void printSuggestions() {
			printf("Suggestions: ");
			for (int i = 0; i < NUM_SUGGESTIONS; i++) {
				if (topSuggestions[i] == NULL) {
					printf("\n");
					return;
				}
				printf("%s %d, ", topSuggestions[i]->getSuggestedWord().c_str(), topSuggestions[i]->getCount());
			}
			printf("\n");
		}

		void printTrie() {
			printf("Letter: %c. Parent letter: \"%c\". Is end of word: %d. Number of children: %d\n", 
				letter, parent == NULL ? '?' : parent->getLetter(), endOfWord, getNumberOfNonNullChilden());
			printSuggestions();
			printf("\n");

			for (int i = 0; i < ALPHABET_SIZE; i++) {
				if (children[i] == NULL) {
					continue;
				}
				children[i]->printTrie();
			}
		}

		vector<string> getSuggestedWords() {
			vector<string> suggestions;
			int i = 0;
			while (i < NUM_SUGGESTIONS && topSuggestions[i] != NULL) {
				suggestions.push_back(topSuggestions[i]->getSuggestedWord());
				i++;
			}
			return suggestions;
		}
};

#endif