#include <stdlib.h>
#include <stdio.h>
 
typedef struct TreeNode {
 	int val;
	struct TreeNode *left;
	struct TreeNode *right;
 }TreeNode;
 

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) 
{
    int i = 0;
    struct TreeNode * proot = NULL;
	int root = 0;
	
	if(postorderSize <=0)
	{
		return NULL;
	}
	
	root = postorder[postorderSize - 1];
    proot = malloc(sizeof(struct TreeNode));
    proot->val = root;
    
    if(postorderSize <=1)
    {
    	proot->left = NULL;
    	proot->right = NULL;
    	return proot;
	}
	
	for(i = 0;i<inorderSize;i++)
	{
		if(inorder[i] == root)
		{
			proot->left =  buildTree(inorder,i, postorder, i);
			proot->right =  buildTree(inorder + i + 1, inorderSize - i- 1, postorder + i, postorderSize- i- 1);
		}	
	}
	return proot;
}


void main()
{
	return;	
}

