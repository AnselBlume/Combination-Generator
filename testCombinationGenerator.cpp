#include <iostream>
#include "CombinationGenerator.h"

void printVector( vector<int> vect );

int main()
{
    vector<int> set = { 3, 7, 1, 18, 19, 20 };

    cout << "Input set: \n";
    printVector( set );
    cout << endl;

    cout << "Testing 3-combinations\n";
    cout << "----------------------\n" << endl;

    CombinationGenerator * cg = new CombinationGenerator( set, 3 );

    for ( int i = 0; i < 21; i++ )
    {
        cout << "Next combination: ";
        printVector( cg->getNextCombination() );
        cout << endl;
    }


    cout << "Testing 0-combinations\n";
    cout << "----------------------\n" << endl;

    delete cg;

    cg = new CombinationGenerator( set, 0 );

    for ( int i = 0; i < 2; i++ )
    {
        cout << "Next Combination: ";
        printVector( cg->getNextCombination() );
        cout << endl;
    }

    cout << "Testing 1-combinations\n";
    cout << "----------------------\n" << endl;

    delete cg;

    cg = new CombinationGenerator( set, 1 );

    for ( int i = 0; i < 7; i++ )
    {
        cout << "Next combination: ";
        printVector( cg->getNextCombination() );
        cout << endl;
    }
  
    delete cg;
    return 0;
}

void printVector( vector<int> vect )
{
    // Prevent empty vector from breaking code
    if ( !vect.size() )
    {
        cout << "<>" << endl;
        return;
    }

    // Print vector in format <...,...,...>
    cout << "<";

    for ( int i = 0; i < vect.size() - 1; i++ )
        cout << vect[i] << ", ";

    cout << vect[vect.size() - 1] << ">" << endl;
}
