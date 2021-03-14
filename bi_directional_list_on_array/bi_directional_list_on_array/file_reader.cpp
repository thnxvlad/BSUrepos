#include "file_reader.h"

vector<string> FileReader::ReadLines(const string& file_path)
{
    ifstream fin(file_path);
    string s;
    vector<string> lines;
    while (getline(fin, s))
    {
        lines.push_back(s);
    }
    return lines;
}

vector<string> FileReader::ReadWords(const string& file_path)
{
    vector<string> lines = ReadLines(file_path);
    vector<string> words;
    for (string s : lines)
    {
        int pos_ = 0;
        for(int i = 0; i < s.length(); i++)
            if (s[i] == ' ' && pos_ - i > 0)
            {
                words.push_back(s.substr(pos_, i - pos_));
                pos_ = i + 1;
            }
    }
    return words;
}