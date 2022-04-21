#ifndef __SUGGESTION_INCLUDED__
#define __SUGGESTION_INCLUDED__

#include <string>

using namespace std;

class Suggestion {
	private:
		string suggestedWord;
		int count;
	public:
		Suggestion(string word) {
			suggestedWord = word;
			count = 0;
		}

		Suggestion(string word, int c) {
			suggestedWord = word;
			count = c;
		}

		string getSuggestedWord() {
			return suggestedWord;
		}

		int getCount() {
			return count;
		}

		void incrementCount() {
			count++;
		}

		bool operator == (const Suggestion& s2) {
			return count == s2.count && suggestedWord == s2.suggestedWord;
		}
		bool operator > (const Suggestion& s2) {
			if (count < s2.count) {
				return false;
			} else if (count > s2.count) {
				return true;
			}

			return s2.suggestedWord > suggestedWord;
		}
};


#endif