#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
    private:
        string value;
        int count;
        TreeNode *left;
        TreeNode *right;
    public:
        TreeNode();
        TreeNode(const string &s, TreeNode*, TreeNode*);
        TreeNode(const TreeNode&);
        void CopyTree();
        int ReleaseTree();
        ~TreeNode();
};

class BinStrTree
{
    private:
        TreeNode *root;
    public:
        BinStrTree();
        BinStrTree(TreeNode*);
        BinStrTree(const BinStrTree &bst);
        ~BinStrTree();
};

TreeNode::TreeNode(): value(""), count(1), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(const string &s = string(), 
                    TreeNode *lchild = nullptr, TreeNode *rchild = nullptr):
                    value(s), count(1), left(lchild), right(rchild) {}

TreeNode::TreeNode(const TreeNode &tn):
    value(tn.value), count(1), left(tn.left), right(tn.right)
{
    if (left)
        left->CopyTree();
    if (right)
        right->CopyTree();
}

void TreeNode::CopyTree()
{
    if (left)
        left->CopyTree();
    if (right)
        right->CopyTree();
    count++;
}

TreeNode::~TreeNode()
{
    if (count)
        ReleaseTree();
}

int TreeNode::ReleaseTree()
{
    if (left)
    {
        if (!left->ReleaseTree())
            delete left;
    }
    if (right)
    {
        if (!right->ReleaseTree())
            delete right;
    }
    count--;
    return count;
}

BinStrTree::BinStrTree(): root(nullptr) {}

BinStrTree::BinStrTree(TreeNode *t = nullptr) : root(t) {}

BinStrTree::BinStrTree(const BinStrTree &bst) : root(bst.root) 
{
    root->CopyTree();
}

BinStrTree::~BinStrTree()
{
    if (!root->ReleaseTree())
        delete root;
}