#include "parser.h"
#include "utils.h"
#define END_OF_EXPR '\0'
#define PLUS_SIGN '+'
#define MINUS_SIGN '-'
using namespace std;

string expr;
int lengthOfExpr = 0;
int nextTokenPosition = 0;
char nextChar;
string value;

int Parser::parse(std::string inExpr){
    expr = calc_utils::clean(inExpr);
    lengthOfExpr = expr.size();
    nextToken();
    if (number()){
        return stoi(value);
    }else{
        return 0;
    }
}

void Parser::nextToken(){
    if (nextTokenPosition >= lengthOfExpr){
        nextChar = END_OF_EXPR;
    }else{
        nextChar = expr.at(nextTokenPosition);
    }
    nextTokenPosition++;
}

//number -> {unsigned_number | signed_number} + terminator

//unsigned_number --> digits
//signed_number --> sign + digits
//sign --> PLUS | MINUS
//digits --> DIGIT | rest_digits
//rest_digits --> {DIGIT + rest_digits} | terminator
//DIGIT           --> "0"| .... |"9"

bool Parser::number(){
    return ((unsignedNumber() || signedNumber()) && terminator)
}

bool Parser::unsignedNumber(){
    return (digits());
}

bool Parser::signedNumber(){
    return (sign() && digits())
}

bool Parser::sign(){
    return (plusSign() || minusSign() )
}

bool Parser::plusSign(){
    return (checkSign(PLUS_SIGN));
}

bool Parser::minusSign(){
    return (checkSign(MINUS_SIGN));
}

bool Parser::checkSign(char signToCheckFor){
    if(nextChar == signToCheckFor){
        value.push_back(nextChar);
        nextToken();
        return true;
    }else{
        return false;
    }
}



bool Parser::terminator(){
    return (nextChar == END_OF_EXPR);
}

bool Parser::digits(){
    return (digit() && restDigits());
}

bool Parser::restDigits(){
    return ((digit() && restDigits()) || terminator());
}

bool Parser::digit(){
    if (isdigit(nextChar)){
        value.push_back(nextChar);
        nextToken();
        return true;
    }else{
        return false;
    }
}

Parser::Parser()
{
    //ctor
}

Parser::~Parser()
{
    //dtor
}


