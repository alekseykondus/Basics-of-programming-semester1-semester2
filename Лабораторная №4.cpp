//Вариант 1
//ПРИМЕРЫ ВЫРАЖЕНИЙ:
//(111+222)*(sin(1)-cos(4))
//(11-22*(33+44)*55)*66
//(a + b - c)* d - e * (f - g)
#include <iostream>
#include <cmath>

using namespace std;

struct tree
{
	double data;
	char operation;
	tree* left = NULL;
	tree* right = NULL;
	tree* prev = NULL;
};
int number(char str[100], int i, int j);
bool check(char ch);
struct tree_node
{
	tree* root;
	void AddToTreeData(tree* Tree, double data, char operation)
	{
		if (!Tree)
		{
			Tree = new tree;
			Tree->data = data;
			Tree->operation = operation;
			Tree->left = NULL;
			Tree->right = NULL;
		}
		else
		{
			Tree->data = data;
			Tree->operation = operation;
		}
	}
	tree *search_tree(tree* Tree, int level)
	{
		if (level == 0) return Tree;
		if (Tree)
		{
			search_tree(Tree->left, level-1);
			for (int i = 0; i < level; i++)
				cout << "	";
			cout << Tree->data << endl;
			print(Tree->right, level + 1);
		}

	}
	void fill_tree(char (&str)[100])
	{
		tree* Tree;
		Tree = new tree;
		tree *item = Tree;
		int operation = 0;
		for (int i = 0; i < size(str); i++)
			if (check(str[i]))
				operation++;
		if (str[0] == '-')
			operation--;
		if (operation == 0)
		{
			int j;
			if (str[0] == '-') j = 1;
			else j = 0;
			while (str[j] > 47 && str[j] < 58)
				j++;
			double a;
			a = number(str, 0, j);
			if (str[j] == 's' && str[j + 1] == 'i' && str[j + 2] == 'n')
			{
				j = j + 4;
				while (str[j] != ')')
					j++;
				if ((str[j - 1] > 64 && str[j - 1] < 91) || (str[j - 1] > 96 && str[j - 1] < 123))
				{
					cout << str[j - 1] << " = ";
					cin >> a;
				}
				else
					a = number(str, j + 4, j);
				a = (double)sin(a);
				//cout << a;
				j++;
			}
			else if (str[j] == 'c' && str[j + 1] == 'o' && str[j + 2] == 's')
			{
				j = j + 4;
				while (str[j] != ')')
					j++;
				if ((str[j - 1] > 64 && str[j - 1] < 91) || (str[j - 1] > 96 && str[j - 1] < 123))
				{
					cout << str[j - 1] << " = ";
					cin >> a;
				}
				else
					a = number(str, j + 4, j);
				a = (double)cos(a);
				//cout << a;
				j++;
			}
			else if (j == 0 && (str[j] > 64 && str[j] < 91) || (str[j] > 96 && str[j] < 123))
			{
				cout << str[j] << " = ";
				cin >> a;
			}

			AddToTreeData(Tree, a, NULL);
		}
		else
		{
			int i = 0, level = 0;
			while (str[i])
			{
				if (str[i] == '(')
				{
					int i_copy = i + 1;
					while (str[i_copy] != ')')
					{
						if (str[i_copy] > 47 && str[i_copy] < 58)
							i_copy++;
						else
							break;
					}
					if (str[i_copy] != ')')
					{
						if (item->left == NULL)
						{
							item->left = new tree;
							item->left->prev = item;
							item = item->left;
						}
						else
						{
							item->right = new tree;
							item->right->prev = item;
							item = item->right;
						}
						level++;
					}
				}
				if (str[i] == ')')
				{
					int i_copy = i - 1;
					while (str[i_copy] != '(')
					{
						if (str[i_copy] > 47 && str[i_copy] < 58)
							i_copy--;
						else
							break;
					}
					if (str[i_copy] != '(')
					{
						int count = 0, i1 = 1, i_c = i-1;
						while (i_c >= 0 && (str[i_c+1] != '(' || i1 != 0))
						{
							if (i1 ==1 && check(str[i_c])) 
								count++;
							if (str[i_c] == '(')
								i1--;
							else if (str[i_c] == ')')
								i1++;
							i_c--;
						}
						//cout << "count = " << count << endl;
						//cout << "i_c = " << i_c << endl;
						int j_copy = 0;
						for (int r = 0; r < size(str); r++)
							if (str[r] > 32 && str[r] < 127)
								j_copy++;
						int q = i + 1;
						while ((str[q] > 47 && str[q] < 58) || check(str[q]))
							q++;
						if (q != j_copy)
						{
							int	q_copy = q, i1 = 0;
							while ((str[q_copy] > 47 && str[q_copy] < 58) || check(str[q_copy]) || str[q_copy] == '(' || str[q_copy] == ')')
							{
								if (str[q_copy] == '(') i1++;
								else if (str[q_copy] == ')') i1--;
								q_copy++;
							}
							if (i1 == 0)
								q = q_copy;
							//cout << "i1 = " << i1 << endl;
							//cout << "q_copy" << q_copy << endl;
						}

						bool b = 0;
						//cout << "j_copy = " << j_copy << endl;
						//cout << "q = " << q << endl;
						if (str[i] == ')' && j_copy == q)
						{
							if (str[0] == '(' || str[1] == '(')
							{
								int j;
								if (str[0] == '(') j = 0;
								else if (str[0] != '(' && str[1] == '(') j = 1;
								int i_copy = i - 1, i1 = 1;
								while (i1 != 0)
								{
									if (str[i_copy] == ')')
										i1++;
									else if (str[i_copy] == '(')
										i1--;
									i_copy--;
								}
								//cout << "i_copy = " << i_copy << endl;
								//cout << "j = " << j << endl;
								if (i_copy + 1 == j)
									b = 1;
							}
						}
						//cout << "b = " << b << endl << endl;
						if (i_c == -1 && b == 1) item = Tree;
						else
							for (int r = 0; r < count + 1; r++)
								item = item->prev;
						//item->prev->prev;
					}
				}
				if (str[i] > 47 && str[i] < 58)
				{
					int j = i;
					while (str[j] > 47 && str[j] < 58)
						j++;
					int a;
					if (i > 0 && str[i - 1] == '-')
						a = number(str, i - 1, j);
					else
						a = number(str, i, j);
					if (str[j] == ')')
					{
						int j_copy = j - 1;
						while (str[j_copy] != '(')
						{
							if (str[j_copy] > 47 && str[j_copy] < 58)
								j_copy--;
							else
								break;
						}

						if (str[j_copy] == '(')
							j++;
					}
					int k = j - 1, i1 = 1;
					while (i1 != 0)
					{
						if (str[k] == '(')
							i1--;
						else if (str[k] == ')')
							i1++;
						k--;
					}

					if ((i - 1 > 0 && check(str[i - 1])) || (i - 1 > 0 && str[i - 1] == '(' && check(str[i - 2])))
					{
						if ((j < size(str) && check(str[j]))) 
							//) || (j+1<size(str) && str[j] == ')' && check(str[j+1])))
						{
							int k = i - 1;
							if (str[k] == '(') k--;
							if (check(str[k])) k--;
							while (k > 0 && str[k] > 47 && str[k] < 58)
								k--;
							if ((str[i - 1] == '*' || str[i - 1] == '/') && !(j < size(str) && (str[j] == '*' || str[j] == '/')))
							{
								AddToTreeData(item, a, NULL);
							}
							else if (str[i - 1] == '(' && str[i - 3] == ')' && (str[i - 2] == '*' || str[i - 2] == '/'))
							{
								AddToTreeData(item, a, NULL);
								item = item->prev;
							}
							
							else if (k == 0 && str[i - 1] == '(' && (str[i - 2] == '*' || str[i - 2] == '/')
								&& !(j < size(str) && (str[j] == '*' || str[j] == '/')))
							{
								AddToTreeData(item, a, NULL);
								item = item->prev;
							}
							else
							{
								if (j < size(str) && str[j] == '-' && str[j+1] != '(')
									AddToTreeData(item, NULL, '+');
								else
									AddToTreeData(item, NULL, str[j]);
								item->left = new tree;
								item->left->prev = item;
								AddToTreeData(item->left, a, NULL);
								j++;
								int j_copy = j + 1, i1 = 1;
								if (str[j] == '(')
								{
									while (i1 != 0)
									{
										if (str[j_copy] == '(')
											i1++;
										else if (str[j_copy] == ')')
											i1--;
										j_copy++;
									}
								}
								if (str[j] != '(' || (str[j] == '(' && (str[j_copy] == '*' || str[j_copy] == '/')))
								{
									item->right = new tree;
									item->right->prev = item;
									item = item->right;
								}
							}
						}
						else if (str[j] == ')' && check(str[j + 1]) && str[j + 2] == '(' && str[k + 1] != '*' && str[k + 1] != '/' && k + 1 != 0)
						{
							AddToTreeData(item, a, NULL);
							item = item->prev;
						}
						else
							AddToTreeData(item, a, NULL);
					}
					
					else
					{
						item->left = new tree;
						item->left->prev = item;
						AddToTreeData(item->left, a, NULL);
					}
					i = j - 1;
				}

				else if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
				{
					double a;
					int j = i + 1;
					if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n')
					{
						j = i + 4;
						while (str[j] != ')')
							j++;
						if ((str[j-1] > 64 && str[j-1] < 91) || (str[j-1] > 96 && str[j-1] < 123))
						{
							cout << str[j-1] << " = ";
							cin >> a;
						}
						else 
							a = number(str, i + 4, j);
						a = (double)sin(a);
						//cout << a;
						j++;
					}
					else if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's')
					{
						j = i + 4;
						while (str[j] != ')')
							j++;
						if ((str[j-1] > 64 && str[j-1] < 91) || (str[j-1] > 96 && str[j-1] < 123))
						{
							cout << str[j-1] << " = ";
							cin >> a;
						}
						else 
							a = number(str, i + 4, j);
						a = (double)cos(a);
						//cout << a;
						j++;
					}
					else
					{
						cout << str[i] << " = ";
						cin >> a;
					}
					if (i > 0 && str[i - 1] == '-')
						a = a*(-1);
					if (str[j] == ')')
					{
						int j_copy = j - 1;
						while (str[j_copy] != '(')
						{
							if (str[j_copy] > 47 && str[j_copy] < 58)
								j_copy--;
							else
								break;
						}
						if (str[j_copy] == '(')
							j++;
					}
					int k = j - 1, i1 = 1;
					while (i1 != 0)
					{
						if (str[k] == '(')
							i1--;
						else if (str[k] == ')')
							i1++;
						k--;
					}

					if ((i - 1 > 0 && check(str[i - 1])) || (i - 1 > 0 && str[i - 1] == '(' && check(str[i - 2])))
					{
						if ((j < size(str) && check(str[j])))
							//) || (j+1<size(str) && str[j] == ')' && check(str[j+1])))
						{
							int k = i - 1;
							if (str[k] == '(') k--;
							if (check(str[k])) k--;
							while (k > 0 && str[k] > 47 && str[k] < 58)
								k--;
							if ((str[i - 1] == '*' || str[i - 1] == '/') && !(j < size(str) && (str[j] == '*' || str[j] == '/')))
							{
								AddToTreeData(item, a, NULL);
							}
							else if (str[i - 1] == '(' && str[i - 3] == ')' && (str[i - 2] == '*' || str[i - 2] == '/'))
							{
								AddToTreeData(item, a, NULL);
								item = item->prev;
							}

							else if (k == 0 && str[i - 1] == '(' && (str[i - 2] == '*' || str[i - 2] == '/')
								&& !(j < size(str) && (str[j] == '*' || str[j] == '/')))
							{
								AddToTreeData(item, a, NULL);
								item = item->prev;
							}
							else
							{
								if (j < size(str) && str[j] == '-' && str[j + 1] != '(')
									AddToTreeData(item, NULL, '+');
								else
									AddToTreeData(item, NULL, str[j]);
								item->left = new tree;
								item->left->prev = item;
								AddToTreeData(item->left, a, NULL);
								j++;
								int j_copy = j + 1, i1 = 1;
								if (str[j] == '(')
								{
									while (i1 != 0)
									{
										if (str[j_copy] == '(')
											i1++;
										else if (str[j_copy] == ')')
											i1--;
										j_copy++;
									}
								}
								if (str[j] != '(' || (str[j] == '(' && (str[j_copy] == '*' || str[j_copy] == '/')))
								{
									item->right = new tree;
									item->right->prev = item;
									item = item->right;
								}
							}
						}
						else if (str[j] == ')' && check(str[j + 1]) && str[j + 2] == '(' && str[k + 1] != '*' && str[k + 1] != '/' && k + 1 != 0)
						{
							AddToTreeData(item, a, NULL);
							item = item->prev;
						}
						else
							AddToTreeData(item, a, NULL);
					}

					else
					{
						item->left = new tree;
						item->left->prev = item;
						AddToTreeData(item->left, a, NULL);
					}
					i = j - 1;
				}

				else if (check(str[i]))
				{
					if (i != 0)
					{
						int k = i - 1;
						if (str[k] != ')')
						{
							while (k > 0 && str[k] > 47 && str[k] < 58)
								k--;
							if (k >= 0 && ((str[k] > 64 && str[k] < 91) || (str[k] > 96 && str[k] < 123)))
								k--;
						}
						else
						{
							int i1 = 0;
							while (k > 0 && (str[k + 1] != '(' || i1 != 0))
							{
								if (str[k] == '(')
									i1--;
								else if (str[k] == ')')
									i1++;
								k--;
							}
						}
						int j_copy = 0;
						for (int r = 0; r < size(str); r++)
							if (str[r] > 32 && str[r] < 127)
								j_copy++;
						int q = i+1;
						while ((str[q] > 47 && str[q] < 58) || check(str[q]))
							q++;
						if (q != j_copy)
						{
							int	q_copy = q, i1 = 0;
							while ((str[q_copy] > 47 && str[q_copy] < 58) || check(str[q_copy]) || str[q_copy] == '(' || str[q_copy] == ')')
							{
								if (str[q_copy] == '(') i1++;
								else if (str[q_copy] == ')') i1--;
								q_copy++;
							}
							if (i1 == 0)
								q = q_copy;
							//cout << "i1 = " << i1 << endl;
							//cout << "q_copy" << q_copy << endl;
						}
						//cout << "q = " << q << "	" << endl;
						//cout << "j_copy = " << j_copy << endl;

						bool b = 0;
						if (str[i-1] == ')' && j_copy == q)
						{
							if (str[0] == '(' || str[1] == '(')
							{
								int j;
								if (str[0] == '(') j = 0;
								else if ( str[0] != '(' && str[1] == '(') j = 1;
								int i_copy = i - 2, i1 = 1;
								while (i1 != 0)
								{
									if (str[i_copy] == ')')
										i1++;
									else if (str[i_copy] == '(')
										i1--;
									i_copy--;
								}
								if (i_copy + 1 == j)
									b = 1;
							}
						}
						//cout << "b = " << b << endl;
						//cout << "k = " << k << endl;
						if (i > 1 && (((str[k] == '*' || str[k] == '/') && str[i-1] != ')') || ((str[i] == '*' || str[i] == '/')
							&& str[i - 1] == ')' && b == 1)))
							//  j != size(str) &&  (str[0] != '(' || (str[0] == '(' && (str[j] == '\n' || str[j] == ' ' || str[j+1] == -52)))))) ////?????
						{
							if (Tree->operation == '+' || Tree->operation == '-' || Tree->operation == '*' || Tree->operation == '/')
							{
								tree* Tree_new = new tree;
								if (str[i] == '-' && str[i + 1] != '(')
									AddToTreeData(Tree_new, NULL, '+');
								else
									AddToTreeData(Tree_new, NULL, str[i]);
								Tree_new->right = Tree;
								Tree_new->right->prev = Tree_new;
								Tree_new->left = new tree;
								item = Tree_new->left;
								Tree = Tree_new;
							}
							else if (!(Tree->operation == '+' || Tree->operation == '-' || Tree->operation == '*' || Tree->operation == '/'))
							{
								item = Tree;
								if (str[i] == '-' && str[i + 1] != '(')
									AddToTreeData(item, NULL, '+');
								else
									AddToTreeData(item, NULL, str[i]);
								if (item->left == NULL)
								{
									item->left = new tree;
									item->left->prev = item;
									item = item->left;
								}
								else if (item->right == NULL)
								{
									item->right = new tree;
									item->right->prev = item;
									item = item->right;
								}
							}
						}
						else
						{
							if (str[i] == '-' && str[i + 1] != '(')
								AddToTreeData(item, NULL, '+');
							else
								AddToTreeData(item, NULL, str[i]);

							item->right = new tree;
							item->right->prev = item;
							item = item->right;
						}
					}
				}
				i++;
			}
		}
		root = Tree;
	}

	double count(tree* Tree)
	{
		if (Tree->left != NULL)
			count(Tree->left);
		if (Tree->right != NULL)
			count(Tree->right);
		if (Tree->operation != NULL)
			switch(Tree->operation)
			{
				case '+': Tree->data = Tree->left->data + Tree->right->data; break;
				case '*':Tree->data = Tree->left->data * Tree->right->data; break;
				case '/':Tree->data = Tree->left->data / Tree->right->data; break;
			}
		Tree->operation = NULL;
		Tree->left = NULL;
		Tree->right = NULL;
		return Tree->data;
	}

	void print(tree *Tree, int level)
	{
		if (Tree)
		{
			print(Tree->left, level + 1);
			for (int i = 0; i < level; i++)
				cout << "	";
			if (Tree->data != NULL)
				cout << Tree->data << endl;
			else
				cout << Tree->operation << endl;
			print(Tree->right, level + 1);
		}
	}
	void print_tree ()
	{
		print(root, 0);
	}
};

