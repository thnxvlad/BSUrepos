#pragma once
#ifndef BIDIRECTIONAL_LIST_ON_ARRAY_FILE_READER_H
#define BIDIRECTIONAL_LIST_ON_ARRAY_FILE_READER_H
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileReader {
public:
    vector<string> ReadLines(const string& file_path);
    vector<string> ReadWords(const string& file_path);
};
#endif //BIDIRECTIONAL_LIST_ON_ARRAY_FILE_READER_H
