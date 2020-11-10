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

    void reverseString(string& str)
    {
        int n = str.length();

        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }

    void add (number a, number b) {
        string x = a.num; //accessing strings of objects
        string y = b.num;
        string temp;
        string answer = "";

        if (x.length() > y.length())
        {
            swap(x, y);//inbuit swap function
        }


        int n1 = x.length(), n2 = y.length();

        // Reverse both of strings
        reverseString(x);
        reverseString(y);

        
        //fundamental calculation rule
        int carry = 0;
        for (int i=0; i<n1; i++)
        {
            int sum = ((x[i]-'0')+(y[i]-'0')+carry);
            answer.push_back(sum%10 + '0');
            carry = sum/10;
        }
        
        for (int i=n1; i<n2; i++)
        {
            int sum = ((y[i]-'0')+carry);
            answer.push_back(sum%10 + '0');
            carry = sum/10;
        }

        
        if (carry)
            answer.push_back(carry+'0');

        // reverse resultant string
        reverse(answer.begin(), answer.end());
        num = answer;
       // cout <<answer<<endl;

    }

};

int main() {

    number n1,n2,n3;

    n1.get_num("2611"); //set value to object 1
    n2.get_num("911"); //set value to object 2

    n1.display_num(); //display object
    n2.display_num();

    n3.add(n1,n2); //add two numbers n1 and n2
    n3.display_num(); // display addition

    return 0;
}