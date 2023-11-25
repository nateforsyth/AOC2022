using Shared;

internal class Program
{
    private static void Main(string[] args)
    {
        var start = DateTime.Now;
        string dayOnePath = "C:\\Repos\\AdventOfCode\\2022\\AOC2022\\CS\\Shared\\Input\\DayOne.txt";

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

        // very simple additions for Day 2 as the lifting was already done in Day 1
        var elfAlpha = sortedElves.ElementAt(0);
        var elfBeta = sortedElves.ElementAt(1);
        var elfGamma = sortedElves.ElementAt(2);

        var carriedTotal = elfAlpha.Value + elfBeta.Value + elfGamma.Value;

        var et = DateTime.Now - start;

        Console.WriteLine($"The strongest 3 elves are carrying a total of {carriedTotal} calories\r\n\tAlpha is carrying:\t{elfAlpha.Value}\r\n\tBeta is carrying:\t{elfBeta.Value}\r\n\tGamma is carrying:\t{elfGamma.Value}\r\n\r\nElapsed time: {et.TotalMilliseconds}ms");

        Console.Read();
    }
}