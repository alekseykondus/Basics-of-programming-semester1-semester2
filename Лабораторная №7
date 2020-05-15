//ВАРИАНТ №1
#include <iostream>
#define NumberOfVertices 15//количество вершин графа
using namespace std;

struct MatrixElement
{
	int i, j;
	bool data;
	MatrixElement* next = nullptr;
	MatrixElement* prev = nullptr;
};
struct int_edges
{
	int Vertex_number;
	int edges = 0;
};

struct MatrixElement_List
{
	MatrixElement* head = nullptr;
	MatrixElement* end = nullptr;
	MatrixElement* item = nullptr;

	void add(int i, int j, bool data)
	{
		MatrixElement* e = new MatrixElement;
		e->i = i;
		e->j = j;
		e->data = data;
		if (!head)
		{
			head = e;
			end = e;
		}
		else
		{
			e->next = head;
			head->prev = e;
			head = e;
		}
	}

	void number_of_edges(int &count)
	{
		item = head;
		while (item != NULL)
		{
			if (item->data)
				count++;
			item = item->next;
		}
	}
};

void print_matrix_list(MatrixElement_List horizontal[NumberOfVertices])
{//вывод в виде матрицы
	for (int i = 0; i < NumberOfVertices; i++)
	{
		MatrixElement* e = horizontal[i].end;

		int j_copy = -1;
		if (e == nullptr)
			for (int j = 0; j < NumberOfVertices; j++)
				cout << '0' << ' ';
		while (e != nullptr)
		{
			if (j_copy == -1 && e->j != 0)
				for (int j = 0; j < e->j; j++)
					cout << '0' << ' ';
			else
				for (int j = j_copy + 1; j < e->j; j++)
					cout << '0' << ' ';
			cout << e->data << ' ';
			j_copy = e->j;

			if (e->prev == nullptr)
				for (int j = j_copy + 1; j < NumberOfVertices; j++) cout << '0' << ' ';

			e = e->prev;
		}
		cout << std::endl;
	}
	cout << std::endl;
}

void print_list(MatrixElement_List list[NumberOfVertices])
{//вывод в виде списка
	for (int i = 0; i < NumberOfVertices; i++)
	{
		MatrixElement* e = list[i].end;
		while (e != nullptr)
		{
			cout << e->data << ' ';
			e = e->prev;
		}
	}
}

void matrix_creation(MatrixElement_List(&horizontal)[NumberOfVertices])
{//заполнение матрицы графа  из файла
	FILE* file;
	int A;

	if (fopen_s(&file, "graph", "rb"))
		perror("Error");
	else
	{
		for (int i = 0; i < NumberOfVertices; i++)
			for (int j = 0; j < NumberOfVertices; j++)
			{
				fread(&A, sizeof(int), 1, file);
				if (A != 0)
				{
					horizontal[i].add(i, j, A);
				}
			}
		//print_matrix_list(horizontal);
		std::cout << std::endl;
	}
	fclose(file);
}

void print_mas(int_edges x[NumberOfVertices], int sort_order)
{
	if (sort_order == 1)
		for (int i = 0; i < NumberOfVertices; i++)
			cout << x[i].Vertex_number + 1 << ' ';
	else if (sort_order == 2)
		for (int i = NumberOfVertices - 1; i >= 0; i--)
			cout << x[i].Vertex_number + 1 << ' ';
	cout << endl;
}

void insertion_sort(int_edges (&x)[NumberOfVertices]) //сортировка вставкой 
{
	for (int i = 1; i < size(x); i++)
		for (int j = i; j > 0 && x[j - 1].edges > x[j].edges; j--) // пока j>0 и элемент j-1 > j, x-массив int
			swap(x[j - 1], x[j]);        // меняем местами элементы j и j-1
	
}

void bubble_sort(int_edges (&x)[NumberOfVertices]) //сортировка пузырьком 
{
	for (int i = 0; i < NumberOfVertices; i++)
		for (int j = NumberOfVertices - 1; j > 0; j--)
			if (x[j - 1].edges > x[j].edges)
				swap(x[j - 1], x[j]);
}

void shaker_sort(int_edges (&x)[NumberOfVertices])
{
	int left = 0;
	int right = size(x) - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++) {
			if (x[i].edges > x[i + 1].edges)
				swap(x[i], x[i+1]);
		}
		right--;
		for (int i = right; i > left; i--) {
			if (x[i].edges < x[i - 1].edges)
				swap(x[i-1], x[i]);
		}
		left++;
	}
}

void quick_sort(int_edges(&x)[NumberOfVertices], int first, int last)
{
	int f = first, l = last;
	unsigned int mid = x[(f + l) / 2].edges; //находим середину массива

	while (f <= l)
	{
		while (x[f].edges < mid) //находим элемент, который больше центрального
			f++;
		while (x[l].edges > mid) //находим элемент, который меньше центрального
			l--;

		if (f <= l) 
		{
			swap(x[f], x[l]); //меняем местами
			f++;
			l--;
		}
	}
	if (first < l) 
		quick_sort(x, first, l); //рекурсивно вызываем левую часть
	if (f < last) 
		quick_sort(x, f, last); //рекурсивно вызываем правую часть
}

