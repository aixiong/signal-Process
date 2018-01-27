
/*****************************************************************************
 *                                 fft-impl.h
 * introduction:
 *****************************************************************************/
#include<complex>
#include<vector>
using std::complex;
using std::vector;
 /**
 * Forward FFT algorithm.
 */
template<typename T>
inline vector< complex<T> > fft( const vector<T> &xn )
{
    return fftr2c( xn );
}

template<typename T>
inline vector< complex<T> > fft( const vector< complex<T> > &xn )
{
    return fftc2c( xn );
}


/**
 * Inverse FFT algorithm.
 */
template<typename T>
inline vector< complex<T> > ifft( const vector< complex<T> > &Xk )
{
    return ifftc2c( Xk );
}


/**
 * Real to complex DFT of 1D signal.
 */
template<typename T>
inline vector< complex<T> > fftr2c( const vector<T> &xn )
{
    vector< complex<T> > Xk( xn.size() );

    if( isPower2(xn.size())  )
    {
        fftMr<T> dft;
        dft.fft( xn, Xk );
    }
    else
    {
		throw "xn is not power of 2!";
    }

    return Xk;
}


/**
 * Complex to complex DFT of 1D signal.
 */
template<typename T>
inline vector< complex<T> > fftc2c( const vector< complex<T> > &xn )
{
    vector< complex<T> > Xk( xn.size() );

    if( isPower2(xn.size())  )
    {
        for( int i=0; i<xn.size(); ++i )
            Xk[i] = xn[i];
        fftMr<T> dft;
        dft.fft( Xk );
    }
    else
    {
		throw "xn is not power of 2!";
    }

    return Xk;
}


/**
 * Complex to real IDFT of 1D signal.
 */
template<typename T>
inline vector<T> ifftc2r( const vector< complex<T> > &Xk )
{
    vector<T> xn( Xk.size() );

    if( isPower2(xn.size())  )
    {
        vector< complex<T> > tmp( Xk );
        fftMr<T> dft;
        dft.ifft( tmp, xn );
    }
    else
    {
		throw "xn is not power of 2!";
    }

    return xn;
}


/**
 * Complex to complex IDFT of 1D signal.
 */
template<typename T>
inline vector< complex<T> > ifftc2c( const vector< complex<T> > &Xk )
{
    vector< complex<T> > xn( Xk.size() );

    if( isPower2(xn.size())  )
    {
        for( int i=0; i<xn.size(); ++i )
            xn[i] = Xk[i];
        fftMr<T> dft;
        dft.ifft( xn );
    }
    else
    {
		throw "xn is not power of 2!";
    }

    return xn;
}
