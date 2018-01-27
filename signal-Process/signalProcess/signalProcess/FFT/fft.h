/*****************************************************************************
 *                                    fft.h
 * introduction:
 *****************************************************************************/


#pragma once

#include<complex>
#include"fftMr.h"

namespace spl
{
    template<typename T>
    vector< complex<T> > fft( const vector<T>& );

    template<typename T>
    vector< complex<T> > fft( const vector< complex<T> >& );

    template<typename T>
    vector< complex<T> > ifft( const vector< complex<T> >& );

    template<typename T>
    vector< complex<T> > fftr2c( const vector<T>& );

    template<typename T>
    vector< complex<T> > fftc2c( const vector< complex<T> >& );

    template<typename T>
    vector<T> ifftc2r( const vector< complex<T> >& );

    template<typename T>
    vector< complex<T> > ifftc2c( const vector< complex<T> >& );


    #include"fftImpl.h"

}

