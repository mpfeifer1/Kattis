#include <bits/stdc++.h>
#include <tr1/memory>

using namespace std;

template <typename T>
struct Node {
  T value;
  tr1::shared_ptr<Node<T> > pointer;
};

template <class T>
struct node_ptr_less {
  bool operator()(const tr1::shared_ptr<Node<T> > &node1,
		  const tr1::shared_ptr<Node<T> > &node2) const {
    return node1->value < node2->value;
  }
};

template <typename T>
vector<T> lis(const vector<T> &n) {
  typedef tr1::shared_ptr<Node<T> > NodePtr;
  vector<NodePtr> pileTops;
  for (typename vector<T>::const_iterator it = n.begin(); it != n.end(); it++) {
    NodePtr node(new Node<T>());
    node->value = *it;
    typename vector<NodePtr>::iterator j =
      lower_bound(pileTops.begin(), pileTops.end(), node, node_ptr_less<T>());
    if (j != pileTops.begin())
      node->pointer = *(j-1);
    if (j != pileTops.end())
      *j = node;
    else
      pileTops.push_back(node);
  }
  vector<T> result;
  for (NodePtr node = pileTops.back(); node != NULL; node = node->pointer)
    result.push_back(node->value);
  reverse(result.begin(), result.end());
  return result;
}





struct segment {
    int first, second;
};

bool operator<(segment& t1, segment& t2) {
    return t1.second <= t2.second;
}

bool operator==(segment& t1, segment& t2) {
    return t1.first == t2.first && t1.second == t2.second;
}

bool cmp(segment& s1, segment& s2) {
    if(s1.first == s2.first) {
        return s1.second > s2.second;
    }
    return s1.first < s2.first;
}

int main() {
    int n;
    cin >> n;
    vector<segment> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
    }

    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto& i : v) {
        i.second *= -1;
    }

    vector<segment> u = lis(v);

    cout << u.size() << endl;
    for(auto& i : u) {
        i.second *= -1;
        cout << i.first << " " << i.second << endl;
    }
}

