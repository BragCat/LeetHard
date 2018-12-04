class Solution {
public:
    string numberToWords(int num) {
    	if (num == 0) {
    		return "Zero";
    	}
    	string ans;
    	int cnt = 0;
    	while (num > 0) {
    		int subNum = num % 1000;
    		num /= 1000;
    		string s = convert2Words(subNum);
    		if (subNum > 0) {
    			if (ans != "") {
    				ans = " " + ans;
    			}
    			if (cnt == 0) {
    				ans = s;
    			} else if (cnt == 1) {
    				ans = s + " Thousand" + ans;
    			} else if (cnt == 2) {
    				ans = s + " Million" + ans;
    			} else if (cnt == 3) {
    				ans = s + " Billion" + ans;
    			}
    		}
    		++cnt;
    	}    
    	return ans;
    }

private:
	const string ONE[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
	const string TEN[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	const string TEN2TWENTY[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	string convert2Words(int num) {
		int first = num % 10;
		num /= 10;
		int second = num % 10;
		num /= 10;
		int third = num;
		string s;
		if (third > 0) {
			s += ONE[third] + " Hundred";
		} 
		if (second == 1) {
			if (s != "") {
				s += " ";
			}
			s += TEN2TWENTY[first];		
		} else {
			if (second > 0) {
				if (s != "") {
					s += " ";
				}
				s += TEN[second];	
			}
			if (first > 0) {
				if (s != "") {
					s += " ";
				}
				s += ONE[first];
			}
		}
		return s;
	}
};