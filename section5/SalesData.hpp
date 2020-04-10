// Copyright (c) 2020 by Chrono

#ifndef _SALES_DATA_HPP
#define _SALES_DATA_HPP

#include "cpplang.hpp"

BEGIN_NAMESPACE(cpp_study)

// demo oop in C++
class SalesData final
{
public:
    using this_type = SalesData;

public:
    using string_type       = std::string;
    using string_view_type  = const std::string&;
    using uint_type         = unsigned int;
    using currency_type     = double;

    STATIC_ASSERT(sizeof(uint_type) >= 4);
    STATIC_ASSERT(sizeof(currency_type) >= 4);
public:
    SalesData(string_view_type id, uint_type s, currency_type r) noexcept
        : m_id(id), m_sold(s), m_revenue(r)
    {}

    SalesData(string_view_type id) noexcept
        : SalesData(id, 0, 0)
    {}

public:
#if 0
    SalesData(SalesData&& s) noexcept
        : m_id(std::move(s.m_id)),
          m_sold(std::move(s.m_sold)),
          m_revenue(std::move(s.m_revenue))
    {}

    SalesData& operator=(SalesData&& s) noexcept
    {
        m_id = std::move(s.m_id);
        m_sold = std::move(s.m_sold);
        m_revenue = std::move(s.m_revenue);

        return *this;
    }
#endif

    SalesData(SalesData&& s) = default;
    SalesData& operator=(SalesData&& s) = default;

    SalesData(const SalesData&) = default;
    SalesData& operator=(const SalesData&) = default;

    SalesData() = default;
   ~SalesData() = default;

private:
    string_type m_id        = "";
    uint_type   m_sold      = 0;
    uint_type   m_revenue   = 0;

public:
    void inc_sold(uint_type s) noexcept
    {
        m_sold += s;
    }

    void inc_revenue(currency_type r) noexcept
    {
        m_revenue += r;
    }
public:
    string_view_type id() const noexcept
    {
        return m_id;
    }

    uint_type sold() const noexcept
    {
        return m_sold;
    }

    currency_type revenue() const noexcept
    {
        return m_revenue;
    }

    CPP_DEPRECATED
    currency_type average() const
    {
        return m_revenue / m_sold;
    }
};

END_NAMESPACE(cpp_study)

#endif  //_SALES_DATA_HPP

