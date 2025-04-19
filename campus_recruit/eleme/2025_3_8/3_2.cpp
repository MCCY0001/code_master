/**
 * 问题描述：
 * 小柒最近想到了一个好玩的游戏，这个游戏一共会进行 n
 * 轮，每一轮，小柒会从下方三种操作中选择一种进行：
 * 1. 在黑板上写一个整数 x；
 * 2. 擦去黑板上的一个整数 x（此操作之前保证黑板上有这个整数）；
 * 3. 询问黑板上哪个数字与整数 x 的异或值最大（若黑板上此时没有数字，则输出
 * -1）。 对于每一次询问操作，需要输出对应的答案。
 *
 * 代码思路：
 * 1. 使用一个 std::set 来模拟黑板，存储整数。
 * 2. 使用一个 std::map 来映射操作码（1, 2, 3）到对应的操作函数。
 * 3. 在 main 函数中读取输入的操作轮数 n
 * 和每一轮的操作码及整数，然后根据操作码执行相应的操作。
 */

#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
 public:
  TrieNode* children[2];  // 0 和 1 两个子节点
  int count[2];           // 记录每个子节点的计数

  TrieNode() {
    children[0] = children[1] = nullptr;
    count[0] = count[1] = 0;
  }
};

class BinaryTrie {
 public:
  BinaryTrie() { root_ = new TrieNode(); }
  ~BinaryTrie() { Clear(root_); }

  void Insert(int number) {
    TrieNode* node = root_;
    for (int i = 31; i >= 0; --i) {
      int bit = (number >> i) & 1;
      if (node->children[bit] == nullptr) {
        node->children[bit] = new TrieNode();
      }
      node->count[bit] += 1;
      node = node->children[bit];
    }
  }

  void Remove(int number) {
    TrieNode* node = root_;
    for (int i = 31; i >= 0; --i) {
      int bit = (number >> i) & 1;
      node->count[bit] -= 1;
      if (node->count[bit] == 0) {
        delete node->children[bit];
        node->children[bit] = nullptr;
        return;
      }
      node = node->children[bit];
    }
  }

  int GetMaxXor(int number) const {
    TrieNode* node = root_;
    if (!node) return -1;
    int result = 0;
    for (int i = 31; i >= 0; --i) {
      int bit = (number >> i) & 1;
      int opposite_bit = 1 - bit;
      if (node->count[opposite_bit] > 0) {
        result |= (1 << i);
        node = node->children[opposite_bit];
      } else {
        node = node->children[bit];
      }
    }
    return result;
  }

 private:
  TrieNode* root_;

  void Clear(TrieNode* node) {
    if (!node) return;
    Clear(node->children[0]);
    Clear(node->children[1]);
    delete node;
  }
};

// 处理输入
int main() {
  BinaryTrie trie;
  int n;
  vector<int> result;
  cin >> n;  // 读取操作数量

  while (n--) {
    int op, x;
    cin >> op >> x;

    if (op == 1) {
      trie.Insert(x);
    } else if (op == 2) {
      trie.Remove(x);
    } else {
      if (op == 3) {
        result.push_back(trie.GetMaxXor(x));
      }
    }
  }
  for (int number : result) {
    cout << number << '\n';
  }

  return 0;
}
