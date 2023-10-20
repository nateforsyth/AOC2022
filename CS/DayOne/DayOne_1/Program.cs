using Shared;
using System.Linq;

internal class Program
{
    private static void Main(string[] args)
    {
        var start = DateTime.Now;
        string dayOnePath = "D:\\Repos\\AdventOfCode\\2022\\AOC2022\\CS\\Shared\\Input\\DayOne.txt";

        Dictionary<int, int> elvesTotals = new Dictionary<int, int>();
        foreach (var elf in Utilities.GetDayOneInput(dayOnePath))
        {
            var runningTotal = 0;

            foreach (var cal in elf.Value)
            {
                runningTotal += cal;
            }

            elvesTotals.Add(elf.Key, runningTotal);
        }

        var sortedElves = elvesTotals.OrderByDescending((el) =>
        {
            return el.Value;
        });

        var strongestElf = sortedElves.ElementAt(0);

        var et = DateTime.Now - start;

        Console.WriteLine($"The highest number of calories carried: {strongestElf.Value}, is by Elf: {strongestElf.Key}\r\n\r\nElapsed time: {et.TotalMilliseconds}ms");

        Console.Read();
    }
}