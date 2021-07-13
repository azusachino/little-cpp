#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) cosnt
    {
        return n * price;
    }
    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class BulkQuote : public Quote
{
public:
    BulkQuote() = default;
    BulkQuote(const std::string &, double, std::size_t, double);
    double net_price(std::size_t) const override;

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};