#pragma once
#include <strstream>
#include <sstream>


enum class MsgSeverety
{
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Log
{

public:
    Log();
    ~Log();

    static void print(const std::string& msg, MsgSeverety severity = MsgSeverety::INFO);

   
};

