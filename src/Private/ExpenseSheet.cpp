#include "ExpenseSheet.h"

#include <iomanip>
#include <ostream>

bool ExpenseSheet::Add(std::string_view label, double amount)
{
    Entry entry;
    entry.label = label;
    entry.amount = amount;

    bool canInsert = std::find(m_entries.begin(), m_entries.end(), entry) == m_entries.end();
    if(canInsert)
    {
        m_entries.push_back(std::move(entry));
    }

    return canInsert;
}

bool ExpenseSheet::Remove(std::string_view label)
{
    Entry entry;
    entry.label = label;
    auto element = std::find(m_entries.begin(), m_entries.end(), entry);
    if(element  != m_entries.end())
    {
        m_entries.erase(element);
        return true;
    }

    return false;
}

void ExpenseSheet::List(std::ostream& os) const
{
    size_t index = 0;
    
    for(const Entry& e: m_entries)
    {
        os << " "<< index++ << std::setprecision(2) << std::fixed << ".\t"<< e.label << " " << e.amount << std::endl;
    }
}

double ExpenseSheet::Calculate() const
{
    double total = 0;
    for(const Entry& e: m_entries)
    {
        total += e.amount;
    }
    
    return total;
}
