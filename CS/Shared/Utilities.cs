namespace Shared
{
    public class Utilities
    {
        public static Dictionary<int, List<int>> GetDayOneInput(string path)
        {
            var dayOneInput = new Dictionary<int, List<int>>();

            if (!string.IsNullOrEmpty(path))
            {
                using (var stream = File.Open(path, FileMode.Open))
                {
                    using var reader = new StreamReader(stream);
                    var line = string.Empty;
                    var currentEl = 0;

                    while ((line = reader.ReadLine()) != null)
                    {
                        if (!int.TryParse(line, out var currentLineIntVal)) // next el, init new List
                        {
                            currentEl++;
                        }
                        else
                        {
                            if (dayOneInput.ContainsKey(currentEl))
                            {
                                dayOneInput[currentEl].Add(currentLineIntVal);
                            }
                            else
                            {
                                var carried = new List<int>
                                {
                                    currentLineIntVal
                                };

                                dayOneInput.Add(currentEl, carried);
                            }
                        }
                    }
                }
            }            

            return dayOneInput;
        }
    }
}