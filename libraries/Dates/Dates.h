/*
 * Dates.h - Library for finding is a year is a leap year and the
 * date for Easter in a given year.
 *
 * There should be no 'executable' code in a header file.
*/
#ifndef Dates_h
  #define Dates_h

  #include "Arduino.h"

  class Dates
{
    public:
    #define ASCIIZERO 48   // character for 0 in ASCII

    struct easter {
        int month;
        int day;
        int year;
        int leap;
        char easterStr[11];   // will use format MM/DD/YYYY (10 char + newline)
    };

    struct easter myEaster;

    // function prototypes
    int IsLeapYear(int year);
    void GetEaster(Dates *myEaster);
};
#endif
