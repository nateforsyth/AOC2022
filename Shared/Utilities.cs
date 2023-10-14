namespace Shared
{
    public class Utilities
    {
        public static Dictionary<int, List<int>> GetDayOneInput(string path)
        {
            Dictionary<int, List<int>> dayOneInput = new Dictionary<int, List<int>>();

            if (!string.IsNullOrEmpty(path))
            {
                using (var stream = File.Open(path, FileMode.Open))
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
                            if (dayOneInput.ContainsKey(currentElf))
                            {
                                dayOneInput[currentElf].Add(currentCal);
                            }
                            else
                            {
                                var carriedCals = new List<int>
                            {
                                currentCal
                            };

                                dayOneInput.Add(currentElf, carriedCals);
                            }
                        }
                    }
                }
            }            

            return dayOneInput;
        }
    }
}