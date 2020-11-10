#include <iostream>

using namespace std;

// imperial distance units class
class Distance{
    private:
     // all imperial units as private data
    int  thou, yard, chain, furlong, mile, league;
    int feet;
    int inches;

    public:
    void set_distance(){
        // set distance function to get input
        cout << "\nEnter league: "; 
        cin >> league;

        // take league

        cout << "\nEnter mile: "; 
        cin >> mile;
        //mile
        //......

        cout << "\nEnter furlong: "; 
        cin >> furlong;

        cout << "\nEnter chain: "; 
        cin >> chain;

        cout << "\nEnter yard: "; 
        cin >> yard;

        cout << "\nEnter feet: "; 
        cin >> feet;

        cout << "\nEnter inches: "; 
        cin >> inches;

        cout << "\nEnter thou: "; 
        cin >> thou;
        // input thou

    }

    void conversion(){
        //conversion
        if(thou>=1000){
            int temp;
            temp = thou % 1000;//remaining thou
            inches +=thou/1000; // thou/1000 increase inches
            thou = temp;
        }
        // similar all conversuion for other units
        if(inches>=12){
            int temp = inches%12;
            feet +=inches/12;
            inches = temp;
        }
        if( feet >=3){
            int temp = feet%3;
            yard+= feet/3;
            feet = temp;

        }
        if(yard>=22){
            int temp = yard % 22;
            chain+=yard/22;
            yard = temp;

        }
        if(chain>=10){
            int temp = chain % 10;
            furlong  +=chain/10;
            chain = temp;

        }
        if (furlong>=8){
            int temp = furlong % 8;
            mile +=furlong/8;
            furlong = temp;

        }
        if(mile>=3){
            int temp = mile % 3;
            league+=mile/3;
            mile = temp;

        }

        cout <<"\n Conversion is:\n";
        //final output

        //print only those units which are non zero
        if(league!=0){
            cout << league << " league  ";
        }
        if(mile!=0){
            cout << mile << " mile  ";
        }
        if(furlong!=0){
            cout << furlong << " furlong  ";
        }
        if(chain!=0){
            cout << chain << " chain  ";
        }
        if(yard!=0){
            cout << yard << " yard  ";
        }
        if(feet!=0){
            cout << feet << " feet  ";
        }
        if(inches!=0){
            cout << inches << " inches  ";
        }
        if(thou!=0){
            cout << thou << " thou  ";
        }
    }
};


int main(){

    Distance d1; //distance object

    d1.set_distance();//call set distance
    d1.conversion();//optimal conversion
    

}