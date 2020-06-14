
#ifndef WALLETCPP_HTML_MONTH_HTML_HPP_
#define WALLETCPP_HTML_MONTH_HTML_HPP_

#include <string>

#include "base_html.hpp"
#include "class/container/entry_container.hpp"
#include "class/container/epic_container.hpp"

namespace Wallet::Html
{
  /**
   * Generates one month html file.
   */
  class MonthHtml final : public BaseHtml
  {
  public:
    //MonthHtml(fs::path, Container::MonthPair, Container::UnsortedEpics);
    MonthHtml(fs::path, Container::MonthPair, Container::UnsortedEpics, const Container::UnsortedEpicPtrs&);
    void generate() const;
    const std::string name{};

  private:
    const Container::MonthEntryContainer container{};
    const std::string year{};

    const Container::UnsortedEpics epics{}; // @deprecated
    const Container::UnsortedEpicPtrs& epicPtrs{};

    static std::string getMonthFile(Container::Month) noexcept;
    static std::string getMonthName(Container::Month) noexcept;
  };
} // Wallet::Html Namespace

#endif // WALLETCPP_HTML_MONTH_HTML_HPP_
