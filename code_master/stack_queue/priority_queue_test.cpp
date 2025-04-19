#include "priority_queue.h"

#include <iostream>

using namespace std;

struct Person {
  std::string name;
  int age;

  bool operator<(const Person& other) const { return age < other.age; }
  bool operator>(const Person& other) const { return age > other.age; }
};

int main() {
  PriorityQueue<Person, Compare<Person>> pq;
  pq.Push({"Alice", 25});
  pq.Push({"Bob", 30});
  pq.Push({"Charlie", 20});
  pq.Push({"David", 35});
  while (!pq.Empty()) {
    Person p = pq.Top();
    std::cout << p.name << " " << p.age << std::endl;
    pq.Pop();
  }
}