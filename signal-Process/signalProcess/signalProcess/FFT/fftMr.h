
/*****************************************************************************
 *                                fftmr.h
 *introduction:
 *****************************************************************************/


#pragma once


#include<vector>
#include<complex>

namespace spl
{
	using std::vector;
	using std::complex;
    /**
     * two routines frequently used in FFT algorithm
     */
    bool    isPower2( int );
    int     fastLog2( int );


    /**
     * Radix based FFT class
     */
	template<typename T>
	class fftMr
	{

	public:

		fftMr();
		~fftMr();

        void fft( vector< complex<T> > &xn );
        void ifft( vector< complex<T> > &Xk );
		void fft( const vector<T> &xn, vector< complex<T> > &Xk );
        void ifft( const vector< complex<T> > &Xk, vector<T> &xn );

	private:

        void bitReverse( vector<int> &bitrev );
		void radix2( int nthpo, complex<T> *c0, complex<T> *c1 );
		void radix4( int nthpo, complex<T> *c0, complex<T> *c1,
                           complex<T> *c2, complex<T> *c3 );
		void radix8( int nxtlt, int nthpo, int length,
                     complex<T> *cc0, complex<T> *cc1,
                     complex<T> *cc2, complex<T> *cc3,
                     complex<T> *cc4, complex<T> *cc5,
                     complex<T> *cc6, complex<T> *cc7 );
		void dft( int direction, int n, complex<T> *b );
	};
	//	class FFTMR


	#include "fftMrImpl.h"

}
// namespace spl


