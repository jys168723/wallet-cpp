
#ifndef WALLETCPP_HTML_BASE_HTML_HPP_
#define WALLETCPP_HTML_BASE_HTML_HPP_

#include <string>

#ifdef __has_include
#  if __has_include(<filesystem>)
#    include <filesystem>
#  elif __has_include(<experimental/filesystem>)
#    include <experimental/filesystem>
#  elif __has_include(<boost/filesystem.hpp>)
#    include <boost/filesystem.hpp>
#  else
#    error "Missing <filesystem>"
#  endif
#  if __has_include(<ctml.hpp>)
#    include <ctml.hpp>
#  else
#    error "Missing <ctml.hpp>"
#  endif
#endif // __has_include

namespace Wallet { namespace Html
{
  class BaseHtml
  {
  public:
    explicit BaseHtml(boost::filesystem::path, boost::filesystem::path, std::string);
    const std::string title{};
    std::string getFullPath() const noexcept;
    std::string getBasePath() const noexcept;
    std::string getFileName() const noexcept;

  protected:
    CTML::Document getHtmlDoc(std::string = "./index.html") const noexcept;
    const boost::filesystem::path basePath{};
    const boost::filesystem::path fileName{};
  };
}} // Wallet::Html Namespace

#endif // WALLETCPP_HTML_BASE_HTML_HPP_
