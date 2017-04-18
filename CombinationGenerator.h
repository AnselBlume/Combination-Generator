/***
 * Name:            Ansel Blume
 * UserID:          ablume
 * Date:            Nov 30 2016
 * Filename:        CombinationGenerator.h
 * Description:     Header file for a program that generates all of the
 *                  combinations of an array of integers one at a time.
 * Sources of help: None. 
 ***/

#ifndef COMBINATION_GEN_H
#define COMBINATION_GEN_H

#include <iostream>
#include <vector>

using namespace std;

class CombinationGenerator
{
private:
    // The set of numbers to choose from
    vector<int> set;

    // The number of elements to choose from the set
    int chooseNum;

    // Indices to generate the next combination
    vector<int> indices;

    // The number of combinations left to generate
    int toGenerate;

    // Whether this is the first combination being generated
    bool isFirst = true;

    // Sets the indices to the next combination to return
    void incrementIndices();

    // Makes all indices in the indices array be 1 + the previous
    // term, starting at index "index"
    void flattenIndices( int index );
public:
    // Initialization constructor
    CombinationGenerator( vector<int> set, int chooseNum );

    // Gets the next combination in the sequence
    vector<int> getNextCombination();

    bool hasNextCombination();
};

#endif
