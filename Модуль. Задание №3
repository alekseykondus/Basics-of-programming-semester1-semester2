#include <iostream>

enum procedure
{
	AND, OR, NON, NUM, NOT, VAL, RGT, LFT
};

struct Tree 
{
	procedure operation = NON;
	int number = 0;
	char ch;
	Tree* up = nullptr;
	Tree* left = nullptr;
	Tree* right = nullptr;

	const char* msg_for_val = "Enter variable: ";

	Tree(Tree* parent)
	{
		up = parent;
	}

	float result() 
	{
		if (operation == NUM) return number;
		else if (operation == VAL) 
		{
			std :: cout << msg_for_val << ch << std :: endl;

			std :: cin >> number;
			return number;
		}
		else if (operation == AND) 
		{
			int t = left->result() + right->result();
			t %= 2;
			return t;
		}
		else if (operation == OR) 
		{
			if (left->result() == 1 || right->result() == 1) return 1;
			return 0;
		}
		else if (operation == NOT) 
		{
			if (right->result() == 1) return 0;
			return 1;
		}
		else 
		{
			float res = 0;
			if (left != nullptr) res += left->result();
			if (right != nullptr) res += right->result();
			return res;
		}
	}
};

struct syntax_tree 
{
	Tree* head = new Tree(nullptr);

	void put(procedure operation)
	{
		if (operation == LFT) left_bracket();
		else if (operation == RGT) right_bracket();
		else if (head->operation == NON) 
		{

			if (head->left == nullptr) 
			{
				head->left = new Tree(head);
				head->left->operation = NUM;
			}

			head->operation = operation;
			head->right = new Tree(head);
			head = head->right;
		}
		else 
		{
			if (head->up == nullptr) 
			{
				head->up = new Tree(nullptr);
				head->up->left = head;
				head = head->up;
			}
			else 
			{
				if (head->up->left == head) 
				{
					head->up = new Tree(head->up);
					head->up->left = head;
					head->up->up->left = head->up;
					head = head->up;
				}
				else 
				{
					head->up = new Tree(head->up);
					head->up->left = head;
					head->up->up->right = head->up;
					head = head->up;
				}
			}
		}
		head->operation = operation;
		head->right = new Tree(head);
		head = head->right;
	}

	void put(int num) 
	{
		number(num);
	}

	void put(char ch) 
	{
		val(ch);
	}

	float result() 
	{
		while (head->up != nullptr) head = head->up;
		return head->result();
	}

private:
	void left_bracket() 
	{
		head->left = new Tree(head);
		head = head->left;
	}

	void right_bracket() 
	{
		if (head->up != nullptr) head = head->up;
	}

	void number(int number)
	{
		head->operation = NUM;
		head->number = number;
		head = head->up;
	}

	void val(char ch) 
	{
		head->operation = VAL;
		head->ch = ch;
		head = head->up;
	}
};

class syntactical_analyzer
{
	syntax_tree tree;
public:
	void analyzer(char arr[])
	{
		int i = 0;

		tree.put(LFT);
		tree.put(LFT);

		while (arr[i] != '\0') {
			if (arr[i] == ' ') {}
			else if (arr[i] == '&') tree.put(AND);
			else if (arr[i] == '|') tree.put(OR);
			else if (arr[i] == '-') tree.put(NOT);
			else if (arr[i] == '(') tree.put(LFT);
			else if (arr[i] == ')') tree.put(RGT);
			else if (arr[i] == 48) tree.put(0);
			else if (arr[i] == 49) tree.put(1);
			else 
				tree.put(arr[i]);
			i++;
		}
		tree.put(RGT);
	}

	float result() 
	{
		return tree.result();
	}
};


int main() 
{
	char expression[20] = "(1&x)|0"; //  пример выражения для одной переменной до 20-ти символов

	syntactical_analyzer p;
	p.analyzer(expression);

	if (p.result() == 0)
		std :: cout << "Result: " << true;
	else
		std :: cout << "Result: " << false;
}
