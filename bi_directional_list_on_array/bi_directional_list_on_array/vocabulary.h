#pragma once
#ifndef BIDIRECTIONAL_LIST_ON_ARRAY_VOCABULARY_H
#define BIDIRECTIONAL_LIST_ON_ARRAY_VOCABULARY_H
#include <string>
#include<map>
#include"word_card.h"
#include "bidirectional_list_on_array.h"
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

#endif //BIDIRECTIONAL_LIST_ON_ARRAY_VOCABULARY_H
