#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileReader {
public:
	vector<string> ReadLines(const string& file_path);
	vector<string> ReadWords(const string& file_path);
};


