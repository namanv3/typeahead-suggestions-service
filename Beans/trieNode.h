#ifndef __TRIE_NODE_INCLUDED__
#define __TRIE_NODE_INCLUDED__

#include <vector>
#include <list>

#include "commonConstants.h"
#include "suggestion.h"

class TrieNode {
	private:
		char letter;
		TrieNode* children[ALPHABET_SIZE];
		bool rootNode;
		bool endOfWord;
		list<Suggestion> topSuggestions;
		TrieNode* parent;
	public:
		TrieNode(char c, bool isEndOfWord, TrieNode* parentNode) {
			letter = c;
			rootNode = (c == ROOT_NODE_CHAR);
			endOfWord = isEndOfWord;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				children[i] = NULL;
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

			parent = NULL;
		}

		TrieNode() {
			letter = ROOT_NODE_CHAR;
			rootNode = true;
			endOfWord = false;
			for (int i = 0; i < ALPHABET_SIZE; i++) {
				children[i] = NULL;
			}

			parent = NULL;
		}

		char getLetter() {
			return letter;
		}

		list<Suggestion> getTopSuggestions() {
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

		void insertSuggestion(Suggestion suggestion) {
			list<Suggestion>::iterator it;
			for (it = topSuggestions.begin(); it != topSuggestions.end(); it++) {
				if (suggestion > *it) {
					break;
				}
				if (suggestion == *it) {
					return;
				}
			}
			topSuggestions.insert(it, suggestion);
		}

		void addNewSuggestionOrIncrement(string word) {
			list<Suggestion>::iterator it;
			for (it = topSuggestions.begin(); it != topSuggestions.end(); it++) {
				if (it->getSuggestedWord() == word) {
					break;
				}
			}
			Suggestion* toInsert = new Suggestion(word, it->getCount() + 1);
			topSuggestions.erase(it);
			insertSuggestion(*toInsert);
		}

		void updateSuggestionsFromChild(char c) {
			int i = c - 'a';
			if (children[i] == 0) {
				return;
			}
			list<Suggestion> childTopSuggestions = children[i]->getTopSuggestions();
			list<Suggestion>::iterator it;
			for (it = childTopSuggestions.begin(); it != childTopSuggestions.end(); it++) {
				insertSuggestion(*it);
			}
		}

		void printSuggestions() {
			printf("Suggestions: ");
			list<Suggestion>::iterator it;
			for (it = topSuggestions.begin(); it != topSuggestions.end(); it++) {
				printf("%s %d, ", it->getSuggestedWord().c_str(), it->getCount());
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
			list<Suggestion>::iterator it;
			for (it = topSuggestions.begin(); it != topSuggestions.end(); it++) {
				suggestions.push_back(it->getSuggestedWord());
			}
			return suggestions;
		}
};

#endif