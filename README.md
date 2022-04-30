## Disclaimer
All files, except `API/crow_all.h`, are written by me.

## About this Project

(This project is a work in progress.)

Given a dictionary of words, Word Finder Service tells whether any queried word is a part of the dictionary or not. Beyond that, it suggests words in the dictionary based on what has been typed. These suggestions take into account which words are frequently searched for.

For example, let our dictionary have the words (`camera`, `capture`, `carpenter`, `cart`, `cattle`). To begin with, no word has been searched for, so typing `ca` will give the suggestions `camera`, `capture`, and `carpenter` (assuming max 3 suggestions), basically suggestions in alphabetical order. But if the search is actually for `cattle`, this will update the suggestions, so when next time someone types `ca`, `cattle` will be the first suggestion.

## Prerequisites for Building
This project uses [the Crow C++ micro web framework](https://github.com/ipkn/crow). The file `API/crow_all.h` is directly taken from the repository, with a [minor tweak](https://github.com/moneroexamples/onion-monero-blockchain-explorer/commit/76a0efa8ee3ea5bb466b81d84357d2fd76920cbd) as mentioned in [this thread](https://github.com/ipkn/crow/issues/340).

Crow requires `boost` and `google-perftools` (mentioned in its README). To install these on MacOS:
```
brew install boost google-perftools
```

## How to begin
Firstly, the dictionary of words needs to be preprocessed. For that, build the datagen app using:
```
g++ -std=c++11 Datagen/datagenApp.cpp 
```
Then run the same:
```
./a.out
```

After this, we need to start our Word Finder Service:
```
g++ -std=c++11 WordFinder/wordFinderApp.cpp
```
```
./a.out
```
This Service has two APIs, one for searching for a word, and the other for getting word suggestions.
### 1. Find word:
```
curl localhost:18080/findWord/<word>
```
### 2. Get Word Suggestions
```
curl localhost:18080/suggestions/<query string>
```
## Data Capture App
Whenever Word Finder App is shut down, all the data about searched words is lost. In order to circumvent this, Data Capture App can be used. This App takes the latest data from The Word Finder App every 10 seconds, and stores it in a file. Whenever Word Finder App is restarted, it queries that file to get the initial data. This way, almost all of the search data is retained.

### Prequisites
This is a python script. The `requests` package is required for this:
```
pip3 install requests
```
### How to run
A simple python command does the trick. 
```
python3 DataCapture/dataCaptureApp.py
```
## Pending Work
1. Build some UI for these APIs
