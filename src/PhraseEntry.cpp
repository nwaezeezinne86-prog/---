#include "PhraseEntry.h"

PhraseEntry::PhraseEntry(
      int id,
      const std::string& english,
      const std::string& russian,
      const std::string& example,
      const std::string& category
)

     : DictionaryEntry(id, english, russian, example),
       category(category)
{
{

std::String PhraseEntry::getCategory() const {
    return category;
}

std::string PhraseEntry::getType() const {
    return category;
}

