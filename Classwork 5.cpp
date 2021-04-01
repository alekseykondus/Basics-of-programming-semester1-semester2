#include <iostream>
#include <exception>

//template <typename T>
struct MyStack
{
	int Data;
	MyStack* next = nullptr;
};
struct queue
{
	int data;
	queue* next = nullptr;
	queue* prev = nullptr;
};

struct MyStack_List
{
	MyStack* top = nullptr;
	void push(int D) // добавление элементов
	{
		MyStack* q = new MyStack;
		q->Data = D;
		if (top == nullptr)
			top = q;
		else
		{
			q->next = top;
			top = q;
		}
	}
	int pop()//удаляет последний элемент стека
	{
		int dat = top->Data;
		top = top->next;
		return dat;
	}
	void peek()// вывод всех элементов на экран
	{
		MyStack* q = new MyStack;
		q = top;
		while (q != NULL)
		{
			std::cout << q->Data << '	';
			q = q->next;
		}
		std::cout << std::endl;
	}
	//int arr[10];
	//int top = -1;
	//void peek();
};
struct queue_list
{
	queue* head = nullptr;
	queue* end = nullptr;
	void add(int data)
	{
		if (end == nullptr)
		{
			queue* item = new queue;
			item->data = data;
			head = item;
			end = item;
		}
		else 
		{
			queue* item = new queue;
			item->data = data;
			item->prev = end;
			end->next = item;
			end = item;
		}
	}
	void delet(queue* node)
	{
		if (node->next != nullptr)
			std :: cout << "Removing from the end!";
		else
		{
			node->prev->next = nullptr;
			delete node;
		}
	}
	void print()
	{
		queue* item = head;
		while (item)
		{
			std :: cout << item->data << '	';
			item = item->next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	MyStack_List* top = new MyStack_List; //черга
	MyStack_List* top_2 = new MyStack_List;
	MyStack_List* top_3 = new MyStack_List;
	queue_list* q1 = new queue_list; //стек
	queue_list* q2 = new queue_list;

	top->push(1);
	top->push(4);
	top->push(6);
	top->push(2);
	top->push(8);
	top->push(12);
	top->push(3);
	top->push(9);
	top->push(7);
	top->push(0);
	top->peek();
	std :: cout << std :: endl;
	for (int i = 0; i < 10; i++)
	{
		int pop_copy = top->pop();
		if (pop_copy < 5)
		{
			top_2->push(pop_copy);
			q1->add(pop_copy);
		}
		else
		{
			top_3->push(pop_copy);
			q2->add(pop_copy);
		}
	}

	top_2->peek();
	top_3->peek();
	std::cout << std::endl;
	q1->print();
	q2->print();
}
