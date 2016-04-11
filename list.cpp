#include <iostream>
#include <string>
using namespace std;
class Element{
public:
	int data;
	Element *next;
	Element(int _data){
		data = _data;
	}
};
class List{
		Element *first;
		int size;
public:
	List(){
		first = nullptr;
		size = 0;
	}
	List(int _element){
		Element *temp = new Element(_element);
		temp->next = nullptr;
		first = temp;
		size = 1;
	}
	void add(int element, int index){
		if(index > size){
			cout << "Error";
			return;
		}
		size++;
		if(index == 0) {
			Element* temp = new Element(element);
			temp->next = first;
			first = temp;
			return;
		}
		Element *temp = new Element(element);
		Element *iterator = first;
		for (int i = 0; i < index-1; i++)
			iterator = iterator->next;
		if(index == size-1) temp->next = nullptr; 
		else temp->next = iterator->next;
		iterator->next = temp;
	}
	void deleteElement(int index){
		if(index > size-1){
			cout << "Error";
			return;
		}
		size--;
		if(index == 0){
			first = first->next;
			return;
		}
		Element *iterator = first;
		for (int i = 0; i < index-1; i++)
			iterator = iterator->next;
		iterator->next = iterator->next->next;
	}
	int get(int index){
		if(index > size-1){
			cout << "Error";
			return -1;
		}
		Element *iterator = first;
		for (int i = 0; i < index; i++)
			iterator = iterator->next;
		return iterator->data;
	}
};
int main(){
	List list;
	string action;
	int n, data, index;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> action >> index;
		if (action == "add"){
			cin >> data;
			list.add(data, index);
		}
		if (action == "get"){
			cout << list.get(index);
		};
		if (action == "del") {
			list.deleteElement(index);
		};
	}
	system("pause");
	return 0;
}
