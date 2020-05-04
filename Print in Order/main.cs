using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
public class Foo
{
    List<ManualResetEvent> locks;
    int sem1;
    int sem2;
    int sem3;
    public Foo()
    {
        locks = new List<ManualResetEvent>();
        locks.Add(new ManualResetEvent(false));
        locks.Add(new ManualResetEvent(false));
        locks.Add(new ManualResetEvent(false));
        sem1 = 0;
        sem2 = 1;
        sem3 = 1;
    }

    public void First(Action printFirst)
    {
        Console.WriteLine("1");
        if (sem1 > 0)
        {
            locks[0].WaitOne();
        }
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem2 = 0;
        sem1 = 1;
        locks[1].Set();
    }

    public void Second(Action printSecond)
    {
        Console.WriteLine("2");

        if (sem2 > 0)
        {
            locks[1].WaitOne();
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem3 = 0;
        sem2 = 1;
        locks[2].Set();
    }

    public void Third(Action printThird)
    {
        Console.WriteLine("3");
        if (sem3 > 0)
        {
            locks[2].WaitOne();
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        sem1 = 0;
        sem3 = 1;
    }
}