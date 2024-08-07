class Solution {

private:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                           "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20)
            return ones[num] + " ";
        else if (num < 100)
            return tens[num / 10] + " " + helper(num % 10);
        else
            return ones[num / 100] + " Hundred " + helper(num % 100);
    }
public:
    string numberToWords(int num) {
        if (num==0)return "Zero";
        int i = 0;
        string words = "";

        while (num > 0) {
            if (num % 1000 != 0)
                words = helper(num % 1000) + thousands[i] + " " + words;
            num /= 1000;
            i++;
        }

        // Remove trailing space and return
        while (!words.empty() && words.back() == ' ')
            words.pop_back();

        return words;


        
    }
};