void merge(int_edges merged[], int lenD, int_edges L[], int lenL, int_edges R[], int lenR)
{
	int i = 0;
	int j = 0;
	while (i < lenL || j < lenR) {
		if (i < lenL & j < lenR) {
			if (L[i].edges <= R[j].edges) {
				merged[i + j] = L[i];
				i++;
			}
			else {
				merged[i + j] = R[j];
				j++;
			}
		}
		else if (i < lenL) {
			merged[i + j] = L[i];
			i++;
		}
		else if (j < lenR) {
			merged[i + j] = R[j];
			j++;
		}
	}
}
void merge_sort(int_edges x[NumberOfVertices], int size)
{
	if (size > 1) {
		int middle = size / 2;
		int rem = size - middle;
		int_edges* L = new int_edges[middle];
		int_edges* R = new int_edges[rem];
		for (int i = 0; i < size; i++) {
			if (i < middle)
				L[i] = x[i];
			else
				R[i - middle] = x[i];
		}
		merge_sort(L, middle);
		merge_sort(R, rem);
		merge(x, size, L, middle, R, rem);
	}
}

/* merge_sort(int_edges(&x)[NumberOfVertices])
{
	int rght, rend;
	int i, j, m;
	int_edges b[NumberOfVertices];
	for (int k = 1; k < size(x); k *= 2)
	{
		for (int left = 0; left + k < size(x); left += k * 2)
		{
			rght = left + k;
			rend = rght + k;
			if (rend > size(x)) rend = size(x);
			m = left; i = left; j = rght;
			while (i < rght && j < rend)
			{
				if (x[i].edges <= x[j].edges)
				{
					b[m] = x[i]; i++;
				}
				else
				{
					b[m] = x[j]; j++;
				}
				m++;
			}
			while (i < rght)
			{
				b[m] = x[i];
				i++; m++;
			}
			while (j < rend)
			{
				b[m] = x[j];
				j++; m++;
			}
			for (m = left; m < rend; m++)
			{
				x[m] = b[m];
			}
		}
	}
}*/

void Shell_sort(int_edges(&x)[NumberOfVertices])
{
	int d = size(x) / 2;
	while (d > 0)
	{
		for (int i = 0; i < size(x) - d; i++)
		{
			int j = i;
			while (j >= 0 && x[j].edges > x[j + d].edges)
			{
				swap(x[j], x[j+d]);
				j--;
			}
		}
		d = d / 2;
	}
}

int main()
{
	//создание и заполнение файла матрицей графа
	FILE* file;
	if (fopen_s(&file, "graph", "wb"))
		perror("Error");
	else
	{
		for (int i = 0; i < pow(NumberOfVertices, 2); i++)
		{
			int a = rand() % 2;
			fwrite(&a, sizeof(int), 1, file);
		}
	}
	fclose(file);
	bool k = 1;
	while (k)
	{
		MatrixElement_List horizontal[NumberOfVertices];
		matrix_creation(horizontal);

		int_edges x[NumberOfVertices];
		for (int i = 0; i < NumberOfVertices; i++)
		{
			x[i].Vertex_number = i;
			horizontal[i].number_of_edges(x[i].edges);
			//cout << x[i].Vertex_number+1 << '	' << x[i].edges << endl;
		}

		//свели задачу до сортировки одного масива - x


		int sorting_method, sort_order;
		cout << "Method to sort?" << endl
			<< "1 - insertion sort" << endl //Вставками
			<< "2 - bubble sort" << endl //Бульбашкою
			<< "3 - shaker sort" << endl //Перемішуванням
			<< "4 - quick sort " << endl //Швидке
			<< "5 - merge sort" << endl //Злиттям
			<< "6 - Shell sort" << endl //Шелла
			<< "______________" << endl;
		cin >> sorting_method;


		cout << "Order to sort?" << endl;
		cout << "1 - from low to high" << endl
			<< "2 - from high to low" << endl
			<< "____________________" << endl;
		cin >> sort_order;
		cout << endl;

		switch (sorting_method)
		{
		case 1:
			insertion_sort(x);
			break;
		case 2:
			bubble_sort(x);
			break;
		case 3:
			shaker_sort(x);
			break;
		case 4:
			quick_sort(x, 0, size(x)-1);
			break;
		case 5:
			merge_sort(x, size(x));
			break;
		case 6:
			Shell_sort(x);
			break;
		default:
			cout << "Function number entered incorrectly!";
			break;
		}
		print_mas(x, sort_order);

		cout << endl << "Would you like to continue work?" << endl;
		cout << "1 - YES" << endl << "0 - NO" << endl << "______" << endl;
		cin >> k;
		if (k == 0)
			break;
	}
}

