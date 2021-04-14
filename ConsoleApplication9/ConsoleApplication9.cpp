// ConsoleApplication9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//3. Разработать набор классов(минимум 5 классов) по теме сотрудники ИТорганизации.
//Использовать smart - указатели для создания программы учета сведений о
//сотрудниках и расчета для них заработной платы.Разработанный набор классов должен
//иметь параметры типа.Все классы должны иметь методы получения и изменения своих
//полей.Реализовать механизм транзакций, который позволит откатывать изменения,
//внесенные в сведения о сотрудниках ИТ - организации.Предусмотреть возможность
//автоматического «отката» к предыдущему состоянию данных о сотруднике, если
//текущее состояние является неудовлетворительным.Смоделировать данную ситуацию.

#if DEBUG
Console.WriteLine("Press enter to close...");
Console.ReadLine();
#endif

#include <iostream>
#include "stdio.h"
#include "windows.h"
#include "time.h"
#include<iomanip> 
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

template <typename T1> struct StatusTest {

	T1* ptr;
	int counter;
};
template <class T1>
class SmartPointerTest {
	StatusTest<T1>* smartPtr;
	T1 salary;
	string name;

public:
	SmartPointerTest(T1* ptr = 0) {
		if (!ptr) smartPtr = NULL;
		else {
			smartPtr = new StatusTest<T1>;
			smartPtr->ptr = ptr;
			smartPtr->counter = 1;

		}
	}
	SmartPointerTest(const SmartPointerTest& obj) : smartPtr(obj.smartPtr) {
		if (smartPtr) smartPtr->counter++;
	}

