// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{


    int num = fraction[0] - '0';
    int denom = fraction[2] - '0';
    int beat = ((8 / denom) * num);

    return beat;
}

//Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int freq;
    int semitone;
    int octave = note[strlen(note) - 1] - '0';

    switch (note[0])
    {
        case 'A':
        semitone = 0.0;
        break;

        case 'B':
        semitone = 2.0;
        break;

        case 'C':
        semitone = -9.0;
        break;

        case 'D':
        semitone = -7.0;
        break;

        case 'E':
        semitone = -5.0;
        break;

        case 'F':
        semitone = -4.0;
        break;

        case 'G':
        semitone = -2.0;
        break;

        default:
        return 0;
    }

        if ((int)note[1] == 35)
        {
            semitone += 1.0;
        }
        else if ((int)note[1] == 98)
        {
            semitone -= 1.0;
        }

    if (octave >= 0  && octave <= 8)
        {
            semitone += (octave - 4.0) * 12.0;
        }

    freq = round(pow(2.0, (semitone/12.0)) * 440.00);
    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
