#include "Matrix2D.h"
#include <iostream>
#include <stdio.h>
#include <string> 
void introduction(), addition_test(), subtraction_test(), transposition_test(), multiplication_test();
using namespace std;
using namespace MatrixClass;
int main(){

	string user_input;

	introduction();
	cin >> user_input;

	if (user_input == "a")
	{
		addition_test();
	}
	else if (user_input == "b")
	{
		subtraction_test();
	}
	else if (user_input == "c")
	{
		transposition_test();
	}
	else if (user_input == "d")
	{
		multiplication_test();
	}
	else if (user_input == "e")
	{
		exit(-1);

	}
	else
	{
		cout << "invalid input!" << endl;
		system("cls");

	}

	system("pause");
}
void introduction(){
	cout << "--LAB 2: MATRIX ARITHMATIC AND MANIPULATION--\n\nGROUP MEMBERS:\n";
	cout << "	Aman	Ullah			174267" << endl;
	cout << "	Khola	Azwar			175946" << endl;
	cout << "	Khawaja Abdul Ahad		174267" << endl << endl;

	system("pause");
	system("cls");

	cout << "--LAB 2: MATRIX ARITHMATIC AND MANIPULATION--\n\n";
	cout << "what operation would you like to perform?" << endl;
	cout << "a. matrix addition" << endl;
	cout << "b. matrix subtraction" << endl;
	cout << "c. matrix transposition" << endl;
	cout << "d. matrix multiplication" << endl;
	cout << "e. exit program" << endl<<endl;
	cout << "user input: ";
}
void addition_test(){
	int* m = new int;
	int* n = new int;

	int *total_elements = new int;
	system("cls");
	cout << "---Matrix Addition---" << endl <<endl;
	cout << "How many rows would you like the matrices to have?" << endl;
	cin >> *m;
	cout << "How many columns would you like matrices to have?" << endl;
	cin >> *n;
	*total_elements = (*m) * (*n);

	int * src_array = new int[*total_elements];

	system("cls");
	cout << "---Matrix Addition---" << endl << endl;
	cout << "Please enter the " << *total_elements << " elements of Matrix A" << endl;
	for (int i = 0; i < *total_elements; i++)
	{
		cin >> src_array[i];
	}
	Matrix2D M1(*m, *n);
	M1.populate_matrix(src_array, *total_elements);
	system("cls");
	cout << "---Matrix Addition---" << endl << endl;
	cout << "Matrix A:" << endl;
	M1.print();
	system("pause");
	system("cls");
	cout << "---Matrix Addition---" << endl << endl;
	cout << "Please enter the " << *total_elements << " elements of Matrix B" << endl;
	for (int i = 0; i < *total_elements; i++)
	{
		cin >> src_array[i];
	}
	system("cls");
	cout << "---Matrix Addition---" << endl << endl;
	Matrix2D M2(*m, *n);
	M2.populate_matrix(src_array, *total_elements);


	
	cout << "Matrix B: " << endl;
	M2.print();
	system("pause");
	system("cls");
	cout << "---Matrix Addition---" << endl << endl;
	M1.add(M2);
	cout << "Matrix A + Matrix B: " << endl;
	M1.print();

	//getting rid of memory leaks beyond this point
	delete m;
	m = NULL;
	delete n;
	n = NULL;
	delete src_array;
	src_array = NULL;
	delete total_elements;
	total_elements = NULL;
}
void subtraction_test() {
	int* m = new int;
	int* n = new int;

	int *total_elements = new int;
	system("cls");
	cout << "---Matrix Subtraction---" << endl << endl;
	cout << "How many rows would you like the matrices to have?" << endl;
	cin >> *m;
	cout << "How many columns would you like matrices to have?" << endl;
	cin >> *n;
	*total_elements = (*m) * (*n);

	int * src_array = new int[*total_elements];

	system("cls");
	cout << "---Matrix Subtraction---" << endl << endl;
	cout << "Please enter the " << *total_elements << " elements of Matrix A" << endl;
	for (int i = 0; i < *total_elements; i++)
	{
		cin >> src_array[i];
	}
	Matrix2D M1(*m, *n);
	M1.populate_matrix(src_array, *total_elements);
	system("cls");
	cout << "---Matrix Subtraction---" << endl << endl;
	cout << "Matrix A:" << endl;
	M1.print();
	system("pause");
	system("cls");
	cout << "---Matrix Subtraction---" << endl << endl;
	cout << "Please enter the " << *total_elements << " elements of Matrix B" << endl;
	for (int i = 0; i < *total_elements; i++)
	{
		cin >> src_array[i];
	}
	system("cls");
	cout << "---Matrix Subtraction---" << endl << endl;
	Matrix2D M2(*m, *n);
	M2.populate_matrix(src_array, *total_elements);



	cout << "Matrix B: " << endl;
	M2.print();
	system("pause");
	system("cls");
	cout << "---Matrix Subtraction---" << endl << endl;
	M1.subtract(M2);
	cout << "Matrix A - Matrix B: " << endl;
	M1.print();

	//getting rid of memory leaks beyond this point
	delete m;
	m = NULL;
	delete n;
	n = NULL;
	delete src_array;
	src_array = NULL;
	delete total_elements;
	total_elements = NULL;
}
void transposition_test(){
	int* m = new int;
	int* n = new int;

	int *total_elements = new int;
	system("cls");
	cout << "---Matrix Transposition---" << endl << endl;
	cout << "How many rows would you like the matrices to have?" << endl;
	cin >> *m;
	cout << "How many columns would you like matrices to have?" << endl;
	cin >> *n;
	*total_elements = (*m) * (*n);

	int * src_array = new int[*total_elements];

	system("cls");
	cout << "---Matrix Transposition---" << endl << endl;
	cout << "Please enter the " << *total_elements << " elements of Matrix A" << endl;
	for (int i = 0; i < *total_elements; i++)
	{
		cin >> src_array[i];
	}
	Matrix2D M1(*m, *n);
	M1.populate_matrix(src_array, *total_elements);
	system("cls");
	cout << "---Matrix Subtraction---" << endl << endl;
	cout << "Matrix A:" << endl;
	M1.print();
	system("pause");
	system("cls");
	cout << "---Matrix Subtraction---" << endl << endl;
	cout << "Matrix A(Transposed):" << endl;
	M1.transpose();
	M1.print();
	delete m;
	m = NULL;
	delete n;
	n = NULL;
	delete src_array;
	src_array = NULL;
	delete total_elements;
	total_elements = NULL;
}
void multiplication_test() {
	int* m = new int;
	int* n = new int;
	int *total_elements = new int;
	system("cls");
	cout << "---Matrix Multiplication---" << endl << endl;
	cout << "How many rows would you like Matrix A to have?" << endl;
	cin >> *m;
	cout << "How many columns would you like Matrix A to have?" << endl;
	cin >> *n;
	*total_elements = (*m) * (*n);

	int * src_array = new int[*total_elements];

	system("cls");
	cout << "---Matrix Multiplication---" << endl << endl;
	cout << "Please enter the " << *total_elements << " elements of Matrix A" << endl;
	for (int i = 0; i < *total_elements; i++)
	{
		cin >> src_array[i];
	}
	Matrix2D M1(*m, *n);
	M1.populate_matrix(src_array, *total_elements);
	system("cls");
	cout << "---Matrix Multiplication---" << endl << endl;
	cout << "Matrix A:" << endl;
	M1.print();
	system("pause");
	system("cls");

	cout << "---Matrix Multiplication---" << endl << endl;
	*m = *n;
	cout << "How many columns would you like Matrix B to have?" << endl;
	cin >> *n;
	system("cls");
	*total_elements = (*m) * (*n);
	cout << "---Matrix Multiplication---" << endl << endl;
	cout << "Please enter the " << *total_elements << " elements of Matrix B" << endl;
	delete src_array;
	src_array = new int[*total_elements];
	for (int i = 0; i < *total_elements; i++)
	{
		cin >> src_array[i];
	}
	system("cls");
	cout << "---Matrix Multiplication---" << endl << endl;
	Matrix2D M2(*m, *n);
	M2.populate_matrix(src_array, *total_elements);



	cout << "Matrix B: " << endl;
	M2.print();
	system("pause");
	system("cls");
	cout << "---Matrix Multiplication---" << endl << endl;
	M1.mult(M2);
	cout << "Matrix A * Matrix B: " << endl;
	M1.print();

	//getting rid of memory leaks beyond this point
	delete m;
	m = NULL;
	delete n;
	n = NULL;
	delete src_array;
	src_array = NULL;
	delete total_elements;
	total_elements = NULL;
}