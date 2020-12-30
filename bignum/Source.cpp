#include "bignum.h"
#include <iostream>
#include <chrono>

struct Timer
{
	Timer( const char* msg ) : m_msg( msg ) { tic(); }
	~Timer()
	{
		auto dur = toc();
		std::cout << m_msg << ":" << dur << std::endl;
	}
	
	void tic()
	{
		t = std::chrono::steady_clock::now();
	}
	double toc()
	{
		auto e = std::chrono::steady_clock::now();
		std::chrono::duration<double> dur = e - t;
		return dur.count();
	}

private:
	std::chrono::steady_clock::time_point t;
	const char* m_msg;
};

uint128 add_uint128(size_t iter, uint64_t factor)
{
	Timer t( __FUNCSIG__ );
	uint128 val = 0;
	for ( auto i = 0; i < iter; i++ )
	{
		val += factor;
		std::cout << val << std::endl;
	}
	return val;
}

uint64_t add_uint64_t( size_t iter, uint64_t factor )
{
	Timer t( __FUNCSIG__ );
	uint64_t val = 0;
	for ( auto i = 0; i < iter; i++ )
	{
		val += factor;
		std::cout << val << std::endl;
	}
	return val;
}

int main( int argc, char* argv[] )
{
	uint8_t a = 160;
	uint8_t b = 192;
	uint8_t c = a + b;

	size_t i = atol( argv[1] );
	size_t f = atol( argv[2] );
	add_uint128( i, f );
	add_uint64_t( i, f );

	return 0;
}