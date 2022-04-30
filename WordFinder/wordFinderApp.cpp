#include <iostream>
#include <fstream>

#include "trieDeserialiser.h"
#include "wordFinderTrie.h"
#include "apiMethods.h"

using namespace std;

string readTrieFileToString();

int main() {
	string trieFileContent = readTrieFileToString();
	wordFinderTrie = deserialiseTrieFile(trieFileContent);

	crow::SimpleApp app;

    CROW_ROUTE(app, "/findWord/<string>")(findWord);
    CROW_ROUTE(app, "/suggestions/<string>")(findSuggestions);
    CROW_ROUTE(app, "/fetchTrieContent/")(fetchTrieContent);

    app.port(18080).multithreaded().run();
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