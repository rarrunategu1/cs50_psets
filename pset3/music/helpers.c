// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //numerator of the beat
    int num = fraction[0] - '0';

    //denominator of the beat
    int denom = fraction[2] - '0';

    //will store 1 for 1/8 beat, 2 for 1/4 beat, 4 for 1/2 beat etc.
    int beat = ((8 / denom) * num);

    return beat;
}

//Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int freq;
    int semitone;

    //changes octave char into an integer
    int octave = note[strlen(note) - 1] - '0';

    //goes through the keys on a piano with A as the base equaling and counting the semitone based on where each letter is from A on the piano keys
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

    //checks for a b or a # in the note to either bring the semitone up on # or down on b
    if ((int)note[1] == 35)
    {
        semitone += 1.0;
    }
    else if ((int)note[1] == 98)
    {
        semitone -= 1.0;
    }

    //subtracts the octave 4(base octave) from the notes octave and multiplies the answer by 12 to increase the semitone by that much
    //if it's A4 it woulld add 0.0 to the semitone because its the base.  if it's A5 it would add 12.0 to the semitone which is 12 semitones going right from base
    if (octave >= 0  && octave <= 8)
    {
        semitone += (octave - 4.0) * 12.0;
    }

    //2,n/12 x 440 for frequency
    freq = round(pow(2.0, (semitone / 12.0)) * 440.00);
    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //if the character at position 0 is the terminator then it's a rest
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
