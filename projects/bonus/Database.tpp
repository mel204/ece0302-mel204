#include "Database.hpp"

template <typename T>
Database<T>::Database() {
    // TODO

    // start with clear binary trees
    clear();
}

template <typename T>
bool Database<T>::isEmpty() {
    // TODO
    return key1.isEmpty() && key2.isEmpty() && explored.isEmpty();
}

template <typename T>
std::size_t Database<T>::getNumberOfEntries() {
    // TODO
    return numEntries;
}

template <typename T>
bool Database<T>::add(std::string key11, std::string key22, const T& item) {
    // TODO

    // if both keys are present insert into binary trees
    key1.insert(key11, item);
    key2.insert(key22, item);

    // add to explored list and increment numEntries
    explored.insert(explored.getLength(), item);
    numEntries += 1;

    return key1.insert(key11, item);

}

template <typename T>
bool Database<T>::remove(std::string key) {
    // TODO

    if(key1.remove(key) && key2.remove(key))
    {
        numEntries -= 1;
        explored.remove(stoi(key));
        return true;
    } else
    {
        return false;
    }

}

template <typename T>
void Database<T>::clear() {
    // TODO

    explored.clear();
    numEntries = 0;
    key1.destroy();
    key2.destroy();
}

template <typename T>
T Database<T>::getValue(std::string key) {
    // TODO

    if(contains(key))
    {
        T item;
        key1.retrieve(key, item);
        return item;

    } else throw std::range_error("key not found");
}

template <typename T>
bool Database<T>::contains(std::string key) {
    // TODO

    //two temp items to check items
    T item1;
    T item2;

    if(key1.retrieve(key, item1) && key2.retrieve(key, item2))
    {
        //return true it items are the same
        if (item1 == item2)
            return true;

    } else
    {
        return false;
    }
}
