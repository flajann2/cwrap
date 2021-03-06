#pragma once
//
//  integer_sequence.h
//  cwrap
//
//  Created by Lisa Lippincott on 8/30/14.
//  Released into the public domain by Lisa Lippincott, 2014.
//


#include <cstddef>
#include <type_traits>
#include <tuple>

/*
    This is roughly the template std::integer_sequence from C++14.
    Since cwrap is currently written to C++11, it needs its own.
*/

namespace cwrap
   {
    namespace stdish
       {
        template < class T, T... indices > struct integer_sequence
           {
            using value_type = T;
            static constexpr std::size_t size()     { return sizeof...(indices); }
           };
        
        template < class T, T begin, T end, T... tail >
        struct integer_range_with_tail
           {
            using type = typename integer_range_with_tail< typename std::enable_if< begin <= end, T >::type, begin, end-1, end-1, tail... >::type;
           };
        
        template < class T, T begin, T... tail >
        struct integer_range_with_tail< T, begin, begin, tail... >
           {
            using type = integer_sequence< T, tail... >;
           };

        template < class T, T n > using make_integer_sequence = typename integer_range_with_tail< T, 0, n >::type;
        
        
        
        template < std::size_t... indices > using index_sequence        = integer_sequence< std::size_t, indices... >;
        template < std::size_t n >          using make_index_sequence   = make_integer_sequence< std::size_t, n >;
        template < class... T >             using index_sequence_for    = make_index_sequence< sizeof...(T) >;



        template < class Callable, class ParameterTuple, std::size_t... indices >
        auto apply_impl( Callable&& toCall,
                         ParameterTuple&& parameters,
                         index_sequence< indices... > )
        -> decltype( std::forward< Callable >( toCall )( std::get<indices>( std::forward< ParameterTuple >( parameters ) )... ) )
           {
            return   std::forward< Callable >( toCall )( std::get<indices>( std::forward< ParameterTuple >( parameters ) )... );
           }

        template < class Callable, class ParameterTuple >
        auto apply( Callable&& toCall,
                    ParameterTuple&& parameters )
        -> decltype( stdish::apply_impl( std::forward<Callable>( toCall ),
                                         std::forward< ParameterTuple >( parameters ),
                                         make_index_sequence< std::tuple_size< ParameterTuple >::value >() ) )
           {
            return   stdish::apply_impl( std::forward<Callable>( toCall ),
                                         std::forward< ParameterTuple >( parameters ),
                                         make_index_sequence< std::tuple_size< ParameterTuple >::value >() );
           }
       }
   }

