## Disclaimer
All files, except `API/crow_all.h`, are written by me.

## About this Project

Given a dictionary of words, Word Finder Service tells whether any queried word is a part of the dictionary or not. Beyond that, it suggests words in the dictionary based on what has been typed. These suggestions take into account which words are frequently searched for.

For example, let our dictionary have the words (`camera`, `capture`, `carpenter`, `cart`, `cattle`). To begin with, no word has been searched for, so typing `ca` will give the suggestions `camera`, `capture`, and `carpenter` (assuming max 3 suggestions), basically suggestions in alphabetical order. But if the search is actually for `cattle`, this will update the suggestions, so when next time someone types `ca`, `cattle` will be the first suggestion.

## Prerequisites for Building
This project uses [the Crow C++ micro web framework](https://github.com/ipkn/crow). The file `API/crow_all.h` is directly taken from the repository, with a [minor tweak](https://github.com/moneroexamples/onion-monero-blockchain-explorer/commit/76a0efa8ee3ea5bb466b81d84357d2fd76920cbd) as mentioned in [this thread](https://github.com/ipkn/crow/issues/340).

Crow requires `boost` and `google-perftools` (mentioned in its README). To install these on MacOS:
```
brew install boost google-perftools
```

## How to begin: 
