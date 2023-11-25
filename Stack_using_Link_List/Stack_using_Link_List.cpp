#include<iostream>
using namespace std;
#define MAX 5
int stack[MAX];

struct node
{
	int info;
	node* link;
};
node* top = 0;

void push(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->link = NULL;
	if (top == NULL)
		top = p;
	else
	{
		p->link = top;
		top = p;
	}
}

int pop()
{
	int x;
	node* p;
	if (top == NULL)
	{
		cout << "Stack is empty.......! " << endl;
		return -1;
	}
	p = top;
	x = top->info;
	top = top->link;
	delete p;
	return x;
}

int peek()
{
	int x;
	node* p;
	if (top == NULL)
	{
		cout << "Stack is empty.......! " << endl;
		return -1;
	}
	x = top->info;
	return x;
}

void display()
{
	node* t;
	if (top == NULL)
	{
		cout << "Stack is empty........!" << endl;
		return;
	}
	else
	{
		cout << "All the Elem in Stack is : " << endl;
		t = top;
		while (t != NULL)
		{
			cout << " " << t->info;
			t = t->link;
			cout << endl;
		}
		return;
	}
}

int main()
{
	int ch, v;
	do
	{  
		cout << "1.Push \n2.Pop \n3.Peek \n4.Display  \n5.exit" << endl; 
		cout << "Enter the choice : ";   cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter the values to push : " << endl;
			cin >> v;     push(v);     break;
		case 2:v = pop();
			cout << "The value is poped : " << v << endl;  break;
		case 3:v = peek();
			cout << "The value is poped : " << v << endl;  break;
		case 4:display();   break;
		default:cout << "Exiting..........! ";
			ch = 5;
		}
	} while (ch != 5);
}