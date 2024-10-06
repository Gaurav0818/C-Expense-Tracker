#include "InputArguments.h"

InputArguments::InputArguments(std::string_view line)
{
    enum class State
    {
        ReadyForArgs,
        ReadingArg
    }state = State::ReadyForArgs;

    std::stringstream ss;
    for(char c: line)
    {
        switch(state)
        {
        case State::ReadyForArgs:
            switch (c) 
            {
                case ' ':
                    break;
                default:
                    ss<<c;
                    state = State::ReadingArg;
                    break;
            }
            break;
        case State::ReadingArg:
            switch (c) 
            {
                case ' ':
                    m_args.push_back(ss.str());
                    ss.str("");
                    state = State::ReadyForArgs;
                    break;
                default:
                    ss<<c;
                    break;
            }
            break;
        }
    }
    if(state == State::ReadingArg)
    {
        m_args.push_back(ss.str());
    }
}

InputArguments InputArguments::subset(size_t offset, size_t count)
{
    InputArguments subset;

    auto it = m_args.begin() + offset;

    while(count-- && it != m_args.end())
    {
        subset.m_args.push_back(*(it++));
    }
    
    return subset;
}
