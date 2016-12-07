/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题2：实现Singleton模式
// 题目：设计一个类，我们只能生成该类的一个实例。

using System;

namespace _02_Singleton
{
    public sealed class Singleton1
    {
        private Singleton1()
        {
        }

        private static Singleton1 instance = null;
        public static Singleton1 Instance
        {
            get
            {
                if (instance == null)
                    instance = new Singleton1();

                return instance;
            }
        }
    }

    public sealed class Singleton2
    {
        private Singleton2()
        {
        }

        private static readonly object syncObj = new object();

        private static Singleton2 instance = null;
        public static Singleton2 Instance
        {
            get
            {
                lock (syncObj)
                {
                    if (instance == null)
                        instance = new Singleton2();
                }

                return instance;
            }
        }
    }

    public sealed class Singleton3
    {
        private Singleton3()
        {
        }

        private static object syncObj = new object();

        private static Singleton3 instance = null;
        public static Singleton3 Instance
        {
            get
            {
                if (instance == null)
                {
                    lock (syncObj)
                    {
                        if (instance == null)
                            instance = new Singleton3();
                    }
                }

                return instance;
            }
        }
    }

    public sealed class Singleton4
    {
        private Singleton4()
        {
            Console.WriteLine("An instance of Singleton4 is created.");
        }

        public static void Print()
        {
            Console.WriteLine("Singleton4 Print");
        }

        private static Singleton4 instance = new Singleton4();
        public static Singleton4 Instance
        {
            get
            {
                return instance;
            }
        }
    }

    public sealed class Singleton5
    {
        Singleton5()
        {
            Console.WriteLine("An instance of Singleton5 is created.");
        }

        public static void Print()
        {
            Console.WriteLine("Singleton5 Print");
        }

        public static Singleton5 Instance
        {
            get
            {
                return Nested.instance;
            }
        }

        class Nested
        {
            static Nested()
            {
            }

            internal static readonly Singleton5 instance = new Singleton5();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // 也会打印An instance of Singleton4 is created.
            Singleton4.Print();

            // 不会打印An instance of Singleton5 is created.
            Singleton5.Print();
        }
    }
}
