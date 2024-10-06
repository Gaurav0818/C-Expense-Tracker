#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <string_view>

class InputArguments
{
public:
    InputArguments() = default;
    InputArguments(std::string_view line);

    InputArguments(const InputArguments&) = default;
    InputArguments& operator=(const InputArguments&) = default;

    InputArguments subset(size_t offset, size_t count = std::numeric_limits<size_t>::max());

    inline size_t count() const { return m_args.size(); }
    inline const std::string& operator[](size_t index) const { return m_args[index]; }
    
private:
    std::vector<std::string> m_args;
};
