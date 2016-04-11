
#include <iostream>
#include <string>
using namespace std;
/**
	\class Queue
*/
class Queue{
	int *elements;
	int length;
public:
	Queue(){
		length = 0;
		elements = NULL;
	}
	Queue(int _length, int *_elements){
		length = _length;
		elements = _elements;
	}
	/// \fn add element
	void add(int element){
		length++;
		int *temp = new int[length];
		for (int i = 0; i < length-1; i++)
			temp[i] = elements[i];
		temp[length - 1] = element;
		elements = new int[length];
		elements = temp;
	}
	/// \fn delete element
	int deleteElement(){
		if (length == 0) throw "error";
		int element = elements[0];
		length--;
		int *temp = new int[length];
		for (int i = 0; i < length; i++)
			temp[i] = elements[i+1];
		elements = temp;
		return element;

	}
	/// \fn get element
	int get(){
		if (length == 0) throw "error";
		return elements[0];
	}
	~Queue(){
		delete[] elements;
	}
};
int main(){
	Queue queue;
	string action;
	int n, data;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> action;
		if (action == "add"){
			cin >> data;
			queue.add(data);
		}
		if (action == "get") cout << queue.get();
		if (action == "del") queue.deleteElement();
	}
	system("pause");
	return 0;
}
