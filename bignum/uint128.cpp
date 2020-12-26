#include "uint128.h"

uint128::uint128( int const& other )
{
    set( other );
}

uint128::uint128( double const& other )
{
    set( other );
}

uint128::uint128( uint64_t const& other )
{
    set( other );
}

uint128::uint128( uint128 const& other )
{
    set( other );
}

uint128 uint128::operator=( int const& other )
{
    set( other );
    return *this;
}

uint128 uint128::operator=( double const& other )
{
    set( other );
    return *this;
}

uint128 uint128::operator=( uint64_t const& other )
{
    set( other );
    return *this;
}

uint128 uint128::operator=( uint128 const& other )
{
    set( other );
    return *this;
}

uint128 uint128::operator+( uint128 const& other )
{
    uint128 t = *this;
    t.add( other );
    return t;
}

uint128 uint128::operator-( uint128 const& other )
{
    uint128 t = *this;
    t.sub( other );
    return t;
}

uint128 uint128::operator*( uint128 const& other )
{
    uint128 t = *this;
    t.mul( other );
    return t;
}

uint128 uint128::operator/( uint128 const& other )
{
    uint128 t = *this;
    t.div( other );
    return t;
}

uint128 uint128::operator+=( uint128 const& other )
{
    add( other );
    return *this;
}

uint128 uint128::operator-=( uint128 const& other )
{
    sub( other );
    return *this;
}

uint128 uint128::operator*=( uint128 const& other )
{
    mul( other );
    return *this;
}

uint128 uint128::operator/=( uint128 const& other )
{
    div( other );
    return *this;
}

uint128 uint128::operator++()
{
    inc();
    return *this;
}

uint128 uint128::operator++( int )
{
    inc();
    return *this;
}

uint128 uint128::operator--()
{
    dec();
    return *this;
}

uint128 uint128::operator--( int )
{
    dec();
    return *this;
}

bool uint128::operator==( uint128 const& other )
{
    return memcmp( m_buffer, other.m_buffer, sizeof( uint128::m_buffer ) ) == 0;
}

bool uint128::operator!=( uint128 const& other )
{
    return memcmp( m_buffer, other.m_buffer, sizeof( uint128::m_buffer ) ) != 0;
}

char* uint128::c_str( int base ) const
{
    return nullptr;
}

void uint128::set( int const& other )
{
    auto setter = reinterpret_cast<uint64_t*>( m_buffer );
    if ( other < 0 )
    {
        setter[0] = FULL64;
        setter[1] = FULL64;
    }
    else
    {
        setter[0] = NULL64;
        setter[1] = NULL64;
    }
    auto thisval = reinterpret_cast<int*>( m_buffer );
    thisval[0] = other;
}

void uint128::set( double const& other )
{
    auto setter = reinterpret_cast<uint64_t*>( m_buffer );
    if ( other < 0 )
    {
        setter[0] = FULL64;
        setter[1] = FULL64;
    }
    else
    {
        setter[0] = NULL64;
        setter[1] = NULL64;
    }
    auto thisval = reinterpret_cast<uint64_t*>( m_buffer );
    thisval[0] = static_cast<uint64_t>( other );
}

void uint128::set( uint64_t const& other )
{
    auto thisval = reinterpret_cast<uint64_t*>( m_buffer );
    thisval[0] = other;
    thisval[1] = NULL64;
}

void uint128::set( uint128 const& other )
{
    memcpy_s( m_buffer, sizeof( uint128::m_buffer ), other.m_buffer, sizeof( uint128::m_buffer ) );
}

void uint128::mul( uint128 const& other )
{

}

void uint128::div( uint128 const& other )
{
}

void uint128::add( uint128 const& other )
{
}

void uint128::sub( uint128 const& other )
{
    auto thisval = reinterpret_cast<uint64_t*>( m_buffer );
    
}

void uint128::inc()
{
    auto thisval = reinterpret_cast<uint64_t*>( m_buffer );
    if ( thisval[0] == FULL64 )
    {
        thisval[0] = NULL64;
        if ( thisval[1] == FULL64 ) thisval[1] = NULL64;
        else                        ++thisval[1];
    }
    else
    {
        ++thisval[0];
    }
}

void uint128::dec()
{
    auto thisval = reinterpret_cast<uint64_t*>( m_buffer );
    if ( thisval[0] == NULL64 )
    {
        thisval[0] = FULL64;
        if ( thisval[1] == NULL64 ) thisval[1] = FULL64;
        else                        --thisval[1];
    }
    else
    {
        --thisval[0];
    }
}

std::ostream& operator<<( std::ostream& out, uint128 const& val )
{
    auto thisval = (uint64_t*) val.m_buffer;
    if ( thisval[1] == 0x00 ) return out << thisval[0];
    return out << thisval[1];
}
