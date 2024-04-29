#pragma once

# include <iostream>

template <typename T> 
void iter(char* address, int len, void (*fonction)(T))
{
    for(int i = 0; i < len; i++)
    {
        fonction(address[i]);
    }
}
