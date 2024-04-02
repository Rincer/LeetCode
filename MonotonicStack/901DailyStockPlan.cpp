#include "..\Solution.h"

class StockSpanner {
    struct priceSpan
    {
        int price;
        int span;
    };
    vector<priceSpan> priceSpans;
public:
    StockSpanner() {

    }

    int next(int price) 
    {
        int i = priceSpans.size() - 1;
        priceSpan ps;
        ps.price = price;
        ps.span = 1;
        while(i >= 0)
        {
            if (priceSpans[i].price <= price)
            {
                ps.span += priceSpans[i].span;
                i -= priceSpans[i].span;
            }
            else
            {
                break;
            }
        }
        priceSpans.push_back(ps);
        return ps.span;
    }
};