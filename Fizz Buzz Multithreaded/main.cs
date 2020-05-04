using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;

public class FizzBuzz
{
    Mutex mNumber;
    Mutex mFizz;
    Mutex mBuzz;
    Mutex mFizzBuzz;
    bool bNumber;
    bool bFizz;
    bool bBuzz;
    bool bFizzBuzz;
    private int n;

    public FizzBuzz(int n)
    {
        this.n = n;
        mNumber = new Mutex(false);
        mFizz = new Mutex(false);
        mBuzz = new Mutex(false);
        mFizzBuzz = new Mutex(false);
    }

    // printFizz() outputs "fizz".
    public void Fizz(Action printFizz)
    {
        for (int loop = 3; loop <= n; loop += 3)
        {
            Console.WriteLine("Wait fizz");
            mFizz.WaitOne();
            Console.WriteLine("Print fizz");
            printFizz();
            if (bNumber)
            {
                mNumber.ReleaseMutex();
            }
        }
    }

    // printBuzzz() outputs "buzz".
    public void Buzz(Action printBuzz)
    {
        for (int loop = 5; loop <= n; loop += 5)
        {
            Console.WriteLine("Wait buzz");
            mBuzz.WaitOne();
            Console.WriteLine("Print buzz");
            printBuzz();
            if (bNumber)
            {
                mNumber.ReleaseMutex();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    public void Fizzbuzz(Action printFizzBuzz)
    {
        for (int loop = 15; loop <= n; loop += 15)
        {
            Console.WriteLine("Wait fizzbuzz");
            mFizzBuzz.WaitOne();
            Console.WriteLine("Print fizzbuzz");
            printFizzBuzz();

            if (bNumber)
            {
                mNumber.ReleaseMutex();
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    public void Number(Action<int> printNumber)
    {
        for (int loop = 1; loop <= n; loop++)
        {
            printNumber(loop);
            int r3 = loop % 3;
            int r5 = loop % 5;

            if (r3 == 0 && r5 == 0)
            {
                bNumber = true;
                mFizzBuzz.ReleaseMutex();
                mNumber.WaitOne();
            }
            else if (r3 == 0)
            {
                bNumber = true;
                mFizz.ReleaseMutex();
                mNumber.WaitOne();
            }
            else if (r5 == 0)
            {
                bNumber = true;
                mBuzz.ReleaseMutex();
                mNumber.WaitOne();
            }
        }
    }
}

