/*
 Author: Kevin
 Date: 1st Feb, 2017
 Propose: exercise day1
 Environment: gcc 4.2
*/

#ifndef BOXX_H_INCLUDED
#define BOXX_H_INCLUDED

typedef unsigned int UINT;

namespace Object
{
    //class for simulating a box
    class BOXX
    {
    public:
        //create a box with three length
        BOXX(UINT len=1, UINT wid=1, UINT hi=1):length_(len),wide_(wid),high_(hi){}
        //create a cube
        BOXX(UINT len, bool isCube):length_(len),wide_(len),high_(len){}
        ~BOXX(){}
        //see if it's a cube
        bool is_cube() {return length_==wide_==high_; }
        //calculate the volume
        UINT box_volume(){return length_*wide_*high_;}
        //calculate its surface area
        UINT box_area() {return 2*(length_*wide_+wide_*high_+length_*high_);}
    private:
        UINT length_;
        UINT wide_;
        UINT high_;
    };
}


#endif // BOXX_H_INCLUDED