int number (char str[100], int i, int j)
{
	int res = 0;
	if (str[i] == '-')
	{
		for (int k = i+1; k < j; k++)
		{
			res = res * 10 + str[k] - '0';
		}
		res *= -1;
	}
	else 
		for (int k = i; k < j; k++)
		{
			res = res * 10 + str[k] - '0';
		}
	return res;
}

bool check(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}

bool correct_input(char (&str)[100])
{
	for (int qwer = 0; qwer < size(str) / 2; qwer++)
	{
		int m = 0;
		for (int i = 0; i < size(str); i++)
			if (str[i] > 32 && str[i] < 127)
				m++;
		if (str[0] == '*' || str[0] == '/' || check(str[m - 1]))
			return false;
		for (int i = 0; i < size(str); i++)
			for (int i = 0; i < size(str); i++)
				if (str[i] == 32)
					for (int j = i; j < size(str); j++)
						str[j] = str[j + 1];

		int i1 = 0;
		for (int i = 0; i < size(str); i++)
		{
			if (str[i] == '(')
				i1++;
			else if (str[i] == ')')
				i1--;
			if (str[i] == ':') str[i] = '/';
			if ((str[i] < 127 && str[i] > 122) || (str[i] >= 32 && str[i] < 40)
				|| (str[i] > 58 && str[i] < 65))
				return false;
			if (check(str[i]) && check(str[i + 1]))
				return false;
			if (i1 < 0)
				return false;
		}
		if (i1 != 0)
			return false;

		for (int p = 0; p < 3; p++)
			for (int i = 0; i < size(str); i++)
			{
				if (str[i] == '(' && str[i - 1] != 'n' && str[i - 2] != 'i' && str[i - 3] != 's'
					&& str[i - 1] != 's' && str[i - 2] != 'o' && str[i - 3] != 'c'
					&& (i == 0 || (i > 0 && str[i - 1] != '*' && str[i - 1] != '/')))
				{
					int i_copy = i + 1, i1 = 1;
					while (i1 != 0)
					{
						if (str[i_copy] == '(')
							i1++;
						else if (str[i_copy] == ')')
							i1--;
						i_copy++;
					}
					if (i_copy == size(str) || (i_copy < size(str) && str[i_copy] != '*' && str[i_copy] != '/'))
					{
						for (int j = i; j < size(str); j++)
						{
							str[j] = str[j + 1];
							if (i > 0 && str[i - 1] == '-' && j < i_copy - 1)
							{
								if (str[j] == '+') str[j] = '-';
								else if (str[j] == '-') str[j] = '+';
							}
						}
						for (int j = i_copy - 2; j < size(str); j++)
						{
							//cout << "line678" << endl;
							str[j] = str[j + 1];
						}
					}
				}
			}
		for (int i = 0; i < size(str); i++)
		{
			if (str[i] == '(')
			{
				if (i > 0 && (str[i - 1] == '*' || str[i - 1] == '/'))
				{
					int i_copy = i + 1, i1 = 1;
					while (i1 != 0)
					{
						if (str[i_copy] == '(')
							i1++;
						else if (str[i_copy] == ')')
							i1--;
						i_copy++;
					}
					int ch = 0, ch_1 = 0, ch_2 = 0;
					i1 = 1;
					for (int r = i + 1; r < i_copy; r++)
					{
						if (i1 == 1)
						{
							if (check(str[r])) ch++;
							if (str[r] == '*') ch_1++;
							else if (str[r] == '/') ch_2++;
						}
						if (str[r] == '(')
							i1++;
						else if (str[r] == ')')
							i1--;
					}
					//cout << "i = " << i << "	ch = " << ch << "	ch_1 = " << ch_1 << "	ch_2 = " << ch_2 << endl;
					if (ch == ch_1 || ch == ch_2)
					{
						for (int j = i; j < size(str); j++)
							str[j] = str[j + 1];
						for (int j = i_copy - 2; j < size(str); j++)
						{
							//cout << "line721" << endl;
							str[j] = str[j + 1];
						}
					}
				}
			}
			if (str[i] == ')' && (str[i + 1] == '*' || str[i + 1] == '/'))
			{
				int i_copy = i - 1, i1 = 1;
				while (i1 != 0)
				{
					if (str[i_copy] == '(')
						i1--;
					else if (str[i_copy] == ')')
						i1++;
					i_copy--;
				}
				int ch = 0, ch_1 = 0, ch_2 = 0;
				i1 = 1;
				for (int r = i - 1; r >= 0; r--)
				{
					if (i1 == 1)
					{
						if (check(str[r])) ch++;
						if (str[r] == '*') ch_1++;
						else if (str[r] == '/') ch_2++;
					}
					if (str[r] == '(')
						i1--;
					else if (str[r] == ')')
						i1++;
				}
				//cout << "i_copy = " << i_copy << endl;
				//cout << "i = " << i << "	ch = " << ch << "	ch_1 = " << ch_1 << "	ch_2 = " << ch_2 << endl;
				if (ch == ch_1 || ch == ch_2)
				{
					for (int j = i_copy + 1; j < size(str); j++)
						str[j] = str[j + 1];
					for (int j = i - 1; j < size(str); j++)
					{
						//cout << "line761" << endl;
						str[j] = str[j + 1];
					}
				}

			}
		}
	}
}
int main() 
{
	char str[100];
	while (1)
	{
		cout << "Enter arithmetic expression: " << endl;
		cin.getline(str, 100, '\n');
		if (correct_input(str))
			break;
		else
			cout << "EROR" << endl;
	}
	cout << "Your expression: " << str << endl;
	
	tree_node *expression = new tree_node;

	expression->fill_tree(str);
	expression->print_tree();
	cout << "REZ: " <<
		expression->count(expression->root);
}
