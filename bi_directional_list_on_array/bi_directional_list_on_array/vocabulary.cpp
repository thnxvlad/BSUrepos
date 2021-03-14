#include <map>
#include "vocabulary.h"
#include "file_reader.h"


WordCard* Vocabulary::convert_string_to_word_card(string str)
{
    return new WordCard(str);
}

void Vocabulary::read_file_to_cards(string file_path)
{
    FileReader FR;
    for(auto S : FR.ReadWords(file_path))
    {
        list_word_cards.PushBack(new WordCard(S));
    }
}

void Vocabulary::make_frequency_vocab()
{
    map<string, size_t> M = copy_to_map();
    list_word_cards.Clear();
    for(auto X : M)
    {
        list_word_cards.PushBack(new WordCard(X.first, X.second));
    }
}

void Vocabulary::sort_words()
{
    multimap<string, size_t> MM;
    for(int i = 0; i < list_word_cards.Size(); i++)
    {
        string S = (*list_word_cards[i])->GetWord();
        size_t C = (*list_word_cards[i])->GetCounter();
        MM.insert({S,C});
    }
    list_word_cards.Clear();
    for(auto X : MM)
    {
        list_word_cards.PushBack(new WordCard(X.first, X.second));
    }
}

map<string, size_t> Vocabulary::copy_to_map()
{
    map<string, size_t> M;
    for(int i = 0; i < list_word_cards.Size(); i++)
    {
        string S = (*list_word_cards[i])->GetWord();
        size_t C = (*list_word_cards[i])->GetCounter();
        if(M.find(S) == M.end())
            M[S] = 0;
        else M[S] += C;
    }
    return M;
}
