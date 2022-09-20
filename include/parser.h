#ifndef PARSER_H
#define PARSER_H
#include <string>


class Parser
{
    public:
        Parser();
        virtual ~Parser();
        int parse(std::string);

    protected:

    private:
        void nextToken();
        bool number();
        bool terminator();
        bool digit();
        bool digits();
        bool restDigits();
};

#endif // PARSER_H
