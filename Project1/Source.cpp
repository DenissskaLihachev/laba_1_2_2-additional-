#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

void firstTask();
void secondTask();
void individualTask();
void additionalTask();

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	while (true)
	{

		cout << "\t\t\t/////      /////  ////////  //////     ///  ///      ///\n";
		cout << "\t\t\t//////    //////  ////////  //////     ///  ///      ///\n";
		cout << "\t\t\t///  //////  ///  ///       /// ///    ///  ///      ///\n";
		cout << "\t\t\t///   ////   ///  //////    ///  ///   ///  ///      ///\n";
		cout << "\t\t\t///          ///  //////    ///   ///  ///  ///      ///\n";
		cout << "\t\t\t///          ///  ///       ///    /// ///  ///      ///\n";
		cout << "\t\t\t///          ///  ////////  ///     //////  ///      ///\n";
		cout << "\t\t\t///          ///  ////////  ///      /////  ////////////\n";
		cout << "\t\t\t--------------------------------------------------------\n";


		cout << "\t\t\t\t\t|1)Задание 1             |\n\t\t\t\t\t|2)Задание 2             |\n\t\t\t\t\t" <<
			"|3)Индивидуальное задание|\n\t\t\t\t\t|4)Дополнительное задание|\n\t\t\t\t\t---------------" <<
			"-----------\n\t\t\t\t\tВыбор: ";
		int menuChoice; cin >> menuChoice;

		switch (menuChoice)
		{
		case(1): { std::system("cls"); firstTask();      break; }
		case(2): { std::system("cls"); secondTask();     break; }
		case(3): { std::system("cls"); individualTask(); break; }
		case(4): { std::system("cls"); additionalTask(); break; }
		default: {std::cout << "Введено неверное значение..."; _getch(); std::system("cls"); break; }
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region firstGeneralTask

void firstTask()
{

}

#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region secondTask

void secondTask()
{

}

#pragma endregion

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region individualTask

void individualTask()
{

}

#pragma endregion

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region Additional task

typedef struct tree
{
	int field;
	struct tree* left, * right;
} TREE;

TREE* AddTree(TREE* root, int value)
{
	if (root == NULL)
	{
		root = new TREE;
		root->field = value;
		root->left = root->right = 0;
		return root;
	}
	if (root->field < value)						 //добавлем ветвь
		root->right = AddTree(root->right, value);
	else
		root->left = AddTree(root->left, value);
	return root;
}

void ArrTree(TREE* root, int arr[], int* counter)
{
	if (root->left != NULL)
		ArrTree(root->left, arr, counter);			 //обход левого поддерева
	arr[(*counter)++] = root->field;
	if (root->right != NULL)
		ArrTree(root->right, arr, counter);			 //обход правого поддерева
	free(root);
}

void TreeSort(int arr[], int size)
{
	TREE* root;
	int i;
	root = NULL;

	for (i = 0; i < size; i++)
		root = AddTree(root, arr[i]);

	int* count = new int;
	*count = 0;
	ArrTree(root, arr, count);						 // заполнение массива
}

void additionalTask()
{
	srand(time(NULL));

	cout << "Введите размер: ";
	int size;
	cin >> size;
	system("cls");
	int* arr = new int[size];

	cout << "Без сортировки: ";
	for (int i = 0; i < size; i++)
	{
		int temp = rand() % 100;
		arr[i] = temp;
		cout << temp << " ";
	}

	TreeSort(arr, size);

	cout << "Отсортирован: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	_getch(); system("cls");
}

#pragma endregion