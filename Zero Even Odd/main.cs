using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;

public class ZeroEvenOdd
{
    List<ManualResetEvent> locks;
    volatile int next;
    int sem0;
    private int n;

    public ZeroEvenOdd(int n)
    {
        this.n = n;
        locks = new List<ManualResetEvent>();
        locks.Add(new ManualResetEvent(false));
        locks.Add(new ManualResetEvent(false));
        locks.Add(new ManualResetEvent(false));
        next = 1;
        sem0 = 1;
    }

    /*
    Step 1: odd lock itself and release zero
    Step 2: zero release odd
    Step 3: odd release even
    */
    // printNumber(x) outputs "x", where x is an integer.
    public void Zero(Action<int> printNumber)
    {
        for (int loop = 1; loop <= n; loop++)
        {
            if (sem0 == 1)
            {
                sem0 = 0;
                locks[0].Reset();
                locks[0].WaitOne();
            }

            Console.WriteLine("0");
            printNumber(0);
            Console.WriteLine("Zero release " + next);
            locks[next].Set();
            sem0 = 1;
        }

    }

    public void Even(Action<int> printNumber)
    {
        for (int loop = 2; loop <= n; loop = loop + 2)
        {
            if (next == 1)
            {
                locks[2].Reset();
                locks[2].WaitOne();
            }

            Console.WriteLine("Even Wait for zero");

            locks[2].Reset();
            if (sem0 == 0)
                locks[0].Set();
            else
                sem0 = 0;
            locks[2].WaitOne();
            Console.WriteLine("Print value even");

            printNumber(loop);
            next = 1;
            locks[1].Set();
            Console.WriteLine("Release 1");
            if (n - loop > 1)
            {

            }

        }

    }

    public void Odd(Action<int> printNumber)
    {
        for (int loop = 1; loop <= n; loop = loop + 2)
        {
            if (next == 2)
            {
                locks[1].Reset();
                locks[1].WaitOne();
            }
            Console.WriteLine("1");



            Console.WriteLine("Odd Wait for zero");

            locks[1].Reset();
            if (sem0 == 0)
                locks[0].Set();
            else
                sem0 = 0;
            locks[1].WaitOne();

            Console.WriteLine("Print value odd");
            printNumber(loop);
            next = 2;
            locks[2].Set();
            Console.WriteLine("Release 2");
            if (n - loop > 1)
            {

            }

        }

    }
}