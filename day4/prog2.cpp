#include <bits/stdc++.h>

using namespace std;


class number{
    string num; //private variable

public:
    void get_num(string x){
        num =x; //set value to num
    }
    void display_num(){
        cout << num<<endl; // for display
    }


    void mult(number u , number v) {

        string num1 = u.num;
        string num2 = v.num;
        string ans="";
        int len1 = num1.size();
        int len2 = num2.size();
        if (len1 == 0 || len2 == 0)
            ans= "0";

        // will keep the result number in vector
        // in reverse order
        vector<int> result(len1 + len2, 0);

        // Below two indexes are used to find positions
        // in result.
        int i_n1 = 0;
        int i_n2 = 0;

        // Go from right to left in num1
        for (int i=len1-1; i>=0; i--)
        {
            int carry = 0;
            int n1 = num1[i] - '0';


            i_n2 = 0;

            // Go from right to left in num2
            for (int j=len2-1; j>=0; j--)
            {
                // Take current digit of second number
                int n2 = num2[j] - '0';
                int sum = n1*n2 + result[i_n1 + i_n2] + carry;

                // Carry for next iteration
                carry = sum/10;

                // Store result
                result[i_n1 + i_n2] = sum % 10;

                i_n2++;
            }

            // store carry in next cell
            if (carry > 0)
                result[i_n1 + i_n2] += carry;

            // To shift position to left after every
            // multiplication of a digit in num1.
            i_n1++;
        }

        // ignore '0's from the right
        int i = result.size() - 1;
        while (i>=0 && result[i] == 0)
            i--;

        if (i == -1)
            ans = "0";

        // generate the result string

        while (i >= 0)
            ans += std::to_string(result[i--]);

        num = ans;
    }
};

int main() {

    number n1,n2,n3,n4;

    n1.get_num("12"); //set value to object 1
    n2.get_num("12"); //set value to object 2

    n1.display_num(); //display object
    n2.display_num();

    n3.mult(n1,n2);
    n3.display_num();


    return 0;
}