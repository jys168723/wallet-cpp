
#ifndef WALLETCPP_HTML_HTML_GENERATOR_HPP_
#define WALLETCPP_HTML_HTML_GENERATOR_HPP_

#include <string>

#include "fs.hpp"
#include "class/trait/logable.hpp"
#include "class/container/entry_container.hpp"

namespace Wallet::Html
{
  using Wallet::Trait::Logable;
  using Wallet::Container::EntryContainer;

  class HtmlGenerator final : public Logable
  {
  public:
    HtmlGenerator(fs::path, fs::path, EntryContainer);
    void generate() const;

  private:
    // Variables
    const fs::path yearPath{};
    const fs::path basePath{};
    const fs::path tmpPath{};
    const EntryContainer container{};

    // Methods
    void setup() const noexcept;
  };
} // Wallet::Html Namespace

#endif // WALLETCPP_HTML_HTML_GENERATOR_HPP_
