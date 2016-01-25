//
// Created by feng on 8/11/15.
//

#include "common.h"


class Solution {
public:
	string getToken(size_t pos, const string& str, size_t& nextpos) {
		while (pos < str.length() && str[pos] == ' ')
			++pos;
		nextpos = pos;
		if (pos >= str.length())
			return "";
		if (str[nextpos] == '+' || str[nextpos] == '-' || str[nextpos] == '(' || str[nextpos] == ')') {
			++nextpos;
		}
		else {
			while (nextpos < str.length() && isdigit(str[nextpos]))
				++nextpos;
		}
		return str.substr(pos, nextpos - pos);
	}

    int calculate(string s) {
		map<string, int> isp{ { "(", 1 },{ "+", 3 },{ "-", 3 },{ ")", 5 },{ "$", 0 } };
		map<string, int> osp{ {"(", 5}, {"+", 2}, {"-", 2}, {")", 1 }, {"$", 0} };
        int val = 0;
		int pos = 0;
		stack<int> data;
		stack<string> ops;
		ops.push("$");
		int on = 0;
		size_t endpos = 0;
		auto ss = getToken(pos, s, endpos);
		auto process = [&](const string& ss) {
			if (isdigit(ss[0])) {
				auto n = atoi(ss.c_str());
				data.push(n);
				return;
			}
			else {
				while (!ops.empty() && isp[ops.top()] > osp[ss]) {
					auto op = ops.top(); ops.pop();
					if (op == "+" || op == "-") {
						auto b = data.top(); data.pop();
						auto a = data.top(); data.pop();
						if (op == "+")
							a += b;
						else
							a -= b;
						data.push(a);
						--on;
					}
				}
				if (!ops.empty() && isp[ops.top()] == osp[ss])
					ops.pop();
				else {
					ops.push(ss);
					if (ss == "+" || ss == "-") {
						++on;
						if (on > data.size())
							data.push(0);
					}
				}
			}
		};

		while (endpos < s.length() && ss != "") {
			process(ss);
			pos = endpos;
			ss = getToken(pos, s, endpos);
		}
		if (ss != "")
			process(ss);
		process("$");
        return data.top();
    }
};



int main(){
    cout << Solution().calculate("-2 + ((4+9) - 7)");
    return 1;
}