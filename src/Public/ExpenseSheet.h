#pragma once
#include <string>
#include <string_view>
#include <vector>

class ExpenseSheet
{
public:
    struct Entry
    {
        std::string label;
        double amount = 0;

        inline bool operator==(const Entry& rhs) const
        {
            return label == rhs.label;
        }
    };

public:
    ExpenseSheet() = default;
    ExpenseSheet(const ExpenseSheet&) = default;
    ExpenseSheet& operator=(const ExpenseSheet&) = default;

    bool Add(std::string_view label, double amount);
    bool Remove(std::string_view label);
    void List(std::ostream& os) const;
    double Calculate() const;
    
private:
    std::vector<Entry> m_entries;
};
