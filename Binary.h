#ifndef BINARY

#include <iostream>
#include <cstddef>
#include <stdexcept>
using namespace std;


struct Node {
    constexpr Node(int key, double data, Node * right, Node * left):key(key),data(data),right(right),left(left){}
    int key;
    double data;
    Node * right;
    Node * left;
};

void printPostorder(Node * Root);
void insert(Node * & p, int key, double data);
void remove(Node * & p, const int & key);
const double & find(Node * p, const int & to_be_found);
double & edit(Node * p, const int & to_be_changed);
void delete_tree(Node * & p);
Node * getMax(Node * p);

unsigned int max_height(Node * p);
unsigned int min_height(Node * p);
unsigned int size(Node * p);
bool is_balanced(Node * p);

#endif
