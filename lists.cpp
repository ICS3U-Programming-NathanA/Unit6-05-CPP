// Copyright (c) 2022 Nathan Araujo All rights reserved.
//
// Created by: Nathan Araujo
// Date: Dec 17, 2022
// This program calculates the average of marks

#include <iomanip>
#include <iostream>
#include <list>

// Calculate and return the average of the marksList in the list
double calcAverage(std::list<int> marks) {
    // set sum to 0
    float sum = 0;
    // set average to 0
    float average = 0;
    // for each loop to calculate the sum of all the odd numbers
    for (int counter : marks) {
        sum = sum + counter;
    }
    // sum divided by the length to find the average
    average = sum / marks.size();
    // return the average
    return average;
}

int main() {
    // declare markStr as a string
    std::string markStr;
    // Initialize an empty list to store the marks
    std::list<int> marksList;
    // Initialize a variable to store the current mark
    int mark = 0;
    // Keep asking the user to enter a mark until they enter -1
    do {
        std::cout << "Enter a mark between 0 and 100 (-1 to quit): ";
        // Get the mark from the user
        std::cin >> markStr;
        // Try catch to catch any invalid inputs
        try {
            mark = std::stof(markStr);
            // If the mark is not -1, add it to the list of marksList
            if (mark >= -1 && mark <= 100) {
                if (mark != -1) {
                    marksList.push_back(mark);
                } else {
                    // Calculate the average of the marksList
                    double average = calcAverage(marksList);
                    // Print the average
                    std::cout << "The average of the marks is " << std::fixed
                    << std::setprecision(2) << average << std::endl;
                }
            } else {
                // if they enter a number less then -1 or greater then 100
                std::cout << "You must enter a number between -1 and a 100\n";
                // break out of the loop
                break;
            }
        } catch (std::invalid_argument) {
        // If they entered a invalid input then display this
        std::cout
            << "You must enter a number."
            << std::endl;
        // break out of the loop
        break;
        }
    } while (mark != -1);
}
