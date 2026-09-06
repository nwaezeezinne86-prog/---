#ifndef PHRASE_ENTRY_H
#define PHRASE_ENTRY_H

#include "DictionaryEntry.h"

class PhraseEntry : public DictionaryEntry {
private:
     std::string category;

public:
    PhraseEntry(
        int id,
        const std::string& english,
        const std::string& russian,
        const std::string& example,
        const std::string& category
);

std::string getCategory() const;

//Polymorphic functions
std::string getType() const override;
std::string getDetails() const override;
};

#endif
