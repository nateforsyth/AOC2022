//
//  main.swift
//  AOC2022_Swift
//
//  Created by Nathan Forsyth on 15/10/23.
//

import Foundation

let start = NSDate()

var importedStrings = [String]()
var input: [Int: [Int]] = [:]
var elvesTotals: [Int: Int] = [:]

let p = "/Users/nathanforsyth/Documents/Repos/AdventOfCode/2022/AOC2022/CS/Shared/Input/DayOne.txt"
let path = NSURL(fileURLWithPath: p)
if let lines = try? String(contentsOf: path as URL) {
    importedStrings = lines.components(separatedBy: "\n")
}

if importedStrings.isEmpty {
    importedStrings = []
}

input = getDayOneInput()

for elf in input {
    var runningTotal: Int = 0
    
    for carried in elf.value {
        runningTotal += carried
    }
    
    elvesTotals[elf.key] = runningTotal
}

var sortedInput = elvesTotals.sorted(by: {$0.value > $1.value})

extension Double {
    func round(to places: Int) -> Double {
        let div = pow(10.0, Double(places))
        return (self * div).rounded() / div
    }
}

func getDayOneInput() -> [Int: [Int]] {
    var dayOneInput: [Int: [Int]] = [:]
    var currentEl = 0
    for str in importedStrings {
        if str.isEmpty {
            currentEl += 1
        }
        else {
            let importedInt: Int = Int(str)!
            
            if dayOneInput.index(forKey: currentEl) != nil {
                var existingCarried = dayOneInput[currentEl]
                existingCarried?.append(importedInt)
                
                dayOneInput[currentEl] = existingCarried
            }
            else {
                let carried = [importedInt]
                
                dayOneInput[currentEl] = carried
            }
        }
    }
    
    return dayOneInput
}

let strongestElf0 = sortedInput[0]
let strongestElf1 = sortedInput[1]
let strongestElf2 = sortedInput[2]

let total: Int = strongestElf0.value + strongestElf1.value + strongestElf2.value

let etMs: Double = -(start.timeIntervalSinceNow * 1000).round(to: 2)

print("The highest number of calories carried: \(strongestElf0.value), is by Elf: \(strongestElf0.key)\r\n\r\nElapsed time: \(etMs)ms\r\n\r\nThe next two highest are:\r\n\tElf: \(strongestElf1.key) with \(strongestElf1.value)\r\n\tElf: \(strongestElf2.key) with \(strongestElf2.value)\r\n\r\n\tTotal: \(total)")
