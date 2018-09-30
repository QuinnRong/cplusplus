#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

struct BinaryTreeNode
{
    int mValue;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
};

bool ReadStream(istream& istr, int& number)
{
    if (istr.eof()) return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch;
    istr >> ch;
    int i = 0;
    while (!istr.eof() && ch != ',')
    {
        buffer[i++] = ch;
        istr >> ch;
    }

    bool isNumeric = false;
    if (i > 0 && buffer[0] != '$')
    {
        number = atoi(buffer);
        isNumeric = true;
    }

    return isNumeric;
}

void Deserialize(BinaryTreeNode** pRoot, istream& istr)
{
    int number;
    if (ReadStream(istr, number))
    {
        *pRoot = new BinaryTreeNode;
        (*pRoot)->mValue = number;
        (*pRoot)->pLeft = nullptr;
        (*pRoot)->pRight = nullptr;
        Deserialize(&((*pRoot)->pLeft), istr);
        Deserialize(&((*pRoot)->pRight), istr);
    }
}

void Serialize(BinaryTreeNode* pRoot, ostream& ostr)
{
    if (pRoot == nullptr)
    {
        ostr << "$,";
        return;
    }
    ostr << pRoot->mValue << ",";
    Serialize(pRoot->pLeft, ostr);
    Serialize(pRoot->pRight, ostr);
}

void PreOrder(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return;
    printf("%d ", pRoot->mValue);
    PreOrder(pRoot->pLeft);
    PreOrder(pRoot->pRight);
}

void InOrder(BinaryTreeNode* root)
{
    if (root == nullptr) return;
    InOrder(root->pLeft);
    printf("%d ", root->mValue);
    InOrder(root->pRight);
}

int main()
{
    BinaryTreeNode* pRoot;
    istringstream istr("1,2,4,$,$,$,3,5,$,$,6,$,$,");
    Deserialize(&pRoot, istr);
    PreOrder(pRoot); printf("\n");
    InOrder(pRoot); printf("\n");

    ostringstream ostr("");
    Serialize(pRoot, ostr);
    cout << ostr.str() << endl;
}