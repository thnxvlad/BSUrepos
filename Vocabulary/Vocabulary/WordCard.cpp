#include "WordCard.h"

WordCard WordCard::operator=(WordCard other)
{
    return *new WordCard(other);
}

WordCard* WordCard::operator=(WordCard&& other)
{
    string word = move(other.word_);
    int counter = move(other.counter_);
    return new WordCard(word, counter);
}

WordCard::~WordCard()
{
    delete this;
}

string WordCard::GetWord()
{
    return word_;
}

size_t WordCard::GetCounter()
{
    return counter_;
}

void WordCard::IncCounter()
{
    counter_++;
}

bool WordCard::operator==(WordCard& other)
{
    return word_ == other.word_ ? true : false;
}

bool WordCard::operator!=(WordCard& other)
{
    return *this == other ? false : true;
}

bool WordCard::operator<(WordCard& second)
{
    return counter_ < second.GetCounter() ? true : false;
}


    
