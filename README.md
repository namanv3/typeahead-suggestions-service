## Disclaimer
All files, except `API/crow_all.h`, are written by me.

## Prerequisites
This project uses [the Crow C++ micro web framework](https://github.com/ipkn/crow). The file `API/crow_all.h` is directly taken from the repository, with a [minor tweak](https://github.com/moneroexamples/onion-monero-blockchain-explorer/commit/76a0efa8ee3ea5bb466b81d84357d2fd76920cbd) as mentioned in [this thread](https://github.com/ipkn/crow/issues/340).

Crow requires `boost` and `google-perftools` (mentioned in its README). To install these on MacOS:
```
brew install boost google-perftools
```
Hopefully this is the only installation needed.
