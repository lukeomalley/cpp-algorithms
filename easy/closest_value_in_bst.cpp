#include <cmath>
#include <iostream>
#include <float.h>

using namespace std;

class BST
{
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);

  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target);
int findClosestValueInBstHelper(BST *tree, int target, int closest);

int findClosestValueInBst(BST *tree, int target)
{
  return findClosestValueInBstHelper(tree, target, tree->value);
}

int findClosestValueInBstHelper(BST *tree, int target, int closest)
{
  BST *currentNode = tree;
  while (currentNode != NULL)
  {
    if (abs(target - closest) > abs(target - currentNode->value))
    {
      closest = currentNode->value;
    }

    if (target < currentNode->value)
    {
      currentNode = currentNode->left;
    }
    else if (target > currentNode->value)
    {
      currentNode = currentNode->right;
    }
    else
    {
      break;
    }
  }

  return int(closest);
}

BST::BST(int val)
{
  value = val;
  left = NULL;
  right = NULL;
}

int main()
{
  BST *root = new BST(10);
  root->left = new BST(5);
  root->left->left = new BST(2);
  root->left->right = new BST(7);
  root->left->left->left = new BST(1);
  root->left->left->right = new BST(3);
  root->right = new BST(15);
  root->right->right = new BST(20);
  root->right->left = new BST(12);
  root->right->left->right = new BST(14);
  root->right->left->left = new BST(11);

  int expected = 7;
  int actual = findClosestValueInBst(root, 8);

  cout << "Expected: " << expected << endl;
  cout << "Actual: " << actual << endl;
  assert(expected == actual);
}