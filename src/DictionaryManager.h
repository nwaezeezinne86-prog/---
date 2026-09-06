#ifndef DICTIONARY_MANAGER_H
#define DICTIONARY_MANAGER_H

#include "DictionaryEntry.h"
#include "WordEntry.h"
#include "PhraseEntry.h"
#include "Repository.h"

#include <memory>
#include <string>
#include <vector>

class DictionaryManager {
private:
    Repository<DictionaryEntry> repository;
    int nextId;

public:
   DictionaryManager();

   std::shared_ptr<WoedEntry> addWord(
       const std::string& english,
       const std::string& russian,
       const std::string& example,
       const std::string& category
);

std::vector<std::shared_ptr<DictionaryEntry>> search(
     const std::string& query
) cinst;

bool deleteEntry(int id);

bool markLearned(int id);

std::vector<std::shared_ptr<DictionaryEntry>> getAll() const;

std::vector<std::shared_ptr<DictionaryEntry>> getSortedByEnglish() const;
};

#endif
std::
