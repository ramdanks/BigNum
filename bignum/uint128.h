#pragma once
#include <cstdint>
#include <ostream>

#define NULL64 0x00
#define FULL64 0xFFFFFFFFFFFFFFFF

class uint128
{
public:
    uint128() = default;
    uint128( int const& other );
    uint128( double const& other );
    uint128( uint64_t const& other );
    uint128( uint128 const& other );

    uint128 operator=( int const& other );
    uint128 operator=( double const& other );
    uint128 operator=( uint64_t const& other );
    uint128 operator=( uint128 const& other );

    uint128 operator+( uint128 const& other );
    uint128 operator-( uint128 const& other );
    uint128 operator*( uint128 const& other );
    uint128 operator/( uint128 const& other );

    uint128 operator+=( uint128 const& other );
    uint128 operator-=( uint128 const& other );
    uint128 operator*=( uint128 const& other );
    uint128 operator/=( uint128 const& other );

    uint128 operator++();
    uint128 operator++( int );
    uint128 operator--();
    uint128 operator--( int );

    bool operator==( uint128 const& other );
    bool operator!=( uint128 const& other );

    char* c_str( int base = 10 ) const;
    friend std::ostream& operator<<( std::ostream& out, uint128 const& val );

private:
    void set( int const& other );
    void set( double const& other );
    void set( uint64_t const& other );
    void set( uint128 const& other );

    void mul( uint128 const& other );
    void div( uint128 const& other );
    void add( uint128 const& other );
    void sub( uint128 const& other );

    void inc();
    void dec();

    uint8_t m_buffer[16];
};