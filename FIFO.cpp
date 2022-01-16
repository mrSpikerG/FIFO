#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node* next;
	Node()
	{
		next = nullptr;
	}
};

template <typename T>
class List {
private:
	Node<T>* head;
	unsigned long long size;
public:

	List()
	{
		this->head = nullptr;
		size = 0;
	}

	void add(int num) {

		if (head == nullptr) {
			this->head = new Node<T>;
			this->head->value = num;
		}
		else {
			Node<T>* tmp = this->head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node<T>;
			tmp->next->next = nullptr;
			tmp->next->value = num;
		}
		this->size++;
	}


	void show() {
		if (size != 0) {
			Node<T>* tmp = this->head;

			while (tmp != nullptr) {
				cout << "this: " << tmp << "\tnext: " << tmp->next << "\tvalue: " << tmp->value << "\n";
				tmp = tmp->next;
			}
		}
		else {
			cout << "\n\nNULL\n\n";
		}
	}

	void remove() {
		if(this->head!=nullptr){
			Node<T>* tmp = this->head;
			this->head = this->head->next;
			this->size--;
		}
	}

};
int main()
{
	List<int> MyTestList;

	MyTestList.add(1);
	MyTestList.add(2);
	MyTestList.add(3);
	MyTestList.add(4);
	MyTestList.add(5);
	MyTestList.add(1);


	MyTestList.remove();
	MyTestList.remove();
	MyTestList.remove();

	MyTestList.show();

}