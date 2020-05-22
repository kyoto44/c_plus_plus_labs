#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"
#include <math.h>

using namespace std;

void BubbleSort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

TreeNode *CreateMinimalBST(const int *array, const int start, const int end)
{
    if (end < start)
        return nullptr;
    const int mid = (start + end) / 2;
    auto bTree = new TreeNode(array[mid]);
    bTree->SetLeftNode(CreateMinimalBST(array, start, mid - 1));
    bTree->SetRightNode(CreateMinimalBST(array, mid + 1, end));
    return bTree;
}

int main()
{
    BinaryTree bTree;
    bTree.Insert(2);
    bTree.Insert(9);
    bTree.Insert(4);
    bTree.Insert(8);
    bTree.Insert(1);
    bTree.Insert(7);
    bTree.Insert(3);
    int array[] = {4, 14, 3, 2, 5};
    BubbleSort(array, sizeof(array) / sizeof(array[0]));
    BinaryTree minimalBTree;
    minimalBTree.SetRoot(CreateMinimalBST(array, 0, sizeof(array) / sizeof(array[0]) - 1));
    return 0;
}
