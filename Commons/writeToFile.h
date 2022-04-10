#ifndef __WRITE_TO_FILE_INCLUDED__
#define __WRITE_TO_FILE_INCLUDED__

#include <fstream>
#include <string>

void writeToFile(string content, string filename) {
	ofstream outputFile;
	outputFile.open(filename);
	outputFile << content;
 	outputFile.close();
}

#endif