//ВАРИАНТ №1
//Слияние двух вершин графа (реализовано через список)
#include <iostream>
using namespace std;
#define NumberOfVertices 7//количество вершин графа

struct MatrixElement
{
	int j;
	bool data;
	MatrixElement* next = NULL;
	MatrixElement* prev = NULL;
};

struct MatrixElement_List
{
	MatrixElement* head = nullptr;
	MatrixElement* end = nullptr;

	void add(int j)
	{
		MatrixElement* e = new MatrixElement;
		e->j = j;
		e->data = true;
		if (!head)
		{
			head = e;
			end = e;
		}
		else
		{
			head->next = e;
			e->prev = head;
			head = e;
		}
	}

	void insert(int a)
	{//вставка элемента в список
		MatrixElement* item = end;
		while (item != NULL && item->j < a - 1)
			item = item->next;
		if (head->j < a-1)
			add(a-1);
		else if (item == end)
		{
			MatrixElement* e = new MatrixElement;
			e->data = true;
			e->j = a - 1;
			e->next = end;
			end->prev = e;
			//e->prev = nullptr;
			end = e;
		}
		else 
		{
			item = item->prev;
			MatrixElement* e = new MatrixElement;
			e->j = a - 1;
			e->data = true;
			e->next = item->next;
			item->next = e;
			e->prev = item;
			(item->next->next)->prev = e;
		}

	}
	void remove(MatrixElement* e)
	{//удаление элемента со списка
		MatrixElement* item = e;
		if (item->next != NULL)
		{
			if (item != end)
			{
				item = item->prev;
				item->next = item->next->next;
				(item->next)->prev = item;
			}
			else
			{
				end = item->next;
				end->prev = NULL;
			}
		}
		else 
			(e->prev)->next = nullptr;
		delete e;
	}

	void vertex_merger_vertical(int a, int b)
	{//выполняем слияние по вертикале
		MatrixElement* item1 = end;
		MatrixElement* item2 = end;

		while (item1 != NULL && item1->j != a - 1)
			item1 = item1->next;

		while (item2 != NULL && item2->j != b - 1)
			item2=item2->next;

		if (item1 == NULL && item2 != NULL)
			insert(a); //добавляем элемент в середину 

		if (item2 != NULL)
			remove(item2); //и удалить элемент item2
	}

	void decrease_j(int b)
	{//удаляем одну вертикаль
		MatrixElement* item = end;
		while (item != NULL)
		{
			if (item->j >= b-1)
				item->j--;
			item = item->next;
		}
	}
};

void vertex_merger_horizontal(MatrixElement_List& item1, MatrixElement_List& item2)
{//выполняем слияние по горизонтале
	MatrixElement* e1 = item1.end;
	MatrixElement* e2 = item2.head;

	while (e2 != NULL)
	{
		while (e1 != NULL && e1->j < e2->j)
			e1 = e1->next;
		if (e1 != NULL && e1->j != e2->j)
		{
			item1.insert(e2->j+1);
		}
		else if (item1.head->j < e2->j)
			item1.insert(e2->j+1);

		e1 = item1.end;
		e2 = e2->prev;
		if (e2 != NULL)
			item2.remove(e2->next);
	}
}

void print_matrix_list(MatrixElement_List *horizontal, int size)
{//вывод в виде матрицы
	for (int i = 0; i < size; i++)
	{
		MatrixElement* e = horizontal[i].end;

		int j_copy = -1;
		if (e == nullptr)
			for (int j = 0; j < size; j++)
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

			if (e->next == nullptr)
				for (int j = j_copy + 1; j < size; j++) cout << '0' << ' ';

			e = e->next;
		}
		cout << std::endl;
	}
	cout << std::endl;
}

void matrix_creation(MatrixElement_List*& horizontal)
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
					horizontal[i].add(j);
			}
		//print_matrix_list(horizontal);
		//std::cout << std::endl;
	}
	fclose(file);
}


int main()
{
	//создание и заполнение файла матрицей графа
	/*FILE* file;
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
	fclose(file);*/

	//пример графа с 7 вершинами
	/*bool A[NumberOfVertices][NumberOfVertices] = {0, 1, 0, 0, 1, 0, 0,
												  1, 0, 1, 1, 1, 0, 0,
												  0, 1, 0, 0, 0, 0, 1,
												  0, 1, 0, 0, 1, 1, 1,
											      1, 1, 0, 1, 0, 1, 0,
												  0, 0, 0, 1, 1, 0, 1,
												  0, 0, 1, 1, 0, 1, 0};
		for (int i = 0; i < NumberOfVertices; i++)
			for (int j = 0; j < NumberOfVertices; j++)
			{
				if (A[i][j] != 0)
					horizontal[i].add(j);
			}
	*/



	MatrixElement_List* horizontal = new MatrixElement_List [NumberOfVertices];
	matrix_creation(horizontal); //считывание матрицы в виде списка с файла
	print_matrix_list(horizontal, NumberOfVertices);

	int a, b;
	cout <<endl << "Vertex numbers to merger: " << endl
		<< "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	if (a > b) 
		swap(a, b);

	cout << endl << "Vertices " << a << ',' << b << " were merged into vertex " << a << endl;

	vertex_merger_horizontal(horizontal[a - 1], horizontal[b - 1]);

	for (int i = 0; i < NumberOfVertices; i++)
		horizontal[i].vertex_merger_vertical(a, b);
	for (int i = 0; i < NumberOfVertices; i++)
		horizontal[i].decrease_j(b);

	MatrixElement_List horizontal_VU[NumberOfVertices - 1];

	for (int i = 0; i < b - 1; i++)
		horizontal_VU[i] = horizontal[i];
	for (int i = b; i < NumberOfVertices; i++)
		horizontal_VU[i - 1] = horizontal[i];

	delete[] horizontal;

	print_matrix_list(horizontal_VU, NumberOfVertices - 1);

}
