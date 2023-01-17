#include "Arduino.h"
#include "Dates.h"

/*****
 *   Purpose: Determine if a given year is a leap year. Algotithm
 *   taken from C Programmer's Toolkit, by Jack Purdum
 *   Parameters:
 *     int years        the year to test
 *   Return:
 *     int              1 if the year is a leap yesr, 0 otherwise
*****/

int Dates::IsLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

/*****
*    Purpose: Determine the date for Easter for a given year.
*    Algorithm taken from Beginning Obkject Oriented Programming with
*    c#, by Jack Purdum
*    Parameters:
*      struct easter *myData    Pointer to an easter structure
*    Return value:
*      void
*****/

void Dates::GetEaster(Dates *myData) {
    int offset;
    int leap;
    int day;
    int temp1, temp2, total;

    myData->myEaster.easterStr[0] = '0';
    myData->myEaster.easterStr[2] = '/';
    myData->myEaster.easterStr[3] = '0';
    myData->myEaster.easterStr[10] = '\0';  // null character for end of string

    offset = myData->myEaster.year % 19;
    leap = myData->myEaster.year % 4;
    day = myData->myEaster.year % 7;
    temp1 = (19 * offset + 24) % 30;
    temp2 = (2 * leap + 4 * day + 6 * temp1 + 5) % 7;
    total = (22 + temp1 + temp2);

    if (total > 31)  {
        myData->myEaster.easterStr[1] = '4';  // must be in April
        myData->myEaster.month = 4;           // save the month
        day = total - 31;
    } else {
        myData->myEaster.easterStr[1] = '3';  // must be March
        myData->myEaster.month = 3;
        day = total;
    }
    myData->myEaster.day = day;   // save the day
    
    if (day < 10) {
        myData->myEaster.easterStr[4] = (char) (day + ASCIIZERO);
    } else {
        itoa(day, myData->myEaster.easterStr + 3, 10);  // convert day to ASCII
                                                        // and...
    }
    myData->myEaster.easterStr[5] = '/';   // always a '/' and overwrites null
                                           // from itoa()
    itoa(myData->myEaster.year, myData->myEaster.easterStr + 6, 10);
}

