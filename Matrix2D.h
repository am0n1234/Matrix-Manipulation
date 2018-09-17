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
		populate_matrix(int * src, int src_size),	//prints out matrix on screen
		add(Matrix2D& x),	//a matrix is added
		subtract(Matrix2D& x);	//a matrix 

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
