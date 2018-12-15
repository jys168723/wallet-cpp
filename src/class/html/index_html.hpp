
#ifndef WALLETCPP_HTML_INDEX_HTML_HPP_
#define WALLETCPP_HTML_INDEX_HTML_HPP_

#ifdef __has_include
#endif // __has_include

#include "base_html.hpp"

namespace Wallet::Html
{
  struct IndexHtmlRow
  {
    const std::string year{};
    const std::string revenue{};
    const std::string expense{};
    const std::string balance{};
    const std::string balanceSum{};
  };

  /**
   * Generates the main index.html file.
   */
  class IndexHtml final : public BaseHtml
  {
  public:
    explicit IndexHtml(fs::path);
    void addRow(IndexHtmlRow);
    void generate(IndexHtmlRow);

  private:
    CTML::Node tableBody{"tbody"};
  };
} // Wallet::Html Namespace

#endif // WALLETCPP_HTML_INDEX_HTML_HPP_