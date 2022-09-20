#include <iostream>
#include "parser.h"

using namespace std;

int main()
{
    cout << "Calculator" << endl << endl << endl;
    cout << "Enter the expression you want to evaluate: ";
    string expr;
    getline (cin, expr);
    Parser parser;
//    string cleanExpr =calc_utils::clean(expr);
//    cout << cleanExpr << endl << endl << endl;
    cout << parser.parse(expr) << endl << endl << endl;
    return 0;
}
