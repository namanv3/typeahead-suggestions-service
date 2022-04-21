#include <fstream>

#include "trieDeserialiser.h"

using namespace std;

string readTrieFileToString();

int main() {
	string trieFileContent = readTrieFileToString();
	TrieNode* trieNode = deserialiseTrieFile(trieFileContent);
	trieNode->printTrie();
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