/*Author: Kevin*/
#ifndef MMATRIX_H_INCLUDED
#define MMATRIX_H_INCLUDED

#include <vector>
#include <iostream>
#include <stdexcept>
#include <math.h>
typedef unsigned int UINT;

namespace DataStructure
{
  class Vvector
  {

  };

  /**a exception class for creating an exception like throw Eexception("Error")  */
  class Eexception
  {
  public:
     const char* err_msg;
     Eexception(const char* arg): err_msg(arg) {}
     ~Eexception() {}
  };

  //first replace the employed vector with std::vector
  template<typename T>
  class Mmatrix
  {
  public:
    Mmatrix(const UINT& rows_, const UINT& cols_, const T& initial_=0);
    Mmatrix(const UINT& rows_, const UINT& cols_, const std::vector<T>& arr);
    Mmatrix(const Mmatrix& rmat);
    //allow to change the shape of the matrix
    Mmatrix<T> operator=(const Mmatrix<T>& rmat);//copy assigment for matrix equation
    ~Mmatrix();
    Mmatrix<T> ones(const UINT& rows_, const UINT& cols_);
    //Mmatrix<T> zeros(const UINT& rows_, const UINT& cols_); //constructor work as zeros
    Mmatrix<T> diag(const UINT & len); //return a n*n diagonal matrix
    Mmatrix<T> inverse() const; //inverse the current matrix
    Mmatrix<T> inverse(const Mmatrix<T> & rmat) const; //inverse a given matrix
    double det(Mmatrix<T> & rmat); //calculate the determinant of a matrix
    //double det(UINT & len) const;
    //get sub-matrix of the given matrix, start from [row_.col_] cover a range of len_
    Mmatrix<T> sub_matrix(const Mmatrix<T> & rmat, const UINT row_, const UINT col_, const UINT len_) const throw (std::runtime_error);
    Mmatrix<T> sub_matrix(const UINT row_, const UINT col_, const UINT len_) const throw (std::runtime_error); //sub-matrix of this matrix
    //return a minor matrix where the selected row and column are removed
    Mmatrix<T> minor_matrix(const UINT& row, const UINT& col) const;

    //overload operators for matrix to matrix mathematical operations
    Mmatrix<T> operator+(const Mmatrix<T>& rmat) const throw (std::runtime_error);
    Mmatrix<T>& operator+=(const Mmatrix<T>& rmat) throw (std::runtime_error);
    Mmatrix<T> operator-(const Mmatrix<T>& rmat) const throw (std::runtime_error);
    Mmatrix<T>& operator-=(const Mmatrix<T>& rmat) throw (std::runtime_error);
    //Left multiplication of this matrix and another
    Mmatrix<T> operator*(const Mmatrix<T>& rmat) const throw (std::runtime_error);
    Mmatrix<T>& operator*=(const Mmatrix<T>& rmat) throw (std::runtime_error);

    //overload operators for matrix-scalar operations
    Mmatrix<T> operator+(const T& rT) const;
    Mmatrix<T> operator-(const T& rT) const;
    Mmatrix<T> operator*(const T& rT) const;
    Mmatrix<T> operator/(const T& rT) const;
    //overload operators for matrix-vector operations
    Mmatrix<T> operator*(const std::vector<T>& rarr) const throw (std::runtime_error);

    //random access for read and write matrix members
    T& operator()(const UINT& row, const UINT& col); //write
    const T& operator()(const UINT& row, const UINT& col) const; //read-only

    //matrix transpose and ...
    Mmatrix<T> transpose();


    //access row and column size
    UINT get_rows() const {return this->rows;}
    UINT get_cols() const {return this->cols;}
    UINT get_len() const;
    UINT get_len(const Mmatrix<T> & rmat) const;
    std::ostream & print(std::ostream & ros) const; //print out all elements of the matrix
    bool is_same_shape(const Mmatrix<T> & rmat) const; //see if two matrix have the indentical size
    bool is_multiplable(const Mmatrix<T> & rmat) const; //see if two matrix have the ability to do right multiple; //this*matrix
    bool is_square() const {return this->rows==this->cols;}
    bool is_square(const Mmatrix<T> & rmat) const {return rmat.get_cols()==rmat.get_rows();}
    const double EPS=0.00001; //a threshold for float-zero

  private:
    std::vector<std::vector<T> > mat;
    UINT rows; //using unsigned int to make sure the matrix set up has at least one element
    UINT cols;
    void swap_(T& a, T& b); //swap a with b
  };

  template class Mmatrix <double>;

};

#endif // MMATRIX_H_INCLUDED
