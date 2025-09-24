class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        //edge case
        if (numerator == 0) {
            return "0";
        }
        //if one of them is negative, result is negative
        //took long long to avoid overflow
        if ((long long)numerator * (long long)denominator < 0) {
            result += "-";
        }
        //map to store the position of the remainder and its corresponding index in the result string for "("
        unordered_map<int, int> mp;
        long long absNumerator = labs(numerator);
        long long absDenominator = labs(denominator);
        long long intdiv = absNumerator / absDenominator;
        result += to_string(intdiv);
        long long remain = absNumerator % absDenominator;
        if (remain == 0) {
            return result;
        }
        //if remainder is not zero,means there is a fractional part.so append "."
        result += ".";
       
        
        while (remain != 0) {
            if (mp.count(remain)) {
                result.insert(mp[remain], "(");
                result += ")";
                break;
            }
            mp[remain] = result.length();
            remain*=10; //1*10=10
            int digit=remain/absDenominator; //10/11=0,this is the next digit after decimal point
            result+=to_string(digit);//append this digit to result
            remain=remain % absDenominator; //10%11=10,this is the new remainder

        }

        return result;
    }
};