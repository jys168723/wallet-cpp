
#ifndef WALLETCPP_ENTRY_HPP_
#define WALLETCPP_ENTRY_HPP_

#include <string>
#include <cmath>

#ifdef __has_include
#  if __has_include(<boost/date_time/gregorian/gregorian.hpp>)
#    include <boost/date_time/gregorian/gregorian.hpp>
namespace calendar = boost::gregorian;
#  else
#    error "Missing <boost/date_time/gregorian/gregorian.hpp>"
#  endif
#  if __has_include(<yaml-cpp/yaml.h>)
#    include <yaml-cpp/yaml.h>
#  else
#    error "Missing <yaml-cpp/yaml.h>"
#  endif
#endif // __has_include

#include "command/command_options.hpp"

namespace Wallet
{
  class Entry final
  {
  public:
    // Constructor
    Entry() noexcept;

    // Copy Contructor
    Entry(const CommandOptions&) noexcept;
    Entry(const YAML::Node&) noexcept;

    // Parameter: ID
    std::string id{};

    // Parameter: Title
    std::string title{};

    // Parameter: Date
    void setDate(std::string);
    std::string getDateStr() const noexcept;

    // Parameter: Revenue
    void setRevenue(std::float_t) noexcept;
    std::float_t getRevenue() const noexcept;
    std::string getRevenueStr() const noexcept;

    // Parameter: Expense
    void setExpense(std::float_t) noexcept;
    std::float_t getExpense() const noexcept;
    std::string getExpenseStr() const noexcept;

    // Parameter: Balance
    std::float_t getBalance() const noexcept;
    std::string getBalanceStr() const noexcept;

    // Parameter: Category
    std::string category{};

    // Parameter: Comment
    std::string comment{};

    // Functions
    void generateRandomId() noexcept;
    std::string getFileName() const noexcept;

    // Conversion
    template<typename T>
    T as() const noexcept;

  private:
    // Variables
    calendar::date date{};
    std::float_t revenue{};
    std::float_t expense{};
    std::float_t balance{};

    // Functions
    void calcBalance() noexcept;
  };
} // Wallet Namespace

#endif // WALLETCPP_ENTRY_HPP_
