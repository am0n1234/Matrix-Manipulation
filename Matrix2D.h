#include <iostream> 
using namespace std;
namespace MatrixClass{

	class Matrix2D
	{
	private:		//private members are the members that can only be accessed within the class

		int rows = 0;
		int cols = 0;
		int ** matrix_pointer;		//points to the created matrix;

	public:
		Matrix2D(int rows, int cols) : rows(rows), cols(cols) {	//constructor
			this->matrix_pointer = generate_matrix(rows, cols);
		};	
		~Matrix2D();		//destructor
		int ** generate_matrix(int rows, int cols);	
		void	print(), 
			populate_matrix(int * src, int src_size),	
			transpose(),
			add(Matrix2D& x),	
			subtract(Matrix2D& x),
			set_value_at(int i, int j, int value),
			mult(Matrix2D& x);
		int 	get_value_at(int i, int j),
			get_rows(),
			get_cols();

	};
}

int ** MatrixClass::Matrix2D::generate_matrix(int rows, int cols){
	//generates a rows x columns matrix
	int **temp = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[cols];
	}
	return temp;

}
void MatrixClass::Matrix2D::print(){
	//prints out a matrix on screen
	cout << endl;
	for (int i = 0; i < this->rows; i++)
	{
		cout << "|	";
		for (int j = 0; j < this->cols; j++)
		{
				cout << this->matrix_pointer[i][j] << "	";
		}
		cout << "|";
		cout << endl;
	}
	cout << endl;
}
MatrixClass::Matrix2D::~Matrix2D()	{

	for (int i = 0; i < this->rows; i++)
	{
		//we will delete each row
		delete this->matrix_pointer[i];
	}
	// after each row is deleted we will delete the main pointer that points to the matrix
	delete this->matrix_pointer;

}
void MatrixClass::Matrix2D::populate_matrix(int *src, int src_size){
	if (this->rows*this->cols != src_size)
	{
		cout << "the matrix does not match with the source size!" << endl;
		system("pause");
		exit(-1);
	}
	//the source file that was recieved was perfectly fine

	int pos = 0;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			this->matrix_pointer[i][j] = src[pos++];

		}

	}

}
void MatrixClass::Matrix2D::add(Matrix2D &x){

	if (this->rows != x.get_rows() || this->cols != x.get_cols())
	{
		cout << "Addition invalid!" << endl;
		system("pause");
		exit(-1);
	}
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			this->matrix_pointer[i][j] = this->matrix_pointer[i][j] + x.get_value_at(i, j);
		}
	}
}
void MatrixClass::Matrix2D::subtract(Matrix2D &x) {

	if (this->rows != x.get_rows() || this->cols != x.get_cols())
	{
		cout << "Subtraction of these two matrices is invalid!" << endl;
		system("pause");
		exit(-1);
	}
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			this->matrix_pointer[i][j] -= x.get_value_at(i, j);
		}
	}

}

void MatrixClass::Matrix2D::transpose() {
	//In place transposition of a matrix
	int ** temp = generate_matrix(this->cols, this->rows); // n x m	matrix generated

	for (int i = 0; i < this->rows; i++)		//temp is a transposed matrix created
	{
		for (int j = 0; j < this->cols; j++)
		{
			temp[j][i] = this->matrix_pointer[i][j];
		}
	}

	for (int i = 0; i < this->rows; i++)		//the old matrix is deallocated from memory
	{
		//we will delete each row
		delete this->matrix_pointer[i];
	}
	this->matrix_pointer = temp;	// the object now points to the tranposed matrix
	//the temporary pointer is deallocated from memory
	int x = this->rows;
	this->rows = this->cols;
	this->cols = x;
	temp = NULL;
	delete temp;
}
void MatrixClass::Matrix2D::set_value_at(int i, int j, int value){
	this->matrix_pointer[i][j] = value;
}
int MatrixClass::Matrix2D::get_value_at(int i, int j){
	return this->matrix_pointer[i][j];
}
int* MatrixClass::Matrix2D::get_row(int row_number){
	int * temp = new int[this->cols - 1];
	temp = this->matrix_pointer[row_number];
	return temp;
}
int* MatrixClass::Matrix2D::get_column(int column_number){
	int * temp = new int[this->rows - 1];
	for (int i = 0; i < this->rows; i++)
	{
		temp[i] = this->matrix_pointer[i][column_number];
	}
	return temp;
}
int MatrixClass::Matrix2D::get_cols(){
	return this->cols;
}
int MatrixClass::Matrix2D::get_rows(){
	return this->rows;
}
int dot_product(int *a, int*b, int size){
	int temp = 0;

	for (int i = 0; i < size; i++)
	{
		temp += (a[i] * b[i]);
	}

	return temp;
}
void MatrixClass::Matrix2D::mult(Matrix2D& x){
	int src_size = this->get_cols();
	if (this->get_cols() != x.get_rows())
	{
		cout << "The matrix multiplication of these two matrices is invalid" << endl <<endl;
		system("pause");
		exit(-1);
	}
	//firstly we must establish that the resultant matrix will be row_a x cols_b 
	int resultant_rows = this->get_rows();
	int resultant_cols = x.get_cols();
	int ** temp = generate_matrix(resultant_rows, resultant_cols);
	int * a = new int[];
	int * b = new int[];


	for (int i = 0; i < resultant_rows; i++)
	{
		for (int j = 0; j < resultant_cols; j++)
		{
			a = this->get_row(i);
			b = x.get_column(j);
			temp[i][j] = dot_product(a, b, src_size);
		}
	}
	//delete the previous matrix row by row, 

	for (int i = 0; i < this->get_rows(); i++)
	{
		delete this->matrix_pointer[i];
	}
	this->matrix_pointer = temp;

	this->rows = resultant_rows;
	this->cols = resultant_cols;

	temp = NULL;
	delete temp;
}
