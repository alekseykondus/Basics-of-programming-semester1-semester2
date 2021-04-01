struct tree
{
	double data;
	tree* left = nullptr;
	tree* right = nullptr;
};

void ex1(tree*& Tree)
{
	if (Tree->left->left != nullptr)
		ex1(Tree->left);

	if (Tree->right != nullptr)
		ex1(Tree->right);

	tree* item = Tree->left;
	Tree->right = Tree->left;
	Tree->left = item;
}

