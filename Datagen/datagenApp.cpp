#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "trieGenerator.h"
#include "../Beans/trieNode.h"

#define WORDS_FILENAME "Datagen/lessWords.txt"

using namespace std;

vector<string> generateWordsVector();

int main() {
	vector<string> words = generateWordsVector();
	TrieNode* trie = generateTrieFromWords(words);
}

vector<string> generateWordsVector() {
	ifstream wordsFileStream(WORDS_FILENAME);
	vector<string> words;
	if (wordsFileStream.is_open()) {
		string currentWord;
		while (getline(wordsFileStream, currentWord)) {
			words.push_back(currentWord);
		}
		wordsFileStream.close();
	}
	return words;
}