using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
public class FooBar
{

    private int n;
    List<ManualResetEvent> locks;
    int sem1;
    int sem2;
    public FooBar(int n)
    {
        this.n = n;
        locks = new List<ManualResetEvent>();
        locks.Add(new ManualResetEvent(false));
        locks.Add(new ManualResetEvent(false));
        sem1 = 0;
        sem2 = 1;
    }

    public void Foo(Action printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            if (sem1 > 0)
            {
                locks[0].Reset();
                locks[0].WaitOne();
            }
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            locks[1].Set();
            sem2 = 0;
            sem1 = 1;
        }
    }

    public void Bar(Action printBar)
    {

        for (int i = 0; i < n; i++)
        {
            if (sem2 > 0)
            {
                locks[0].Reset();
                locks[1].WaitOne();
            }
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            locks[0].Set();
            sem1 = 0;
            sem2 = 1;
        }
    }
}