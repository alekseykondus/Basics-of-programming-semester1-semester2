//Умова: Дано бінарне дерево пошуку. Знайти його висоту h. Серед всіх вершин на рівні [h/2] видалити всі вершини, у яких висота лівого піддерева та висота правого піддерева однакові.

struct tree
{
	double data;
	tree* left = nullptr;
	tree* right = nullptr;
};

void delete_tree(tree*& Tree) //освобождаем память от дерева
{
	if (Tree != nullptr)
	{
		delete_tree(Tree->left);
		delete_tree(Tree->right);
		delete Tree;
	}
}

void check_and_delete(tree*& Tree, int r, int l)// r - высота правого поддерева, l - высота левого поддерева
{
	if (Tree)
	{
		l++;
		check_and_delete(Tree->left, r, l);

		r++;
		check_and_delete(Tree->right, r, l);
	}
	if (r == l)
		delete_tree(Tree);
}

void half_the_height(tree*& Tree, int level, int h)
{
	if (Tree)
	{
		half_the_height(Tree->left, level + 1, h);
		if (level == h / 2)
			check_and_delete(Tree, 0, 0);

		half_the_height(Tree->right, level + 1, h);
		if (level == h / 2)
			check_and_delete(Tree, 0, 0);
	}
}

void height(tree*& Tree, int level, int &h) //находим высоту h
{
	if (Tree)
	{
		height(Tree->left, level + 1, h);
		if (h < level)
			h = level;

		height(Tree->right, level + 1, h);
		if (h < level)
			h = level;
	}
	half_the_height(Tree, 0, h);//запускаем функцию, которая выполняет вторую часть уловия (удаляет ....)
}

