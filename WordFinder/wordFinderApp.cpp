#include <fstream>
#include <string>

#include "../Commons/trieFileConstants.h"

string readTrieFileToString();

int main() {
	string trieFileContent = readTrieFileToString();
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