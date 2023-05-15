// JA - it is good practice to insert comment about intended use, context, contributors, etc
//This program is intended for use for companies to calculate their financial ratios and categorize them
//Made by JA with contributions by Suhail Jadwat

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int dollars2rands(int x)
{
    return(x*20);
}

//Calculation is correct
double calcRatioPM(double revenue, double expenses)
{
    return((revenue-expenses)/revenue);
}

//Calculation is supposed to be (revenue - expense)/assets
double calcRatioRoA(double revenue, double expenses, double assets)
{
    return ((revenue - expenses) / assets);
}

//Calculation is supposed to be liabilities over assets
double calcRatioDE(double assets, double liabilities)
{
    return(liabilities / assets);
}


//The three functions to catergorise the data use char, rather than string
//So only the last letter is stored
//Also, the specs defined "average" to be less than 0.15 or less than 2 
//and unhealthy to be 0.15/0.2 and higher, so inequalities need to be adjusted
//Technically the words should be capitalised, so changed as well
string categorisePM(double ratio)
{
    string cat;
    if (ratio<0.08)
        cat= "Unhealthy";
    else if (ratio<0.15)
        cat= "Average";
    else
        cat= "Healthy";
    return(cat);
}

string categoriseRoA(double ratio)
{
    string cat;
    if (ratio < 0.08)
        cat = "Unhealthy";
    else if (ratio < 0.15)
        cat = "Average";
    else
        cat = "Healthy";
    return(cat);
}

string categoriseDE(double ratio)
{
    string cat;
    if (ratio < 1)
        cat = "Healthy";
    else if (ratio < 2)
        cat = "Average";
    else
        cat = "Unhealthy";
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string company_id;
    double revenue_USD, expenses, assets, liabilities, revenue_ZAR, ratio_PM, ratio_RoA, ratio_DE;
    //Confusing variables, so instead changed to match what category they are storing
    string catPM, catRoA, catDE;

    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);
    while (!f_in.eof())
    {
    	f_in >> company_id >> revenue_USD >> expenses >> assets >> liabilities;
        //revenue_ZAR call function with itself as the parameter
        //Wrong Variable, also a uninstantiated variable
        revenue_ZAR = dollars2rands(double(revenue_USD));
        //also called with wrong variable, we require ZAR not USD here
        ratio_PM = calcRatioPM(revenue_ZAR, expenses);
        catPM=categorisePM(ratio_PM);
        ratio_RoA = calcRatioRoA(revenue_ZAR, expenses, assets);;
        catRoA = categoriseRoA(ratio_RoA);
        ratio_DE = calcRatioDE(assets, liabilities);
        catDE = categoriseDE(ratio_DE);;

        //Formatting is missing some spaces between outputs
	    f_out << company_id << " " << ratio_PM << " " << catPM << " " << ratio_RoA << " " << catRoA << " " << ratio_DE << " " << catDE << endl;
    }
    f_in.close();
    f_out.close();
}

//Not actually sure how this code works, like it defines needing an integer and an array of characters (techincally a string), but two strings are inputted
//And it works??
int main(int argc, char *argv[])
{
    // JA - Need to check that 3 arguments were supplied upon execution
    try
    {
        process_data(argv[1], argv[2]);
    }
    catch (...)
    {
        cout << "Incorrect Format";
    }

}
