#ifndef DICTIONARY_ENTRY_H
#define DICTIONARY_ENTRY_H

#include <string>

class DictionaryEntry {
protected:
int id;
std::string english;
std::string russian;
std::string example;
bool learned;

public:
    DictionaryEntry(
      int id,
      const std::string& english,
      const std::string& russian,
      const std::string& example
);

virtual ~DictionaryEntry() = default;

int getId() const;
std::string getEnglish() const;
std::string getRussian() const;
std::string getExample() const;
bool isLearned() const;

void setEnglish(const std::string& english);
void setRussian(const std::string& russian);
void setExample(const std::string& example);

void markASLearned();

// Pure virtual functions make this class abstract.
virtual std::string getType() const = 0;
virtual std::string getDetails() const = 0;

};

#endif
