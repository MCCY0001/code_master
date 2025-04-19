#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <iostream>
#include <vector>

template <typename Key, typename Value>
class HashTable {
 private:
  struct kv_pair {
    Key key;
    Value value;
    kv_pair(Key k, Value v) : key(k), value(v) {}
  };
  std::vector<std::vector<kv_pair>> table_;
  size_t size_;
  size_t capacity_;
  float load_factor_;

  size_t Hash(Key key) const { return std::hash<Key>{}(key) % capacity_; }

  void Resize() {
    capacity_ *= 2;
    std::vector<std::vector<kv_pair>> new_table(capacity_);
    for (const auto& bucket : table_) {
      for (const auto& kv : bucket) {
        new_table[Hash(kv.key)].push_back(kv);
      }
    }
    table_ = std::move(new_table);
  }

 public:
  HashTable(size_t capacity = 10, float load_factor = 0.75)
      : table_(capacity),
        size_(0),
        capacity_(capacity),
        load_factor_(load_factor) {}

  void Insert(Key key, Value value) {
    if (size_ >= capacity_ * load_factor_) {
      Resize();
    }
    size_t index = Hash(key);
    for (auto& kv : table_[index]) {
      if (kv.key == key) {
        kv.value = value;
        return;
      }
    }
    table_[index].push_back(kv_pair(key, value));
    size_++;
  }

  bool Get(Key key, Value& value) const {
    size_t index = Hash(key);
    for (const auto& kv : table_[index]) {
      if (kv.key == key) {
        value = kv.value;
        return true;
      }
    }
    return false;
  }

  bool Remove(Key key) {
    size_t index = Hash(key);
    for (auto it = table_[index].begin(); it != table_[index].end(); ++it) {
      if (it->key == key) {
        table_[index].erase(it);
        size_--;
        return true;
      }
    }
    return false;
  }
  size_t Size() const { return size_; }

  size_t Capacity() const { return capacity_; }

  float LoadFactor() const { return load_factor_; }

  void Print() const {
    for (size_t i = 0; i < capacity_; i++) {
      std::cout << i << ": ";
      for (const auto& kv : table_[i]) {
        std::cout << kv.key << " " << kv.value << " ";
      }
      std::cout << std::endl;
    }
  }
};

#endif
