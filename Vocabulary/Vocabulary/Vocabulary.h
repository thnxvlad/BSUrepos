#pragma once
#include <string>
#include<map>
#include"WordCard.h"
#include "BiDirectionalListOnArray.h"
#include "containers.h"
class Vocabulary {
public:
	void read_file_to_cards(string file_path);
	WordCard* convert_string_to_word_card(string str);
	void make_frequency_vocab();
	void sort_words(); 
	map<string, size_t> copy_to_map();

private:
	BiDirectionalListOnArray<WordCard*> list_word_cards;

};


