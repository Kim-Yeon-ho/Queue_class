#include <iostream>
#include<string>
#define MQS 100
using namespace std;

class C_Queue {
protected:
	string data[MQS];
	int Qfront , Qrear;
	
public:
	C_Queue() { Qfront = Qrear = 0; } 

	string enqueue(string str) {
		Qrear = (Qrear + 1 ) % MQS;
		return data[Qrear] = str;
	}
	string dequeue() {
		if (Qfront == Qrear) return "empty";
		else {
			Qfront = (Qfront + 1) % MQS;
			return data[Qfront];
		}
	}
	
};

class C_Deque : C_Queue {
public:
	C_Deque() {};
	void add(string pos, string str) {
		if (pos == "front") {
			data[Qfront] = str;
			Qfront = (Qfront - 1 + MQS) % MQS;
		}
		else if (pos == "rear") {
			enqueue(str);
		}
	}

	void Delete (string pos) {
		if (Qfront == Qrear) { cout << "empty\n"; }
		else if (pos == "front") { 
			cout << dequeue() << endl; }
		else if (pos == "rear") { 
			Qrear = (Qrear -1 + MQS) % MQS;
			cout << data[Qrear+1] << endl;
		}
	}

	void size() {
		cout << (Qrear - Qfront + MQS) % MQS << endl;;
	}

	void empty() {
		if (Qfront == Qrear) cout << "empty" << endl;
		else cout << "not empty" << endl;
	}

	void front() {
		if (Qfront == Qrear) cout << "empty" << endl;
		else {
			cout << data[(Qfront + 1) % MQS] << endl;
		}
	}
	void rear() {
		if (Qfront == Qrear) cout << "empty" << endl;
		else{
			cout << data[(Qrear) % MQS] << endl;
		}
			
	}
};

int main() {
	int input;
	C_Deque d;
	string order;string pos;
	string addor;string delor;
	cin >> input;
	cin.ignore();
	for (int i = 0; i < input; i++) {
		getline(cin, order);
		addor = order.substr(0, 3);
		delor = order.substr(0, 6);
		if (addor == "add") {
			string element;
			if (order.substr(9, 1) != " ") { //rear계산
				pos = order.substr(4, 4);
				element = element = order.substr(9, order.size());
			}
			else {//front 계산
				pos = order.substr(4, 5);
				element = order.substr(10, order.size());
			}
			d.add(pos, element);
		}
		else if (delor == "delete") {
			pos = order.substr(7, order.size());
			d.Delete(pos);
		}
		else if (order == "size") {d.size();}
		else if (order == "empty") {d.empty();}
		else if (order == "front") { d.front();}
		else if (order == "rear") { d.rear(); }
	}
	return 0;
}