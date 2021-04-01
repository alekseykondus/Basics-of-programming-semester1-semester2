#include <iostream>
using namespace std;

struct vocabulary
{
	char ukr[20];
	char eng[20];
	int count;
};
struct Node
{
	vocabulary data;
	Node* left;
	Node* right;
};
int check(char* mas1, char* mas2, int n)
// функция проверяет два массива на схожесть и возращает ближайший номер ячеек, которые отличаются
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (mas1[i] != mas2[i])
			return count;
		count++;
	}
}

void AddToTree_Alphabetically(Node*& Tree_Alphabetically, vocabulary data)
// функция для добавления элементов в дерево, которое строится по алфавиту 
{
	int i = 0;
	if (Tree_Alphabetically && data.eng[0] == Tree_Alphabetically->data.eng[0])
		i = check(data.eng, Tree_Alphabetically->data.eng, size(data.eng));
	if (!Tree_Alphabetically)
	{
		Tree_Alphabetically = new Node;
		Tree_Alphabetically->data = data;
		Tree_Alphabetically->left = NULL;
		Tree_Alphabetically->right = NULL;
	}
	else if (data.eng[i] < Tree_Alphabetically->data.eng[i])
		AddToTree_Alphabetically(Tree_Alphabetically->left, data);
	else
		AddToTree_Alphabetically(Tree_Alphabetically->right, data);
}

void CreatTree_Alphabetically(Node*& Tree_Alphabetically)
// функция для постройки дерева словаря по алфавиту (считывает с файла слова и добавляет их в дерево)
{
	FILE* dict;
	vocabulary word;
	if (fopen_s(&dict, "dictionary", "rb"))
	{
		cout << "Dictionary let!";
		perror("Error");
	}
	else
	{
		while (!feof(dict))
		{
			fread(&word, sizeof(vocabulary), 1, dict);
			if (feof(dict))
				break;
			AddToTree_Alphabetically(Tree_Alphabetically, word);
		}
	}
	fclose(dict);
}
void print_tree(Node* Tree, int level)
//функция печатает дерево
{
	if (Tree)
	{
		print_tree(Tree->left, level + 1);
		for (int i = 0; i < level; i++)
			cout << "	";
		cout << Tree->data.eng << "	" << Tree->data.count << endl;
		print_tree(Tree->right, level + 1);
	}
}

int main()
{
	Node* Tree_Alphabetically = NULL;

	CreatTree_Alphabetically(Tree_Alphabetically);
	print_tree(Tree_Alphabetically, 0);

}

