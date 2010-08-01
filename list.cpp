/**
 * \file list.cpp
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
 
#include "list.h"

template < class type >
void list < type > :: insert ( type date, int position )
{
    if ( size == 0 )
        throw "You have to create an element before";
    if ( ( unsigned ) position > size )
        throw "Elem before does not exist";

    elem * ptr = first;

    while ( position-- )
        ptr = ptr -> next;

    elem * newElem = new elem;

    newElem -> value = date;
    newElem -> next = ptr -> next;
    ptr -> next = newElem;

    size++;
}

template < class type >
void list < type > :: insert_back ( type date )
{
    elem * newElem= new elem;

    newElem-> value = date;
    newElem -> next = first;

    first = newElem;

    size++;
}

template < class type >
void list < type > :: erase ( int position )
{
    if ( position >= size )
        throw "Element before does not exist";

    elem * ptr = first;

    if ( position == 0 )
    {
        first = ptr -> next;
        delete ptr;
    }
    else
    {
        for ( ; --position > 0 ; )
            ptr = ptr -> next;

        elem * tmp = ptr -> next -> next;
        delete ptr -> next;
        ptr -> next = tmp;
    }

    size--;
}

template < class type >
void list < type > :: operator<< ( type date )
{
    elem * number = new elem;

    number -> value = date;

    if ( size == 0 )
    {
        first = number;
        last = number;
    }
    else
    {
        last -> next = number;
        last = number;
    }

    size++;
}

template < class type >
void list < type > :: operator>> ( type &in )
{
    if( size == 0 )
        throw "List not initialized";

    in = last -> value;
}

template < class type >
type & list < type > :: operator[] ( unsigned int index )
{
    if ( index > size )
        throw "Elem before does not exist";

    elem * ptr = first;

    while ( index-- )
        ptr = ptr -> next;

    return ptr -> value;
}

/* End of list.cpp */