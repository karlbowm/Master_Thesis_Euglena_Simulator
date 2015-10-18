#include "Log.h"
#include <iostream>


Log::Log()
{
}


Log::~Log()
{
}

void Log::print(const std::string& msg, MsgSeverety severity)
{
    std::string sevStr;
    switch(severity)
    {
    case MsgSeverety::INFO:
        sevStr = "[INFO]:\t";
        break;
    case MsgSeverety::WARNING:
        sevStr = "[WARNING]:\t";
        break;
    case MsgSeverety::CRITICAL:
        sevStr = "[CRITICAL]:\t";
        break;
    case MsgSeverety::ERROR:
        sevStr = "[ERROR]:\t";
        break;
    }
    std::cout << sevStr << msg << std::endl;
}