	~SmartPointerTest() {
		if (smartPtr) {
			smartPtr->counter--;
			if (smartPtr->counter <= 0) {
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
	}
	SmartPointerTest& operator=(const SmartPointerTest&);

	T1* operator->() const;
	void showCounter() { cout << smartPtr->counter; }

	void setSalary(int salary) { this->salary = salary; } // инициализация объекта

	T1 getSalary() { return salary; } // возвращается значение объекта 


	void setName(string name) {
		this->name = name;
	}
	T1 showData() {
		cout << "Сотрудник работает в Test." << endl;
		cout << "Имя сотрудника:" << this->name << endl;
		cout << "Зарплата сотрудника: " << this->salary << endl;
		return NULL;
	}

};

template <class T1>
T1* SmartPointerTest<T1>::operator->() const {
	if (smartPtr) return smartPtr->ptr;
	else return NULL;
}
template <class T1>
SmartPointerTest<T1>& SmartPointerTest<T1>::operator=(const SmartPointerTest& obj) {
	if (smartPtr) {
		smartPtr->counter--;
		if (smartPtr->counter <= 0) {
			delete smartPtr->ptr;
			delete smartPtr;
		}
	}
	smartPtr = obj.smartPtr;
	if (smartPtr) smartPtr->counter++;
	return *this;
}
///////////////////////////////////////////////////////////////
template <typename T2> struct StatusDev {

	T2* ptr;
	int counter;
};
template <class T2>
class SmartPointerDev {
	StatusDev<T2>* smartPtr;
	T2 salary;
	string name;

public:
	SmartPointerDev(T2* ptr = 0) {
		if (!ptr) smartPtr = NULL;
		else {
			smartPtr = new StatusDev<T2>;
			smartPtr->ptr = ptr;
			smartPtr->counter = 1;

		}
	}
	SmartPointerDev(const SmartPointerDev& obj) : smartPtr(obj.smartPtr) {
		if (smartPtr) smartPtr->counter++;
	}

	~SmartPointerDev() {
		if (smartPtr) {
			smartPtr->counter--;
			if (smartPtr->counter <= 0) {
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
	}
	SmartPointerDev& operator=(const SmartPointerDev&);

	T2* operator->() const;
	void showCounter() { cout << smartPtr->counter; }

	void setSalary(int salary) { this->salary = salary; } // инициализация объекта

	T2 getSalary() { return salary; } // возвращается значение объекта 


	void setName(string name) {
		this->name = name;
	}
	T2 showData() {
		cout << "Сотрудник работает в Dev." << endl;
		cout << "Имя сотрудника:" << this->name << endl;
		cout << "Зарплата сотрудника: " << this->salary << endl;
		return NULL;
	}

};

template <class T2>
T2* SmartPointerDev<T2>::operator->() const {
	if (smartPtr) return smartPtr->ptr;
	else return NULL;
}
template <class T2>
SmartPointerDev<T2>& SmartPointerDev<T2>::operator=(const SmartPointerDev& obj) {
	if (smartPtr) {
		smartPtr->counter--;
		if (smartPtr->counter <= 0) {
			delete smartPtr->ptr;
			delete smartPtr;
		}
	}
	smartPtr = obj.smartPtr;
	if (smartPtr) smartPtr->counter++;
	return *this;
}


//////////////////////////////////////////////////////////////////////////////
template <typename T> struct Status {

	T* ptr;
	int counter;
};
template <class T>
class SmartPointer {
	Status<T>* smartPtr;
	T salary;
	string name;
	
public:
	SmartPointer(T* ptr = 0) {
		if (!ptr) smartPtr = NULL;
		else {
			smartPtr = new Status<T>;
			smartPtr->ptr = ptr;
			smartPtr->counter = 1;
			
		}
	}
	SmartPointer(const SmartPointer& obj): smartPtr (obj.smartPtr) {
			if (smartPtr) smartPtr->counter++;
		}
	
	~SmartPointer() {
		if (smartPtr) {
			smartPtr->counter--;
			if (smartPtr->counter <= 0) {
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
	}
	SmartPointer& operator=(const SmartPointer&); 
	
		T * operator->() const; 
	void showCounter() { 
		cout << smartPtr->counter;
		
	}

	void setSalary(int salary) { this->salary = salary; } // инициализация объекта

	T getSalary() { return salary; } // возвращается значение объекта 

	
	void setName(string name) {
		this->name = name;
	}
	T showData() {
		cout << "Сотрудник работает в HR." << endl;
		cout << "Имя сотрудника:" << this -> name << endl;
		cout << "Зарплата сотрудника: " << this -> salary << endl;
		return NULL;
	}

};

template <class T>
T* SmartPointer<T>::operator->() const {
	if (smartPtr) return smartPtr->ptr;
	else return NULL;
}
template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& obj) {
	if (smartPtr) {
		smartPtr->counter--; 
			if (smartPtr->counter <= 0) { 
				delete smartPtr->ptr;
				delete smartPtr;
			}
	}
	smartPtr = obj.smartPtr; 
	if (smartPtr) smartPtr->counter++; 
		return *this;
}
//////// --- Transaction  --- //////////
template <class T2>
class Transaction {
	T2* currentState; // текущее значение объекта класса
	T2* prevState; // предыдущее значение объекта класса
public:
	Transaction() :prevState(NULL), currentState(new T2) {} //конструктор

		Transaction(const Transaction& obj) : currentState(new T2(*(obj.currentState))), prevState(NULL) {}

	~Transaction() { delete currentState; delete prevState; } //деструктор

	Transaction& operator=(const Transaction& obj); // перегрузка операции присваивания

	void show(int);//отображение состояний (предыдущего и текущего) объекта
	int BeginTransactions(int, string); // метод начала транзакции
	void commit(); // метод подтветждения (коммита) транзакции
	void DeleteTransactions(); //метод отката транзакции

	T2* operator->(); // перегрузка операции ->
};
// перегрузка оператора =
template <class T2>
Transaction<T2>& Transaction<T2>::operator=(const Transaction<T2>& obj)
{
	if (this != &obj) // проверка на случай obj=obj
	{
		delete currentState; // удаление текущего значения объекта
		currentState = new T2(*(obj.currentState)); // создание и	копирование
	}
	return *this;
}
// перегрузка оператора -> 
template <class T2>
T2* Transaction<T2>::operator->()
{
	return currentState;
}
// метод отображения состояния объекта
template <class T2>
void Transaction<T2>::show(int account) {
	cout << "состояния объекта ";
	if (!account) cout << "до начала транзакции " << endl;
	else cout << "после выполнения транзакции " << endl;
	if (prevState) cout << "prevState = " << prevState->getSalary() << endl;
	// предыдущее состояние
	else cout << "prevState = NULL" << endl;
	cout << "currentState = " << currentState->getSalary() << endl; // текущее состояние
	cout << currentState->showData() << endl;
	//cout << "Количесво укзателей: ";
	//cout << currentState->showCounter() << endl;;
	
}
template <class T2>
int Transaction<T2>::BeginTransactions(int number, string name) {// метод начала транзакции
	delete prevState; // удаление предыдущего значения
	prevState = currentState; // текущее становится предыдущим
	currentState = new T2(*prevState); // создание нового значения текущего состояния
		if (!currentState) return 0; // ошибка (необходимо отменить действие)
	currentState->setSalary(number); // изменение состояния объекта
	currentState->setName(name);
	return 1; // успешное окончание транзакции
}
template <class T2>
void Transaction<T2>::commit() {// метод подтветждения (коммита) транзакции
		delete prevState; // удаление предыдущего значения
	prevState = NULL; // предыдущего состояния нет
}
template <class T2>
void Transaction<T2>::DeleteTransactions() {//метод отката транзакции
	if (prevState != NULL) {
		delete currentState; // удаление текущего значения
		currentState = prevState; // предыдущее становится текущим
		prevState = NULL; // предыдущего состояния нет
	}
}
	







int main()
{
	setlocale(LC_ALL, "rus");
	Transaction<SmartPointer<int>> TransactionHR;
	Transaction<SmartPointerTest<int>> TransactionTest;
	Transaction<SmartPointerDev<int>> TransactionDev;

	SmartPointer<int> employeeHR;
	SmartPointerTest<int> employeeTest;
	SmartPointerDev<int> employeeDev;
	
	cout << "             Сотрудники:          " << endl;
	employeeHR.setName("Nik");
	employeeHR.setSalary(1000);
	employeeHR.showData();
	cout << "" << endl;
	employeeTest.setName("Tom");
	employeeTest.setSalary(1500);
	employeeTest.showData();
	cout << "" << endl;
	employeeDev.setName("Max");
	employeeDev.setSalary(1700);
	employeeDev.showData();

	//int a = 0;
	//cout << "hsifov== " << endl;
	//cin >> a;
	//firstTransaction.show(0);
	//cout << "НАЧАЛЬНАЯ ИНИЦИАЛИЗАЦИЯ ПРОШЛА УСПЕШНО" << endl;
	cout << endl;
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ В HR НАЧАТА СО ЗНАЧЕНИЕМ <1200, Kolya> " << endl;
	if (TransactionHR.BeginTransactions(1200,"Kolya")) // начало транзакции (изменение объекта)
	{
		TransactionHR.show(1);
		TransactionHR.commit(); // закрепление транзакции
	}
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ ПРОШЛА УСПЕШНО" << endl;
	cout << endl;

	cout << "ВТОРАЯ ТРАНЗАКЦИЯ В HR НАЧАТА СО ЗНАЧЕНИЕМ <1200, САНЯ> " << endl;
	if (TransactionHR.BeginTransactions(1200, "САНЯ")) // начало транзакции (изменение объекта)
	{
		
		TransactionHR.DeleteTransactions(); // закрепление транзакции
		TransactionHR.show(1);
	}
	cout << "ВТОРАЯ ТРАНЗАКЦИЯ ОТМЕНЕНА" << endl;
	cout << endl;

	employeeHR.showCounter();
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ В Tets НАЧАТА СО ЗНАЧЕНИЕМ <1560, Alex> " << endl;
	if (TransactionTest.BeginTransactions(1560, "Alex")) // начало транзакции (изменение объекта)
	{
		TransactionTest.show(1);
		TransactionTest.commit(); // закрепление транзакции
	}
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ ПРОШЛА УСПЕШНО" << endl;
	cout << endl;
	//employeeDev.showData();
	return 0;

	/*
	HR<int> pointerHR = new int(0);
	
	//pointerHR.set();
	//pointerHR.get();
	Transaction<HR<int>> firstTransaction;
	setlocale(LC_ALL, "Russian");
	//firstTransaction->set(5); // начальная инициализация объекта
	firstTransaction.show(0);
	cout << "НАЧАЛЬНАЯ ИНИЦИАЛИЗАЦИЯ ПРОШЛА УСПЕШНО" << endl;
	cout << endl;
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ НАЧАТА СО ЗНАЧЕНИЕМ 10" << endl;
	if (firstTransaction.BeginTransactions(10)) // начало транзакции (изменение объекта)
	{
		firstTransaction.show(1);
		firstTransaction.commit(); // закрепление транзакции
	}
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ ПРОШЛА УСПЕШНО" << endl;
	cout << endl;
	firstTransaction.DeleteTransactions(); // отмена транзакции при ошибке
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ БЫЛА ОТМЕНЕНА" << endl;
	firstTransaction.show(0);
	cout << endl;
	*/
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
