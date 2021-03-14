#pragma once
#ifndef BIDIRECTIONAL_LIST_ON_ARRAY_WORD_CARD_H
#define BIDIRECTIONAL_LIST_ON_ARRAY_WORD_CARD_H

#include<string>
using namespace std;;

class WordCard
{
public:
    WordCard() : word_(""), counter_(0) {};
    WordCard(string s) : word_(s), counter_(0) {};
    WordCard(string s, int x) : word_(s), counter_(x) {};

    WordCard(WordCard& W) : word_(W.word_), counter_(W.counter_) {};
    WordCard operator=(WordCard other);

    WordCard(WordCard &&W) : word_(move(W.word_)), counter_(move(W.counter_)){};
    WordCard* operator=(WordCard&& other);

    ~WordCard();

    string GetWord();
    size_t GetCounter();

    void IncCounter();

    bool operator==(WordCard& other);
    bool operator!=(WordCard& other);

    bool operator<(WordCard& second);

private:
    string word_;
    size_t counter_;
};

#endif //BIDIRECTIONAL_LIST_ON_ARRAY_WORD_CARD_H
