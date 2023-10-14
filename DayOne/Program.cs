using System.Linq;

internal class Program
{
    private static async Task Main(string[] args)
    {
        Dictionary<int, List<int>> elves = new Dictionary<int, List<int>>();
        Dictionary<int, int> elvesTotals = new Dictionary<int, int>();

        // D:\Repos\AdventOfCode\2022\AOC2022\DayOne\Input_DayOne.txt
        using (var stream = File.Open("D:\\Repos\\AdventOfCode\\2022\\AOC2022\\DayOne\\Input_DayOne.txt", FileMode.Open))
        {
            using var reader = new StreamReader(stream);
            var line = string.Empty;
            var currentElf = 0;

            while ((line = reader.ReadLine()) != null)
            {
                if (!int.TryParse(line, out var currentCal)) // next elf, init new List
                {
                    currentElf++;
                }
                else
                {
                    if (elves.ContainsKey(currentElf))
                    {
                        elves[currentElf].Add(currentCal);
                    }
                    else
                    {
                        var carriedCals = new List<int>
                            {
                                currentCal
                            };

                        elves.Add(currentElf, carriedCals);
                    }
                }
            }
        }

        foreach (var elf in elves)
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

        await Console.Out.WriteLineAsync($"The highest number of calories carried is by Elf: {strongestElf.Key}, carrying: {strongestElf.Value}");

        Console.Read();
    }
}