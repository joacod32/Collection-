//
// ansi_string.hpp
// isft_tsas_prog1_proyecto_integrador_iter84_2016
//
// Created by Gabriel Pimentel.
// Copyright 2016 Gabriel Pimentel. All rights reserved.
//

#ifndef ansi_string_hpp
#define ansi_string_hpp

#include <stdio.h>

#ifdef collections_hpp
    #include "collections.hpp"
#endif

struct AnsiString
{
    enum { NULL_CHAR = '\0', ANSI_STRING_DEFAULT_LENGTH = 256, CONTAINER_CAPACITY = ANSI_STRING_DEFAULT_LENGTH + 1} ;

    char items[ CONTAINER_CAPACITY] ;

    size_t first ;
    char* current ;
    size_t last ;
    unsigned long count ;

    bool initialized;
    //
    // private helpers functions
    //
    char* allocate( size_t requiredCapacity = CONTAINER_CAPACITY) ;
    void collectionAsString( Collection<char> collection, char* string) ;
    static void simple_layout( const char& item) ;
    void KMPBuildPartialMatchTable(const char* pattern, int partialMatch[] ) const ;
    //
    // initialize family functions ...
    //
    void init( void ) ;
    void init(chart ch) ;
    void init( const char* plasinString) ;
    void init( Collection<char>& collection) ;
    void init( const AnsiString& string) ;
    //
    // release and reset family functions ...
    //
    void release( void ) ;
    void reset( void ) ;
    //
    // concat family functions ...
    //
    AnsiString& concat( const char& item) ;
    AnsiString& concat( const char* plasinString) ;
    AnsiString& concat( Collection<char>& collection) ;
    AnsiString& concat( const AnsiString& string) ;
    //
    // insert family functions ...
    //
    AnsiString& insert( const char& item ) ;
    AnsiString& insertArPos( unsigned long pos, const char& item) ;
    //
    AnsiString& insert( const char* plasinString) ;
    AnsiString& insert( unsigned long pos, const char* plasinString) ;
    //
    
}