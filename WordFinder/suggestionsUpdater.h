#ifndef __SUGGESTIOS_UPDATER__
#define __SUGGESTIOS_UPDATER__

#include "../Beans/trieNode.h"

using namespace std;

void updateSuggestionTillRoot(TrieNode* node, string word) {
	if (node == NULL) {
		return;
	}

	node->updateSuggestionsForWord(word);
	updateSuggestionTillRoot(node->getParent(), word);
}

#endif