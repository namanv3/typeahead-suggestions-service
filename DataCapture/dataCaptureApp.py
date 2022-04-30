import requests
import time

URL = "http://localhost:18080/fetchTrieContent/"

while True:
	print("Fetching trie content")
	response = requests.get(url = URL)
	trieContent = response.json()["trieContent"]

	trieContentFileHandler = open("latestDictionary.trie", "w+")
	trieContentFileHandler.write(trieContent)
	trieContentFileHandler.close()

	print("Going to sleep")
	time.sleep(10)
