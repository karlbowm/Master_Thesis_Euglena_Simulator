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

    void print(const std::string& msg, MsgSeverety severity = MsgSeverety::INFO);

   
};

