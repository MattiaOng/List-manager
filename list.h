/**
 * \file list.h
 *
 *  Copyright (C) 2009-2010, Ongaro Mattia <moongaro at gmail.com>
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */
 
#ifndef LISTE_H
#define LISTE_H

template < class type >
class list
{
    class elem
    {
        public:
        elem ( )
        {
            next = 0;
        }

        ~elem ( )
        {
        }

        elem * next;
        type value;
    };

    public:
    list ( ) :
        size(0)
    {
    }

    ~list ( )
    {
        elem  * tmp;

        while ( first )
        {
            tmp = first;
            first = first -> next;
            delete tmp;
        }
    }

	// Insert back an element
    void insert_back ( type );
	// Insert an element
    void insert ( type, int );

	// Erase an element
    void erase ( int );

	// Return the first value
    type & firstValue ( )
    {
        return first->value;
    }

	// Return the last value
    type & lastVale ( )
    {
        return last->value;
    }

	// Get an element
    type & operator[] ( unsigned int );
	// Insert a new element
    void operator<< ( type );
	// Get the last element
    void operator>> ( type & );

	// Return the number of elements of the list
    unsigned lenght ( void )
    {
        return size;
    }

    private:
    elem * last;
    elem * first;

    unsigned int size;
};

#endif

/* End of list.h */