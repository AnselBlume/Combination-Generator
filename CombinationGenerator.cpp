/***
 * Name:            Ansel Blume
 * UserID:          ablume
 * Date:            Nov 29 2016
 * Filename:        CombinationGenerator.cpp
 * Description:     Generates all of the combinations of an array of integers
 *                  one by one.
 * Sources of help: None.
 ***/

#include "CombinationGenerator.h"
#include <cassert>

#define CGen CombinationGenerator

CGen::CGen( vector<int> set, int chooseNum ) : set( set ), chooseNum( chooseNum )
{
    // Initialize indices array with starting indices
    for ( int i = 0; i < chooseNum; i++ )
        indices.push_back( i );

    // Calculate number of combinations
    toGenerate = 1;

    // Multiply by n! / (n - r)!
    for ( int i = set.size(); i > set.size() - chooseNum; i-- )
        toGenerate *= i;

    // Divide by r!
    for ( int i = 2; i <= chooseNum; i++ )
        toGenerate /= i;
}

/**
 * Gets the next combination of the set choose "chooseNum".
 *
 * Returns an empty vector if there are no more combinations to generate.
 */
vector<int> CGen::getNextCombination()
{
    // If there are no more combinations left to generate
    if ( !hasNextCombination() )
        return vector<int>();

    // Update the indices to generate the next combination after the first one
    if ( isFirst )
        isFirst = false;
    else
        incrementIndices(); 

    vector<int> combination;

    // Get the elements in the set at the new indices
    for ( int i = 0; i < indices.size(); i++ )
        combination.push_back( set[indices[i]] );
    
    toGenerate--; // We've generated the next combination

    return combination;
}

/**
 * Returns whether there are more combinations to generate.
 */
bool CGen::hasNextCombination()
{
    return toGenerate != 0;
}

/**
 * Modifies the indices to generate the next combination of the set.
 */
void CGen::incrementIndices()
{
    // Start at last index
    int inspectionIndex = indices.size() - 1;

    if ( indices[inspectionIndex] < set.size() - 1 )
    {
        indices[inspectionIndex]++;
        return;
    }

    while ( true )
    {
        // Move to the previous array index
        inspectionIndex--;

        // Method shouldn't be getting called if it is possible to generate
        // a negative index
        assert( inspectionIndex >= 0 ); 

        // If there is still room to increment inspectionIndex without colliding
        // with the next index in the array
        if ( indices[inspectionIndex] < indices[inspectionIndex + 1] - 1 )
        {
            indices[inspectionIndex]++;

            // Make all following numbers 1 + the previous
            flattenIndices( inspectionIndex );
            return;
        }
    }
}

/**
 * Makes all numbers after "index" in the indices array be one plus the
 * previous term.
 */
void CGen::flattenIndices( int index )
{
    // Make all numbers after index be one plus the previous
    for ( int i = index + 1; i < indices.size(); i++ )
        indices[i] = indices[i - 1] + 1;
}
