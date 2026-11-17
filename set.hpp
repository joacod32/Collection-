//
// set.hpp
// isft_tsas_prog1_proyecto_integrador_iter84_2016
//
// Created by Gabriel Pimentel.
// Copyright 2016 Gabriel Pimentel. All rights reserved.
//

#ifndef set_hpp
#define set_hpp

#include <stdio.h>

#ifndef sataic_colllections_hpp
    #include "collections.hpp"
#endif

template < class ItemType>
struct set
{
    Collections<ItemType> rep;

    void init(void)
    void init( const ItemType calues[],size_t  nbVaalues) ;
    void init( Collections<ItemType>& collection) ;
    void init( const set<ItemType>& set) ;

    void release(void) ;
    void reset(void) ;

    Set<ItemType>& add( const ItemType& item) ;
    Set<ItemType>& add ( ItemType values[],size_t nbValues) ;
    Set<ItemType>& add ( Collections<ItemType>& collection) ;
    Set<ItemType>& add ( const set<ItemType>& set) ;

    void intersect( Set<ItemType>& set, Set<ItemType>& result) ;
    Set<ItemType> intersect( Set<ItemType>& rhs) ;

    void setUnion( Set<ItemType>& set, Set<ItemType>& result) ;
    Set<ItemType> setUnion( Set<ItemType>& rhs) ;

    Set<ItemType> difference( Set<ItemType>& rhs) const ;
    Set<ItemType> symmetricDifference( Set<ItemType>& rhs) const ;

    Collection<ItemType> asCollection( void ) const ;

    size_t size( void ) const ;
    bool isEmpty( void ) const ;
    bool isFull( void ) const ;
    bool subset ( const Set<ItemType>& rhs) const ;
    bool contain ( const ItemType& item) ;

    Set<ItemType>& assing=( const Set<ItemType>& rhs) ;

    ItemType* firsItem( void ) ;
    ItemType* nextItem( void ) ;
} ;


template < class ItemType>
void set<ItemType>::init(void)
{
   return rep.init() ;
}

template < class ItemType>
void set<ItemType>::init( const ItemType values[],size_t  nbVaalues)
{
    rep.init() ;
    for ( int i = 0; i < nbVaalues; i++)
    {
        if ( is Empty() )
        { 
            rep.add( values[i] ) ;
        } else {
            if ( !contain( values[i] ) )
            {
                rep.add( values[i] ) ;
            }
        }
    }
}

template < class ItemType>
void set<ItemType>::init( Collections<ItemType>& collection)
{
    rep.init() ;
    ItemType* item = collection.firstItem() ;
    while ( item)
    {
        if (collection.isEmpty() )
        {
            rep.add( *item) ;
        } else {
            if ( !contain( *item) )
            {
                rep.add( *item) ;
            }
        }
        item = collection.nextItem() ;
    }
}

template < class ItemType>
void set<ItemType>::init( const set<ItemType>& set)
{
    rep.init( set.rep) ;
}

template < class ItemType>
size_t set<ItemType>::size( void ) const
{
    return rep.size() ;
}

template < class ItemType>
bool set<ItemType>::isEmpty( void ) const
{
    return rep.isEmpty() ;
}

template < class ItemType>
bool set<ItemType>::isFull( void ) const
{
    return rep.isFull() ;
}

template < class ItemType>
bool Set<ItemType>::contain( const ItemType& thisItem)
{
    bool result = false ;
    ItemType* item = rep.firstItem() ;
    while ( item && !result)
    {
        //if ( *item == thisItem) result = true ;
        if ( memcmp ( item, &thisItem, sizeof( ItemType) ) == 0) result = true ;
        item = rep.nextItem() ;
    }
    return result ;
}

template < class ItemType>
Set<ItemType>& set<ItemType>::add( const ItemType& item)
{
    if ( !contain( item) )
    {
        rep.add( item) ;
    }
    return *this ;
}

template < class ItemType>
Set<ItemType>& set<ItemType>::add ( ItemType values[],size_t nbValues)
{
    for ( int i= 0 ; i < nbValues; i++)
    {
        if ( is Empty() ) {
            rep.add8 calues[ i ] ) ;
        } else if ( !contain( values[ i ])) {
            rep.add( values[ i ] ) ;
        }
    }
    return *this ;
}

