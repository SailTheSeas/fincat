SUHAIL JADWAT
# Description for Lab Test

This code takes as input a data file with the revenue, expenses, assets and liabilities of companies and computes finalcial ratios and categorization for that company. 

The three ratios to be calculated are as follows:
* Profit margin ratio = (revenue - expenses) / revenue
* Return on Assets ratio = (revenue - expenses) / assets
* Debt-to-Equity ratio = liabilities/assets 

The program should then categorize the financial ratios according to these rules for the Profit margin ratio and the Return on Assets ratio:
* Less than 0.08: unhealty
* Not less than 0.08 but less than 0.15: average 
* 0.15 or over: healthy

The program should also categorize the Debt-to-Equity ratio as follows:
* Less than 1: healty
* Not less than 1 but less than 2: average 
* 2 or over: unhealthy

The complexity is that these companies generate their income from an international market working in Dollars, thus the revenue is require to be converted while the expenses, assets and liabilities are already given in Rand values.   

Input is a file that contains the identifiers and financials of the companies (revenue, expenses, assets and liabilities). A two line example is shown below: the first company (company1) has a yearly dollar revenue of 50000, expenses of R600000, assets of R5000000, and liabilites of R2000000. The second company (company2) has a yearly dollar revenue of 100000, expenses of R1800000, assets of R4000000, and liabilites of R10000000.  

```
company1 50000 600000 5000000 2000000
company2 100000 1800000 4000000 10000000
```

We can assume that the exchange rate is measured at a yearly average of $1 = R20.

# How to build and test

```
make
make test
```

# How the program should be run

The program is run from the command line. It should take two command-line arguments: the name of an input file and the name of an output file. For example

```
./bmi raw.dat analyzed.txt
```

This opens the file `raw.dat` categorises each company and puts the result in the file `analysed.txt`. For example, if the two line example above is the content of `raw.dat`, then `analyzed.txt` should contain

```
company1 0.4 Healthy 0.08 Average 0.4 Healthy
company2 0.1 Average 0.05 Unhealthy 2.5 Unhealthy
```

