#include <iostream>
#include <string>
using namespace std;
/**
	\class Stack
*/
class Stack{
	int *elements;
	int length;
public:
	Stack(){
		length = 0;
		elements = NULL;
	}
	Stack(int _length, int *_elements){
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
	int deleleElement(){
		if (length == 0) throw "error";
		int element = elements[length-1];
		length--;
		int *temp = new int[length];
		for (int i = 0; i < length; i++)
			temp[i] = elements[i];
		elements = temp;
		return element;

	}
	/// \fn get element
	int get(){
		if (length == 0) throw "error";
		return elements[length-1];
	}
	~Stack(){
		delete[] elements;
	}
};

int main(){
	Stack stack;
	string action;
	int n, data;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> action;
		if (action == "add"){
			cin >> data;
			stack.add(data);
		}
		if (action == "get") cout << stack.get();
		if (action == "del") stack.deleteElement();
	}
	system("pause");
	return 0;
}
