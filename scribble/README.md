# scribble

This tool unreliably copies the standard input to the standard output. A proportion of bytes---by default 1%---are overwritten with a random byte.

Usage:

    make
    scribble < input > output
    scribble p < input > output

where p is a real number in the range [0-1] and specifies the probability of writing over an input byte.

