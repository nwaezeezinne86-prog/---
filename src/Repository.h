#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <memory>
#include <algorithm>

//generic repository using a C++ template
// T can be replaced with different classes
template <typename T>
class Repository {
private:
    std::vector<std::shared_ptr<T>> items;

public:
    // Add an item to the repository
void add(std::shared_ptr<T> item) {
     items.push_back(item);
}

// remove an item by its ID
bool removedById(int id) {
  auto oldSize = items.size();

items.erase(
   std::remove_if(
       items.begin(),
       items.end(),
       [id](const std::shared_ptr<T>& item) {
            return item->getId() == id;
       }
  ),
  items.end()
);

return items.size() < oldsize;
}

//find an item by its ID
std::shared_ptr<T> findById(int id) const {
   auto it = std::find_if(
       items.begin(),
       items.end(),
       [id](const std::shared_ptr<T>& item) {
            return item->getId() == id;
       }
);

if (it != items.end()) {
    return *it;
}

return nulltpr;
}

// return all stored items.
const std::vector<std::shared_ptr<T>>& getAll() const {
  return items;
}

// return the number of stored items
std::size_t size() const {
    return items.size();
}

};

#endif
  
  
