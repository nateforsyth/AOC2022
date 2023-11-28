# AOC2022

Attempting [Advent of Code 2022](https://adventofcode.com/2022) while waiting for [Advent of Code 2023](https://adventofcode.com/2023).

Initial plans were to do AOC2022 in a language I know well, and then do it in two languages I want to learn to accelerate the learning process.

I've since abandoned this because I ran out of time prior to AOC2023 starting and I am trying to prioritise C++. Upon completion of AOC2023, I may return and redo all challenges in C# and Swift.


## C++

I wasn't aware how much plumbing was required to simply create a DLL for utility functionality, and I've thoroughly enjoyed learning how it all works which is partially why my AOC2023 attempt will be focused upon C++.

- [C++ > Day One](https://github.com/nateforsyth/AOC2022/tree/master/CPP/DayOne_CPP)
- [C++ > Day Two](https://github.com/nateforsyth/AOC2022/tree/master/CPP/DayTwo_CPP)
- [C++ > AOCUtilities](https://github.com/nateforsyth/AOC2022/tree/master/CPP/AOCUtilities)

[Microsoft Docs > Walkthrough: Create and use your own Dynamic Link Library (C++)](https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170)


### DLL

Properties > [TODO]


### Consuming project

- Properties > Configuration Properties > C/C++ > **General**
 - Additional Include Directories = [pathToDLLProjectFolder]
- Properties > Configuration Properties > Linker > **General**
 - Additional Library Directories = [pathToDLLBinFolder]
 - Link Library Directories = **No**
- Properties > Configuration Properties > Linker > **Input**
 - Additional Dependencies = [DLLName].lib


## C#

C# is my primary language in my day job. I'd intended to do the time-based challenge aspect of AOC using this language, and then use other languages to do the same thing to learn them. This has ended up not happening due to time consuming projects at work.

- [C# > Day One, 1](https://github.com/nateforsyth/AOC2022/tree/master/CS/DayOne/DayOne_1)
- [C# > Day One, 2](https://github.com/nateforsyth/AOC2022/tree/master/CS/DayOne/DayOne_2)
- [C# > Shared functionality](https://github.com/nateforsyth/AOC2022/tree/master/CS/Shared)


## Swift

I'm putting learning of Swift on hold for a while.

- [AOC2022_Swift](https://github.com/nateforsyth/AOC2022/tree/master/Swift/AOC2022_Swift)


# AOC2023

My [Advent of Code 2023](https://github.com/nateforsyth/AOC2023) repository.
