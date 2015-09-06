//
// Created by feng on 8/27/15.
//

#include "common.h"
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

int main(){
    date_period dp (date(2015,8,1), days(30));
    auto di = day_iterator(dp.begin());
    while (di->day_of_week() != Sunday) {
        ++di;
    }
    cout << "sunday list:" << endl;
    for(auto wi = week_iterator(*di); *wi < dp.end(); ++wi){
        cout << to_simple_string(*wi) <<endl;
    }


    return 1;
}
