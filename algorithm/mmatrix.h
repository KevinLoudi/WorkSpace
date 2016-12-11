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

  //first replace the employed vector with std::vector
  template<typename T>
  class Mmatrix
  {
  public:
    Mmatrix(UINT rows_, UINT cols_, const T& initial_);
    Mmatrix(const Mmatrix& rmat);
    //allow to change the shape of the matrix
    Mmatrix<T> operator=(const Mmatrix<T>& rmat);//copy assigment for matrix equation
    ~Mmatrix();

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
    Mmatrix<T> diag();

    //access row and column size
    UINT get_rows() const {return this->rows;}
    UINT get_cols() const {return this->cols;}
    std::ostream & print(std::ostream & ros) const; //print out all elements of the matrix

  private:
    std::vector<std::vector<T> > mat;
    UINT rows;
    UINT cols;
  };

  template class Mmatrix <double>;

};

#endif // MMATRIX_H_INCLUDED
