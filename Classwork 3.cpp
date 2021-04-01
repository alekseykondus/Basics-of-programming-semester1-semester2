#include <iostream>

using namespace std;
struct Bus
{	
	char name[10];
	int number;
	int voute;
};
struct Node
{
	Bus bus;
	Node* next;
	Node* prev;//ссылка на предидущее значение
};
struct NodeList
{
	Node* head = nullptr;
	void add_first(Bus bus) //добавляет новый елемент в начало списка
	{
		Node* node = new Node;
		node->bus = bus;
		node->next = NULL;
		if (head == 0)
			head = node;
		else
		{
			node->next = head;
			head->prev = node;
			head = node;
		}
	}
	Bus* find(int number) 
	{
		Node* current = head;
		while (current != nullptr) 
		{
			if (number == current->bus.number) 
				return &(current->bus);
			current = current->next;
		}
		return 0;
	}
	Bus remove(int number) 
	{
		Node* current = head;
		Node* previous = head;
		while (current != nullptr) 
		{
			if (number == current->bus.number)
			{
				Bus info = current->bus;
				previous->next = current->next;
				(current->next)->prev = previous;
				delete current;
				return info;
			}
			previous = current;
			current = current->next;
		}
	}
	void print() 
	{
		Node* current = head;
		while (current != nullptr) 
		{
			cout << "Номер автобуса: " << current->bus.number << endl << "Название: " << current->bus.name << endl;
			current = current->next;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	NodeList bus_routes;
	NodeList bus_park;
	for (int i = 0; i < 3; i++) //добавим 7 автобусов
	{
		Bus bus;
		cout << "Введите название автобуса: ";
		cin >> bus.name;
		cout << "Введите номер автобуса: ";
		cin >> bus.number;
		cout << "Введите маршрут автобуса: "; // 1 - в дороге, 2 - стоит на парковке
		cin >> bus.voute;
		if (bus.voute == 1) bus_routes.add_first(bus);
		else if (bus.voute == 2) bus_park.add_first(bus);

	}
	bus_routes.remove(4); //удаляем автобус с номером 4
	bus_routes.print();
	bus_park.print();
	return 0;
}
