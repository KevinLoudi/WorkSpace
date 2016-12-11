#include "mmatrix.h"

namespace DataStructure
{
    template<typename T>
    Mmatrix<T>::Mmatrix(UINT rows_, UINT cols_, const T& initial_)
    {
        mat.resize(rows_); //let the container contains rows_ elements
        for(UINT i=0; i<mat.size(); ++i)
        {
            mat[i].resize(cols_,initial_); //let each containers contain cols_ initial_ values
        }
        rows=rows_;
        cols=cols_;
    }

    template<typename T>
    Mmatrix<T>::Mmatrix(const Mmatrix& rmat)
    {
        mat=rmat.mat;
        rows=rmat.get_rows();
        cols=rmat.get_cols();
    }

    template<typename T>
    Mmatrix<T>::~Mmatrix()
    {

    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::operator=(const Mmatrix<T>& rmat)
    {
        if(this==&rmat) return *this;
        UINT new_rows=rmat.get_rows();
        UINT new_cols=rmat.get_cols();

        //allocate memory
        mat.resize(new_cols);
        for(UINT i=0; i<mat.size(); ++i)
        {
            mat[i].resize(new_cols);
        }

        //assign value one by one
        for(UINT i=0; i<new_rows; ++i)
            for(UINT j=0; j<new_cols; ++j)
                mat[i][j]=rmat(i,j);

          rows = new_rows;
          cols = new_cols;

          return *this;
    }

    template<typename T>
    std::ostream & Mmatrix<T>::print(std::ostream & ros) const
    {
        ros<<"\nFollowing is all elements of the matrix....\n";
        for(UINT i=0; i<this->rows; ++i)
        {
             for(UINT j=0; j<this->cols; ++j)
             {
                 ros<<this->mat[i][j]<<"\t";
             }
             ros<<"\n";
        }
        return ros;
    }

    template<typename T>
    inline T& Mmatrix<T>::operator()(const UINT& row, const UINT& col)
    {
        return this->mat[row][col];
    }

    template<typename T>
    inline const T& Mmatrix<T>::operator()(const UINT& row, const UINT& col) const
    {
        return this->mat[row][col];
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::operator+(const Mmatrix<T>& rmat) const throw (std::runtime_error)
    {
        //execute after evaluate the expression as true
        if(rows!=rmat.get_rows() || cols!=rmat.get_cols())
            throw std::runtime_error("matrix dimension do not match!!");

        UINT s_rows=rmat.get_rows();
        UINT s_cols=rmat.get_cols();
        Mmatrix<T> result(s_rows,s_cols,0);

        for(UINT i=0; i<s_rows; ++i)
        {
             for(UINT j=0; j<s_cols; ++j)
             {
                 result(i,j)=this->mat[i][j]+rmat(i,j);
             }
        }

        return result;//copy out by value could cause performance deduct ??
    }

    template<typename T>
    Mmatrix<T>& Mmatrix<T>::operator+=(const Mmatrix<T>& rmat) throw (std::runtime_error)
    {
        //execute after evaluate the expression as true
        if(rows!=rmat.get_rows() || cols!=rmat.get_cols())
            throw std::runtime_error("matrix dimension do not match!!");
        UINT s_rows=rmat.get_rows();
        UINT s_cols=rmat.get_cols();

        for(UINT i=0; i<s_rows; ++i)
        {
             for(UINT j=0; j<s_cols; ++j)
             {
                 this->mat[i][j]+=rmat(i,j);
             }
        }
        return *this;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::operator-(const Mmatrix<T>& rmat) const throw (std::runtime_error)
    {
        //execute after evaluate the expression as true
        if(rows!=rmat.get_rows() || cols!=rmat.get_cols())
            throw std::runtime_error("matrix dimension do not match!!");

        UINT s_rows=rmat.get_rows();
        UINT s_cols=rmat.get_cols();
        Mmatrix<T> result(s_rows,s_cols,0);

        for(UINT i=0; i<s_rows; ++i)
        {
             for(UINT j=0; j<s_cols; ++j)
             {
                 result(i,j)=this->mat[i][j]-rmat(i,j);
             }
        }

        return result;//copy out by value could cause performance deduct ??
    }

    template<typename T>
    Mmatrix<T>& Mmatrix<T>::operator-=(const Mmatrix<T>& rmat) throw (std::runtime_error)
    {
        //execute after evaluate the expression as true
        if(rows!=rmat.get_rows() || cols!=rmat.get_cols())
            throw std::runtime_error("matrix dimension do not match!!");
        UINT s_rows=rmat.get_rows();
        UINT s_cols=rmat.get_cols();

        for(UINT i=0; i<s_rows; ++i)
        {
             for(UINT j=0; j<s_cols; ++j)
             {
                 this->mat[i][j]-=rmat(i,j);
             }
        }
        return *this;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::operator*(const Mmatrix<T>& rmat) const throw (std::runtime_error)
    {
        UINT l_rows=rows;
        UINT l_cols=cols;
        UINT r_rows=rmat.get_rows();
        UINT r_cols=rmat.get_cols();
        //execute after evaluate the expression as true
        //[M,N]*[N,T], so l_cols should equals to r_rows
        if(l_cols!=r_rows )
            throw std::runtime_error("matrix dimension do not match!!");

        Mmatrix<T> result(l_rows,r_cols,0.0);
        /**| 1   1 |    | 2 |        | 4 |
            |  1  1  | * | 2 | ==>| 4 |
            |  1 1  |                   | 4 |
         *///  [3,2] * [2,1] ==>[3,1]

        for(UINT i=0; i<l_rows; ++i)
        {
            for(UINT j=0; j<r_cols;++j)
            {
                for(UINT k=0; k<l_cols;++k)
                {
                    result(i,j)+=this->mat[i][k]*rmat(k,j);
                }
            }
        }
        return result;
    }

    template<typename T>
    Mmatrix<T>& Mmatrix<T>::operator*=(const Mmatrix<T>& rmat) throw (std::runtime_error)
    {
        Mmatrix<T> result=(*this)*rmat;
        //re-assign the result to 'this' object
        *this=result;
        return *this;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::operator+(const T& rT) const
    {
         Mmatrix<T> result(rows, cols, 0.0);
         for(UINT i=0; i<rows; ++i)
         {
            for(UINT j=0; j<cols;++j)
             {
                 result(i,j)=this->mat[i][j]+rT;
             }
         }

         return result;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::operator-(const T& rT) const
    {
         Mmatrix<T> result(rows, cols, 0.0);
         for(UINT i=0; i<rows; ++i)
         {
            for(UINT j=0; j<cols;++j)
             {
                 result(i,j)=this->mat[i][j]-rT;
             }
         }

         return result;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::operator*(const T& rT) const
    {
         Mmatrix<T> result(rows, cols, 0.0);
         for(UINT i=0; i<rows; ++i)
         {
            for(UINT j=0; j<cols;++j)
             {
                 result(i,j)=this->mat[i][j]*rT;
             }
         }

         return result;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::operator/(const T& rT) const
    {
         Mmatrix<T> result(rows, cols, 0.0);
         for(UINT i=0; i<rows; ++i)
         {
            for(UINT j=0; j<cols;++j)
             {
                 result(i,j)=this->mat[i][j]/rT;
             }
         }

         return result;
    }

    template<typename T>
    std::vector<T> Mmatrix<T>::operator*(const std::vector<T>& rarr) const throw (std::runtime_error)
    {
        UINT s_len=rarr.size();
        if(s_len!=cols) throw std::runtime_error("the input vector does not match the dimension of the matrix!!!");
        std::vector<T> res_vec(rows,0.0);

        for(UINT i=0; i<rows; ++i)
         {
            for(UINT j=0; j<cols;++j) //cols also indicate the length of input vector
             {
                 res_vec[i]+=this->mat[i][j]*rarr[j]; //each vector element multiple with each row of the matrix
             }
         }

        return res_vec;
    }
};
