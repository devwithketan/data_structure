#include <iostream>
#include <stdexcept> // For std::underflow_error

using namespace std;
struct Node
{
	int data;
	Node* next;
};

class Queue
{
public:
	Queue()
	{
		front_node = nullptr;
		back_node = nullptr;
		s = 0;
	}

	~Queue()
	{
		while (!empty())
		{
			pop();
		}
	}

	void push(const int& val)
	{
		Node* node = new Node(); // this needs to replace with smart pointer
		node->data = val;
		node->next = nullptr;


		if (!front_node)
		{
			front_node = node;
			back_node = node;
			s++;
			return;
		}

		back_node->next = node;
		back_node = node;
		s++;
	}

	bool empty()
	{
		if (!front_node) return true;
		return false;

	}

	void pop()
	{
		if (empty())
		{
			throw std::underflow_error("Underflow error: Attempt to pop from empty queue.");
		}
		else
		{
			Node* temp_node = front_node;
			front_node = front_node->next;
			delete temp_node;
			s--;
		}
	}

	size_t size() const
	{
		return s;
	}

	int front()
	{
		if (empty())
		{
			throw std::underflow_error("Underflow error: Attempt to get value from empty queue.");
		}
		return front_node->data;
	}

	int back()
	{
		if (empty())
		{
			throw std::underflow_error("Underflow error: Attempt to get value from empty queue.");
		}
		return front_node->data;
	}


private:
	Node* front_node;
	Node* back_node;
	size_t s;

};

int main()
{
	try {
		Queue que;

		que.push(5);
		que.push(6);
		que.push(9);
		while (!que.empty())
		{
			cout << que.front() << endl;
			que.pop();
		}
	}
	catch (const std::underflow_error& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}
