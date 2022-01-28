#include<iostream>
using namespace std;

// create the class
struct Date {

    //initialize variables
    int dd;
    int mm;
    int yy;
};

istream& operator>>(istream& in, Date& d)
{
    char i;
    in >> d.dd >> i >> d.mm >> i >> d.yy;
    return in;

}
/*
public:
    int operator-(Date);
    Date operator+(int);
    Date getTomorrow();
    bool operator< (Date);
    bool operator <= (Date);
    bool operator > (Date);
    bool operator >= (Date);
    bool operator == (Date);
*/

    //display the date
ostream& operator<<(ostream& out, Date& d)
    {
        cout << "Date:" << d.dd << "/" << d.mm << "/" << d.yy << endl;
    }

    // check to make sure input is correct format foe example feburary cannot have 30 days
void checkmonth (Date& d){
    if ((d.mm == 2) && (d.dd > 29))
    {
        cout << "wrong input!!!\n";
        cout << "\nenter the date again....\n";
    }
    if ((d.mm > 12) || (d.dd > 31))
    {
        cout << "wrong input!!!\n";
        cout << "\nenter the date again....\n";
    }
    if ((d.mm == 4 || d.mm == 6 || d.mm == 9 || d.mm == 11) && (d.dd > 30))
    {
        cout << "wrong input!!!\n";
        cout << "\nenter the date again....\n";
    }
    if ((d.yy % 4) != 0 && (d.mm == 2) && (d.dd > 28))
    {
        cout << "wrong input!!!\n";
        cout << "\nenter the date again....\n";
    }
}


Date operator+(Date a, Date b)
{
    Date dd3;
    while (nd > 365)
    {
        yy++;
        nd -= 365;
    }
    while (nd > 30)
    {
        if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        {
            nd -= 31;
            mm++;
        }
        else if (mm == 2)
        {
            nd -= 28;
            mm++;
        }
        else
        {
            nd -= 30;
            mm++;
        }
        if (mm > 12)
        {
            yy++;
            mm = 1;
        }
    }
    dd = dd + nd;
    if (dd > 30)
    {
        if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        {
            mm++;
            dd -= 30;
        }
        else if (mm == 2)
        {
            mm++;
            dd -= 28;
        }
        else if (dd > 31)
        {
            mm++;
            dd -= 31;
        }
        if (mm > 12)
        {
            yy++;
            mm = 1;
        }
    }
    dd3.mm = mm;
    dd3.dd = dd;
    dd3.yy = yy;
    cout << "new date is:";
    cout << dd << "-" << mm << "-" << yy << endl;
    return(dd3);
}

Date operator-(Date a, Date b)
{
    int i, nod1, nod2, nody, lc, no_of_days;
    nod1 = nod2 = lc = 0;
    for (i = 1; i < mm; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            nod1 += 31;
        else if (i == 2)
            nod1 += 28;
        else
            nod1 += 30;
    }
    nod1 += dd;
    for (i = 1; i < d2.mm; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            nod2 += 31;
        else if (i == 2)
            nod2 += 28;
        else
            nod2 += 30;
    }
    nod2 += d2.dd;
    nody = (yy - d2.yy) * 365;
    for (i = d2.yy; i < yy; i++)
        if ((i % 4) == 0)
            lc++;
    int y4 = yy - d2.yy;
    while (y4 > 400)
    {
        lc++;
        y4 -= 400;
    }
    if ((mm > 2) && (yy % 4) == 0)
        lc++;
    if ((d2.mm > 2) && (d2.yy % 4) == 0)
        lc--;
    no_of_days = nody + nod1 - nod2 + lc;
    if (no_of_days > 0)
    {
        cout << "total number of days between these dates is=";
        return(no_of_days);
    }
    else
        return(no_of_days);
}
void Date getTomorrow(Date& d)
{
    Date temp = *this;
    return temp + 1;
}

Date operator<(Date a, Date b)
{
    Date temp = *this;
    int res;
    res = temp - d2;
    if (res < 0)
        return true;
    else
        return false;
}
Date operator<=(Date a, Date b)
{
    Date temp = *this;
    int res;
    res = temp - d2;
    if (res <= 0)
        return true;
    else
        return false;
}
Date operator>(Date a, date b)
{
    Date temp = *this;
    int res;
    res = temp - d2;
    if (res > 0)
        return true;
    else
        return false;
}
Date operator>=(Date a, Date b)
{
    Date temp = *this;
    int res;
    res = temp - d2;
    if (res >= 0)
        return true;
    else
        return false;
}
Date operator==(Date a, Date b)
{
    Date temp = *this;
    int res;
    res = temp - d2;
    if (res == 0)
        return true;
    else
        return false;
}