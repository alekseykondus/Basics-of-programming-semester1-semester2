#include <iostream>
using namespace std;


struct Node
{
	bool data = 0;
	char polynom[10] = { 0 };
	Node* next = NULL;
	Node* prev = NULL;
};
struct NodeList
{
	Node* head = nullptr;
	Node* end = nullptr;
	void add(int a) //добавляет новый елемент в начало списка
	{
		Node* node = new Node;
		node->data = a;
		if (head == 0)
		{
			head = node;
			end = node;
		}
		else
		{
			node->next = head;
			head->prev = node;
			head = node;
		}
	}
	void add(char *str, int k, int p) //добавляет новый елемент в начало списка
	{
		Node* node = new Node;
		int l = 0;
		if (k + 1 >= p) cout << "Error" << endl;
		for (int i = k + 1; i <= p; i++) // добавил '+'
		{
			//if (str[i] == '0') break;
			if (l == 10)
				cout << "Полином не влез в node->polynom" << endl;
			node->polynom[l] = str[i];
			l++;
		}
		if (head == 0)
		{
			head = node;
			end = node;
		}
		else
		{
			node->next = head;
			head->prev = node;
			head = node;
		}
	}
	int count(NodeList polynomial, int size) //считает значение функции на даном наборе
	{
		Node* current = head;
		Node* cur1 = polynomial.end;
		int j = 0;
		int j_copy = 1;
		for (int k = 0; k < size; k++) 
		{
			for (int i = 0; i < 10; i++)
			{
				switch (cur1->polynom[i])
				{
				case '0': 	j += 1; break;
				case '1': j += 0; break;
				case 'x': 	j_copy *= current->data; break;
				case 'y':
					for (int k = 0; k < 1; k++)
						current = current->next;
					j_copy *= current->data;
					current = head;
					break;
				case 'z':
					for (int k = 0; k < 2; k++)
						current = current->next;
					j_copy *= current->data;
					current = head;
					break;
				case 't':
					for (int k = 0; k < 3; k++)
						current = current->next;
					j_copy *= current->data;
					current = head;
					break;
				case 'k':
					for (int k = 0; k < 4; k++)
						current = current->next;
					j_copy *= current->data;
					current = head;
					break;
				case 'l':
					for (int k = 0; k < 5; k++)
						current = current->next;
					j_copy *= current->data;
					current = head;
					break;
				case 'm':
					for (int k = 0; k < 6; k++)
						current = current->next;
					j_copy *= current->data;
					current = head;
					break;
				case 'n':
					for (int k = 0; k < 7; k++)
						current = current->next;
					j_copy *= current->data;
					current = head;
					break;
				//case '0'-0: j += 0; break;
				default: break;
				}
				if (cur1->polynom[i] == '+' || !cur1->polynom[i])
				{
					j += j_copy;
					j_copy = 1;
					break;
				}
			}
			cur1 = cur1->prev;
		}
		return j % 2;
	}
	/*int count(char *str, int n) //считает значение функции на даном наборе
	{
		Node* current = head;
		int j = 0;
		int j_copy = 1;
		for (int i = 0; i < 100; i++)
		{
			switch (str[i])
			{
			case 'x': 	j_copy *= current->data; break;
			case 'y': 
				for (int k = 0; k < 1; k++)
					current = current->next;
				j_copy *= current->data; 
				current = head;
				break;
			case 'z':
				for (int k = 0; k < 2; k++)
					current = current->next;
				j_copy *= current->data;
				current = head;
				break;
			case 't':
				for (int k = 0; k < 3; k++)
					current = current->next;
				j_copy *= current->data;
				current = head;
				break;
			case 'k':
				for (int k = 0; k < 4; k++)
					current = current->next;
				j_copy *= current->data;
				current = head;
				break;
			case 'l':
				for (int k = 0; k < 5; k++)
					current = current->next;
				j_copy *= current->data;
				current = head;
				break;
			case 'm':
				for (int k = 0; k < 6; k++)
					current = current->next;
				j_copy *= current->data;
				current = head;
				break;
			case 'n':
				for (int k = 0; k < 7; k++)
					current = current->next;
				j_copy *= current->data;
				current = head;
				break;
			}
			if (str[i] == '+' || !str[i])
			{
				j += j_copy;
				j_copy = 1;
			}
		}
		return j%2;
	}*/
	void print()
	{
		Node* current = end;
		while (current != nullptr)
		{
			cout << current->data << ' ';
			current = current->prev;
		}
	}
	void print_tabl(int n) // выводит таблицей размером (pow(2,n) на n)
	{
		int j = 0;
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << ' ';
			j++;
			if (j % n == 0) cout << endl;
			current = current->next;
		}
	}
	void print_polynomial()
	{
		Node* current = end;
		while (current != nullptr)
		{
			cout << current->polynom;
			current = current->prev;
		}
		cout << endl;
	}
};

NodeList *value_of_variable_binary_conversion(NodeList *X, int n)
{
	for (int i = 0; i < pow(2, n); i++)
	{
		int b = 0;
		int j = n - 1;
		int i_copy = i;
		int z = 0;
		while (z!=n)
		{
			b = i_copy % 2;
			i_copy /= 2;
			switch (b)
			{
			case 0: X[i].add(0); break;
			case 1: X[i].add(1); break;
			}
			j--;
			z++;
		}
	}
	return X;
}


int main()
{
	setlocale(LC_ALL, " ");
	cout << "Enter the number of variables: ";
	int n;
	cin >> n;
	NodeList* X = new NodeList[pow(2, n)];
	NodeList F ;
	const char ch[] = { 'x', 'y', 'z', 't', 'k', 'l', 'm', 'n' };
	for (int i = 0; i < n; i++)
		cout << ch[i] << ' ';
	cout << endl;

	X = value_of_variable_binary_conversion(X, n);
	for (int i = 0; i < pow(2, n); i++)
		X[i].print_tabl(n);

	char str[100];
	cout << endl << "Enter the Zhegalkin polynomial: " << endl;
	cin.ignore(32767, '\n');
	cin.getline(str, 100, '\n');
	int j = 1;
	for (int i = 0; i < size(str); i++)
		if (str[i] == '+')
			j++;
	int j_copy = j;
	int* k = new int[j+1];
	k[0] = -1;
	j = 1;
	for (int i = 0; i < size(str); i++)
		if (str[i] == '+' || !str[i])
		{
			k[j] = i;
			k[j + 1] = i + 4;
			j++;
		}
	NodeList polynomial;
	for (int i = 0; i < j; i++)
		polynomial.add(str, k[i], k[i + 1]);
	//polynomial.print_polynomial ();

	
	//сделать проверку на правильность ввода
	cout << "f = (";
	for (int i = 0; i < pow(2, n); i++)
		F.add( X[i].count(polynomial, j_copy));
	F.print();
	cout << ')';
}
