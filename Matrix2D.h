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
		void	print(),	//prints out matrix on screen


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
