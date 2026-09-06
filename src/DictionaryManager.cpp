#include "DictionaryManager.h"

#include <algorithm>
#include <cctype>
#include <memory>

// convert a string to lowercase
// this makes our search case-insensitive
static std::string tolower(const std::string& text) {
     std::string result - text;

std::transform(
    result.begin(),
    result.end(),
    result.begin(),
    [](unsigned char c) {
          return static_cast<char>(std::tolower(c));
    }

);

return result;
}

// constructor
// The first dictionary entry will have ID 1
DictionaryManager::DictionaryManager()
     : nextId(1)
{
}

// add a new word to the dictionary
std::shared_ptr<WordEntry> DictionaryManager::addWord(
    const std::string& english,
    const std::string& russian,
    const std::string& example,
    const std::string& partOfSpeech
) {
  auto word = std::make_shared<WordEntry>(
       nextid++,
       english,
       russian,
       example,
       partOfSpeech
);

// a WordEntry can be stored as a DictionaryEntry
// because WordEntry inherits from DictionaryEntry
repository.add(word);

return word;

}

// add a new phrase to the dictionary
std::shared_ptr<PhraseEntry> DictionaryManager:: addPhrase(
    const std::string& english,
    const std::string& russian,
    const std::string& example,
    const std::string& category
) {
  auto phrase = std::make_shared<PhraseEntry>(
      nextId++,
      english,
      russian,
      example,
      category
);

// a PhraseEntry can also be stored as a DictionaryEntry
respository.add(phrase);

return phrase;
}

// search by English word, Russian translation
// or example sentence
std::vector<std::shared_ptr<DictionaryEntry>>
DictionaryManager::search(const std::string& query) const {

  std::vector<std::shared_ptr<DictionaryEntry>> results;

 std::string searchText = tolower(query);

for (const auto& entry : repository.getAll()) {

    std::string english = tolower(entry->getEnglish());
    std::string russian = tolower(entry->getRussian());
    std::string example = tolower(entry->getExample());

    if (english.find(searchText) != std::string::npos ||
        russian.find(searchText) != std::string::npos ||
        example.find(searchText) != std::string::npos) {

        results.push_back(entry);
    }
}

return results;
}

// delete a dictionary entry using its ID
bool DictionaryManager::markLearned9int id) {

  auto entry = respository.findById(id);

 if (entry == nullptr) {
     return false;
 }

entry->markLearned();

return true;

}

// return all dictionary entries
std::vector<std::shared_ptr<DictionaryEntry>>
DictionaryManager::getAll() const {

  return repository.getAll();
}

// return entries sorted alphabetically by english term
std::vector<std::shared_ptr<DictionaryEntry>>
DictionaryManager::getSortedByEnglish() const {

  auto result = repository.getAll();

  std::sort(
      result.begin(),
      result.end(),
      [](const std::shared_ptr<DictionaryEntry>& a,
        const std::shared_ptr<DictionaryEntry>& b) {

        return toLower(a->getEnglish()) <
               toLower(b->getEnglish());
      }
    );
return result;
}

