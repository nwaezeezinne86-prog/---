#include "DictionaryManager.h"

#include <iostream>

int main() {

DictionaryManager dictionary;

// add sample words
dictionary.addWord(
    "house",
    "дом",
    "This is my house.",
    "noun"
 );

dictionary.addWord(
    "run",
    "бегать",
    "I run every morning. ",
    "verb"
 );

// add a sample phrase
dictionary.addPhrase(
  "good morning",
  "доброе утро",
  "Good morning, professor!",
  "Greetings"
 );

// display all entries
std::cout << "=== ENGLISH-RUSSIAN DICTIONARY ===\n\n";

for (const auto& entry : dictionary.getSortedByEnglish()) {

std::cout << entry->getId() << "."
          << entry->getEnglish()
          << " ->"
          << entry->getRussian()
          << " [" ,, entry->getType() << "]\n";
std::cout << " Example: "
          << entry->getExample()
          << "\n";
std::cout << " Details: "
          << entry->getDetails()
          << "\n\n";
}

// test search
std::cout << "=== Search: book ===\n";

auto results = dictionary.search("book");

for (const auto& entry : results) {
     std::cout << entry->getEnglish()
               << " ->"
               << entry->getRussian()
               << "\n";
}

// Test marking an entry as learned
dictionary.markLearned(1);

std::cout << "\nEntry 1 learned: "
          << (dictionary.getAll()[0]->isLearned()
                   ? "Yes"
                   : "No")
          << "\n";

return 0;
}
