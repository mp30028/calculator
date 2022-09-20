#include "utils.h"
#include <algorithm>
#include <cctype>
using namespace std;

bool calc_utils::isSpace(unsigned char c) {
    return (
        c == ' ' ||
        c == '\n' ||
        c == '\r' ||
        c == '\t' ||
        c == '\v' ||
        c == '\f'
    );
}

string calc_utils::clean(string expr){
    expr.erase(remove_if(expr.begin(), expr.end(), isSpace), expr.end());
    return expr;
}

