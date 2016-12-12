#include "mmatrix.h"

namespace DataStructure
{
    template<typename T>
    Mmatrix<T>::Mmatrix(const UINT& rows_, const UINT & cols_, const T& initial_)
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
    Mmatrix<T>::Mmatrix(const UINT& rows_, const UINT& cols_, const std::vector<T>& arr)
    {
        if((rows_*cols_)>arr.size()) throw Eexception("initialize data is not enough!!!");
        typename std::vector<T>::const_iterator it=arr.begin();

        for(UINT rx=0; rx<rows_; ++rx)
        {
            for(UINT cx=0; cx<cols_; ++cx)
            {
                this->mat[rx][cx]=*it;
                ++it;
            }
        }
    }

    template<typename T>
    Mmatrix<T>::~Mmatrix()
    {

    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::operator=(const Mmatrix<T>& rmat)
    {
        if(!is_same_shape(rmat)) throw Eexception("cannot assign matrix to a different shaped matrix!!!");
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
    Mmatrix<T> Mmatrix<T>::ones(const UINT& rows_, const UINT& cols_)
    {
         Mmatrix<T> res= Mmatrix<T>(rows_,cols_,1);
         return res;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::diag(const UINT & len)
    {
        Mmatrix<T> res= Mmatrix<T>(len,len);
        for(UINT ix=0; ix<len; ++ix)
            res(ix,ix)=1;
        return res;
    }

    template<typename T>
    double Mmatrix<T>::det(Mmatrix<T> & rmat)
    {
        if (!is_square()) throw Eexception("this matrix is not a square, cannot calculate determinate!!!");

        double d=0.0;
        UINT len=rows;

        if(len==1) d=this->mat[0][0];
        else if(len==2) d=this->mat[0][0]*this->mat[1][1]-this->mat[0][1]*this->mat[1][0];
        else
        {
            for(UINT ix=0; ix<len; ++ix)
            {
                Mmatrix<T>m=rmat.minor_matrix(0,ix);
                d+=(double)(pow(-1,ix+1)*this->mat[0][ix]*det(m));
                //recursive take part the big matrix to a 2*2 matrxi
            }
        }

        return d;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::minor_matrix(const UINT& row, const UINT& col) const
    {
        if( row>rows || col>cols) throw Eexception("error input");
        Mmatrix<T> res(rows-1,cols-1);

        for(UINT rx=0; rx <(rows-(row>=rows)) ; ++rx) //subtract one when index pass the would-be deleted row or col
        {
            for(UINT cx=0; cx<(cols-(col>=cols)); ++cx)
            {
                //pass the row,col before would-be deleted one normally
                //and pass them with one minus index when after
                res(rx-(rx>row),cx-(cx>col))=this->mat[rx-1][cx-1];
            }
        }

        return res;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::sub_matrix(const Mmatrix<T> & rmat, const UINT row_, const UINT col_, const UINT len_) const throw (std::runtime_error)
    {
        //see if the intended cut area will out bound
        if( ( (row_+len_)>rmat.get_rows())||( (col_+len_)>rmat.get_cols()) ) throw std::runtime_error("cut sub-matrix out of range!!");

        Mmatrix<T> res(len_,len_);
        for(UINT i=0; i<len_; ++i)
        {
            for(UINT j=0; j<len_; ++j)
            {
                res(i,j)=rmat(row_+i, col_+j);
            }
        }

        return res;
    }

    template<typename T>
    Mmatrix<T> Mmatrix<T>::sub_matrix(const UINT row_, const UINT col_, const UINT len_) const throw (std::runtime_error)
    {
        if( ( (row_+len_)>rows)||( (col_+len_)>cols) ) throw std::runtime_error("cut sub-matrix out of range!!");

        Mmatrix<T> res(len_,len_);
        for(UINT i=0; i<len_; ++i)
        {
            for(UINT j=0; j<len_; ++j)
            {
                res(i,j)=this->mat[row_+i][col_+j];
            }
        }

        return res;
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

//    template<typename T>
//    Mmatrix<T> Mmatrix<T>::inverse() const
//    {
//
//    }

    template<typename T>
    inline T& Mmatrix<T>::operator()(const UINT& row, const UINT& col)
    {
        if(row<this->rows && col<this->cols)
            return this->mat[row][col];
        else
            throw Eexception("Subscript out of range!!");
    }

    template<typename T>
    inline const T& Mmatrix<T>::operator()(const UINT& row, const UINT& col) const
    {
        if(row<this->rows && col<this->cols)
            return this->mat[row][col];
        else
            throw Eexception("Subscript out of range!!");
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
        if(!is_same_shape(rmat))
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
        //execute after evaluate the expression as true
        //[M,N]*[N,T], so l_cols should equals to r_rows
        if( !is_multiplable(rmat) )
            throw std::runtime_error("matrix dimension does not match!!");

        UINT l_rows=rows;
        UINT l_cols=cols;
        //UINT r_rows=rmat.get_rows();
        UINT r_cols=rmat.get_cols();

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
        if( !is_multiplable(rmat) ) throw Eexception("two matrix does not match in dimension!!");
        if(!is_same_shape(rmat)) throw Eexception("the matrix cannot be assigned for the differed shape!!");
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
         if(!((rT>EPS)||(rT<EPS))) throw Eexception("cannot divide zeros");
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
    Mmatrix<T> Mmatrix<T>::operator*(const std::vector<T>& rarr) const throw (std::runtime_error)
    {
        UINT s_len=rarr.size();
        if(s_len!=cols) throw std::runtime_error("the input vector does not match the dimension of the matrix!!!");
        Mmatrix<T> res_vec(rows,1,0.0);

        for(UINT i=0; i<rows; ++i)
         {
            for(UINT j=0; j<cols;++j) //cols also indicate the length of input vector
             {
                 res_vec(i,0)+=this->mat[i][j]*rarr[j]; //each vector element multiple with each row of the matrix
             }
         }

        return res_vec;
    }

    template<typename T>
    inline bool Mmatrix<T>::is_same_shape(const Mmatrix<T> & rmat) const
    {
        return ((this->rows==rmat.get_rows()) && (this->cols==rmat.get_cols()));
    }

    template<typename T>
    inline bool Mmatrix<T>::is_multiplable(const Mmatrix<T> & rmat) const
    {
        //[M,N]*[N,K]
        return ((this->cols==rmat.get_rows()));
    }

    template<typename T>
    inline void Mmatrix<T>::swap_(T& a, T& b)
    {
        T tmp=a;
        a=b;
        b=tmp;
    }

    template<typename T>
    UINT Mmatrix<T>::get_len() const
    {
        if(!is_square()) throw Eexception("this is not a square, operations illegal!!!");
        return this->rows;
    }

    template<typename T>
    UINT Mmatrix<T>::get_len(const Mmatrix<T> & rmat) const
    {
        if(!is_square(rmat)) throw Eexception("this is not a square, operations illegal!!!");
        return rmat.get_rows();
    }
};
