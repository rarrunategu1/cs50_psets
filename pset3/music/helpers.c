// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int beat;

    for (int i = 0, length = strlen(fraction); i < length; i++)
    {
        if (fraction[i] == 49)
        {
            beat = 1;
        }
        else if (fraction[i] == 50)
        {
            beat = 2;
        }
        else
        {
            beat = 4;
        }
    }
    return beat;
}

//Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
