#include <stdlib.h>
#include <stdio.h>

//定义二叉搜索树的结点和树类型
//树类型其实就是结点类型的指针
//因为一般树就是这个数的头结点
typedef struct node
{
	int data;
	struct node *left, *right;
} node, *tree;

//新建二叉搜索树
tree create(int val)
{
	node *root = (tree)malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	root->data = val;
	return root;
}

//插入一个数
tree insert(tree root, int val)
{
	//如果头结点为空，则新建一个头结点(最后直接返回)
	if (root == NULL)
		root = create(val);
	//如果要插入的数小于头结点的数，则将这个数插入左子树
	else if (val < root->data)
		root->left = insert(root->left, val);
	//如果要插入的数大于等于头结点的数，则将这个数插入右子树
	else
		root->right = insert(root->right, val);

	//返回头结点
	return root;
}

//搜索一个数
node* search(tree root, int val)
{
	//如果头结点为空，则返回空
	if (root == NULL)
		return NULL;

	//如果头结点的值和要找的数一致，则直接返回头结点
	if (val == root->data)
		return root;
	//如果要找的数小于头结点的数，则继续在左子树寻找
	else if (val < root->data)
		return search(root->left, val);
	//如果要找的数大于等于头结点的数，则继续在右子树寻找
	else
		return search(root->right, val);
}

//寻找指定子树的最小值结点
node* findmin(tree root) {
	while (root->left != NULL) root = root->left;
	return root;
}

//删除一个数
node* del(node *root, int val)
{
	//如果头结点为空，直接返回头结点
	if (root == NULL)
		return root;
	//如果要删除的数小于头结点的数，则将这个数插入左子树
	else if (val < root->data)
		root->left = del(root->left, val);
	//如果要删除的数大于头结点的数，则将这个数插入右子树
	else if (val > root->data)
		root->right = del(root->right, val);
	//如果要删除的数等于头结点的数，则接下来删除这个结点
	else {
		// Case 1: 如果该结点没有孩子结点，则直接删除
		if (root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		}
		// Case 2: 如果该结点有一个孩子节点，则删除该结点并返回其孩子结点(在函数最后return)
		else if (root->left == NULL) {
			node *temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL) {
			node *temp = root;
			root = root->left;
			free(temp);
		}
		// Case 3: 如果该结点有两个孩子节点，
		// 则先找右子树里的最小值结点和该结点交换，然后再在右子树里边继续删除
		// 或先找左子树里的最大值结点和该结点交换，然后再在左子树里边继续删除
		else {
			node *temp = findmin(root->right);
			root->data = temp->data;
			root->right = del(root->right, temp->data);
		}
	}
	//左后要返回头结点
	return root;
}

//先序遍历
void print_preorder(node *root)
{
	if (root)
	{
		printf("%d ", root->data);
		print_preorder(root->left);
		print_preorder(root->right);
	}

}

//中序遍历
void print_inorder(node *root)
{
	if (root)
	{
		print_inorder(root->left);
		printf("%d ", root->data);
		print_inorder(root->right);
	}
}

//后序遍历
void print_postorder(node *root)
{
	if (root)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		printf("%d ", root->data);
	}
}

//主函数
int main()
{
	int nums[] = { 12, 5, 16, 3, 1, 13, 7, 17, 9, 11, 14, 8, 20, 18 };
	int n = sizeof(nums) / sizeof(nums[0]);
	
	node *tree = NULL;
	int i;
	for (i = 0; i < n; i++)
		tree = insert(tree, nums[i]);

	print_inorder(tree);
	printf("\n");
	node *result = search(tree, 11);
	if (result)
		printf("found\n");
	else
		printf("not found\n");

	tree = del(tree, 11);
	print_inorder(tree);
	printf("\n");
}