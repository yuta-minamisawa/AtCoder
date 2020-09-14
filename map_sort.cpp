#include <boost/foreach.hpp>
#include <iostream>
#include <map>
#include <queue>
#include <string>

typedef std::map<std::string, int> container;
typedef std::pair<std::string, int> value_type;

struct second_order {
  bool operator()(const value_type& x, const value_type& y) const {
    return x.second > y.second;
  }
};

int main() {
  container src;
  src["あ"] = 3;
  src["い"] = 2;
  src["う"] = 1;
  src["え"] = 10;
  src["お"] = 8;
  std::priority_queue<value_type, std::vector<value_type>, second_order> que;
  std::pair<std::string, int> p;
  BOOST_FOREACH (p, src) { que.push(p); }
  while (!que.empty()) {
    value_type item = que.top();
    std::cout << item.first << "(" << item.second << ")" << std::endl;
    que.pop();
  }
}