#include "DictionaryEntry.h"

DictionaryEntry::DictionaryEntry(
   int id,
   const std::string& english,
   const std::string& russian,
   const std::string& example
)

:id(id),
english(english),
russian(russain),
example(example),
learned(false)

{
}

int DictionaryEntry::getId() const {
  return id;
}

std::string DictionaryEntry::getEnglish() const {
  return english;
}

std::string DictionaryEntry::getRussian() const {
  return russian;
}

std::string DictionaryEntry::getExample() const {
  return example;
}

bool DictionaryEntry::isLearned() const {
  return Learned;
}

void DictionaryEntry::setEnglish(const std::string& english) {
  this->english = english;
}

void DictionaryEntry::setRussian(const std::string& russian) {
  this->russian = russian;
}

void DictionaryEntry::setExample(const std::string& example) {
  this->example = example;
}

void DictionaryEntry::markAsLearned() {
  learned = true;
}

