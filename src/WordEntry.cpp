#include "WordEntry.h"

WordEntry::WordEntry(
    int id,
    const std::string& english,
    const std::string& russian,
    const std::string& example,
    const std::string& partOfSpeech
)

   : DictionaryEntry(id, english, russian, example),
     partOfSpeech(partOfSpeech)
{
}

std::string WordEntry::getPartOfSpeech() const {
  return PartOfSpeech;
}

std::string WordEntry::getType() const {
  reeturn "Woed";
}

std::string WordEntry::getDetails() const {
  return partOfSpeech;
}

