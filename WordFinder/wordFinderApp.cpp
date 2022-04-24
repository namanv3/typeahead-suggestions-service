#include <iostream>
#include <fstream>

#include "trieDeserialiser.h"
#include "wordFinderTrie.h"

using namespace std;

string readTrieFileToString();

int main() {
	string trieFileContent = readTrieFileToString();
	wordFinderTrie = deserialiseTrieFile(trieFileContent);
	// wordFinderTrie->printTrie();

	while (true) {
		string query;
		cin >> query;
		cout << checkForWord(query) << endl;
	}
}

string readTrieFileToString() {
	ifstream trieFileStream(TRIE_FILENAME);
	string content;
	if (trieFileStream.is_open()) {
		getline(trieFileStream, content);
		trieFileStream.close();
	}
	return content;
}