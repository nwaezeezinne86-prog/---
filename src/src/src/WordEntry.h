#ifndef WORD_ENTRY_H
#define WORD_ENTRY_H

#include "DictionaryEntry.h"

class WordEntry : public DictionaryEntry {
private:
   std::string partOfSpeech;

public:
   WordEntry(
int id,
const std::string& english,
const std::string& russian,
const std::string& example,
const std::string& partOfSpeech
);

std::string getPartOfSpeech() const;

// Polymorphic functions
std::string getType() const override;
std::string getDetails() const override;

};

#endif
