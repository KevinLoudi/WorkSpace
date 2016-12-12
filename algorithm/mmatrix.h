/*Author: Kevin*/
#ifndef MMATRIX_H_INCLUDED
#define MMATRIX_H_INCLUDED

#include <vector>
#include <iostream>
#include <stdexcept>
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
    Mmatrix(const Mmatrix& rmat);
    //allow to change the shape of the matrix
    Mmatrix<T> operator=(const Mmatrix<T>& rmat);//copy assigment for matrix equation
    ~Mmatrix();
    Mmatrix<T> ones(const UINT& rows_, const UINT& cols_);
    //Mmatrix<T> zeros(const UINT& rows_, const UINT& cols_); //constructor work as zeros
    Mmatrix<T> diag(const UINT & len); //return a n*n diagonal matrix
    double Det(const Mmatrix<T> & rmat) const; //calculate the determinant of a matrix
    double Det() const;

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
    std::ostream & print(std::ostream & ros) const; //print out all elements of the matrix
    bool is_same_shape(const Mmatrix<T> & rmat) const; //see if two matrix have the indentical size
    bool is_multiplable(const Mmatrix<T> & rmat) const; //see if two matrix have the ability to do right multiple; //this*matrix
    const double EPS=0.00001; //a threshold for float-zero

  private:
    std::vector<std::vector<T> > mat;
    UINT rows; //using unsigned int to make sure the matrix set up has at least one element
    UINT cols;
  };

  template class Mmatrix <double>;

};

#endif // MMATRIX_H_INCLUDED