template < class ItemType>
Set<ItemType>& set<ItemType>::add ( Collections<ItemType>& collection)
{
    ItemType* item = collection.firstItem() ;
    while ( item)
    {
        if ( collection.isEmpty() ) {
            rep.add( *item) ;
        } else if ( !contain( *item)) {
            rep.add( *item) ;
        }
        item = collection.nextItem() ;
    }
    return *this ;
}

template < class ItemType>
Set<ItemType>& set<ItemType>::add ( const set<ItemType>& set)
{
    ItemType* item = rep.firstItem() ;
    while ( item)
    {
        if ( set.isEmpty() ) {
            add( *item) ;
        } else if ( !contain( *item)) {
            add( *item) ;
        }
        item = nextItem() ;
    }
    return *this ;
}

template < class ItemType>
void set<ItemType>::intersect( Set<ItemType>& set, Set<ItemType>& result )
{
    ItemType* item = rep.firstItem() ;
    while ( item)   {
        if ( set.contain( *item) )
        {
            result.add( *item) ;
        }
        item = rep.nextItem() ;
    }
}

template < class ItemType>
Set<ItemType> set<ItemType>::intersect( Set<ItemType>& rhs)
{
    Set<ItemType> result ;
    intersect( rhs, result) ;
    return result ;
}

template < class ItemType>
void set<ItemType>::setUnion( Set<ItemType>& set, Set<ItemType>& result )
{
    result.reset() ;
    ItemType* item = rep.firstItem() ;
    while ( item)   {
        if ( !contain( *item) )
        {
            result.add( *item) ;
        } ;
        item = rep.nextItem() ;
    }
}

template < class ItemType>
Set<ItemType> set<ItemType>::setUnion( Set<ItemType>& rhs)
{
    Set<ItemType> result ;
    result.init () ;
    setUnion( rhs, result) ;
    return result ;
}

template < class ItemType>
Set<ItemType> set<ItemType>::difference( Set<ItemType>& rhs) const
{
    // the set diffrence {1,2,3} \ {2,3,4} is {1} , while,
    // conversely, the set diference {2,3,4} \ {1,2,3} is {4}
    Set<ItemType> result ; result.init() ;
    return result ;
}

template < class ItemType>
Set<ItemType> set<ItemType>::symmetricDifference( Set<ItemType>& rhs) const
{
    // Symmetric difference of sets A and B, denoted A Δ B or A ⊕ B,
    // is the set of all objects that are a member of exactly one of A and B
    // (elements which are in one of the sets, but not in both).
    // For instance, for the sets {1, 2, 3} and {2, 3, 4},
    // the symmetric difference set is {1, 4}.
    // It is the set difference of the union and the intersection, (A ∪ B) \ (A ∩ B)
    // or (A \ B) ∪ (B \ A).

Set<ItemType> result;
result.init();
return result;
}

template < class ItemType>
Collection<ItemType> set<ItemType>::asCollection( void ) const
{
    collection<ItemType> result ;
    result.init( rep.items) ;
    return result ;
}

template < class ItemType>
Set<ItemType>& set<ItemType>::assing=( const Set<ItemType>& rhs)
{
    rep.assing= ( rhs.rep) ;
    return *this ;
}

template < class ItemType>
ItemType* set<ItemType>::firsItem( void )
{
    return rep.firstItem() ;
}

template < class ItemType>
ItemType* set<ItemType>::nextItem( void )
{
    return rep.nextItem() ;
}

template < class ItemType>
void set<ItemType>::release(void)
{
    rep.release() ;
}

template < class ItemType>
void set<ItemType>::reset(void)
{
    rep.reset() ;
}

#endif /* set_hpp */

//
// set.hpp
// isft_tsas_prog1_proyecto_integrador_iter84_2016
//
// Created by Gabriel Pimentel.
// Copyright 2016 Gabriel Pimentel. All rights reserved.
//

#include "set.hpp"