
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
 public:
  unordered_map<char, TrieNode*> children;
  bool end_of_word;
  TrieNode() : end_of_word(false) {}
};

class Trie {
 public:
  Trie() { root_ = new TrieNode(); }

  ~Trie() { Destroy(root_); }

  void Insert(const string& word) {
    TrieNode* node = root_;
    for (char ch : word) {
      if (node->children.find(ch) == node->children.end()) {
        node->children[ch] = new TrieNode();
      }
      node = node->children[ch];
    }
    node->end_of_word = true;
  }

  bool Search(const string& word) {
    TrieNode* node = root_;
    for (char ch : word) {
      if (node->children.find(ch) == node->children.end()) {
        return false;
      }
      node = node->children[ch];
    }
    return node->end_of_word;
  }

  bool StartsWith(const std::string& word) {
    TrieNode* node = root_;
    for (char ch : word) {
      if (node->children.find(ch) == node->children.end()) {
        return false;
      }
      node = node->children[ch];
    }
    return true;
  }

  bool Delete(const string& word) { return DeleteHelper(root_, word, 0); }

 private:
  TrieNode* root_;

  void Destroy(TrieNode* node) {
    if (node == nullptr) {
      return;
    }
    for (auto& child : node->children) {
      Destroy(child.second);
    }
    delete node;
  }

  // 删除辅助函数
  bool DeleteHelper(TrieNode* current, const string& word, int index) {
    if (index == word.length()) {
      // 如果不是单词结尾，不需要删除
      if (!current->end_of_word) {
        return false;
      }
      // 标记为非单词结尾
      current->end_of_word = false;
      // 检查是否有子节点
      return current->children.empty();
    }
    char ch = word[index];
    auto it = current->children.find(ch);
    if (it == current->children.end()) {
      return false;
    }
    // 递归删除子节点
    bool shouldDeleteCurrentNode =
        DeleteHelper(it->second, word, index + 1) && !it->second->end_of_word;

    if (shouldDeleteCurrentNode) {
      delete it->second;
      current->children.erase(it);
      return current->children.empty();
    }
    return false;
  }
};