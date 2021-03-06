#include <fstream>

#include "trieGenerator.h"
#include "../Commons/writeTrieToFile.h"

using namespace std;

vector<string> generateWordsVector();

int main() {
	vector<string> words = generateWordsVector();
	TrieNode* trieNode = generateTrieFromWords(words);
	writeTrieToFile(trieNode, TRIE_FILENAME);
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