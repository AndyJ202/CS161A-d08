/******************************************************************************
# Author:           Andy Joy
# Assignment:       Discussion 8
# Date:             06/13/2026
# Description:      This program takes the user's monthy income and expenses.
#                   Then calculates the total income, total expenses, net total,
#                   and notifies the user if they're over or under the required
#                   amount.
# Input:            socialSecurity (double), pensions (double), retirementSavings
#                   (double), food (double), housing (double),
#                   entertainment (double).
# Output:           totalIncome (double), totalExpenses (double), net total
#                   (calculated).
# Sources:          N/A
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

//Function prototypes
void welcomeMessage();
void goodByeMessage();
void doubleInputValidation(double &userInteger, string prompt);
void monthlyIncomeSources(double &income);
void monthlyExpenses(double &expenses);

//Main function
int main() {
  double totalIncome = 0;
  double totalExpenses = 0;

  welcomeMessage();
  cout << "\n";
  monthlyIncomeSources(totalIncome);
  cout << "\n";
  monthlyExpenses(totalExpenses);
  cout << "\n" << "Total Income Amount: $" << totalIncome << endl;
  cout << "Total Expenses: $" << totalExpenses << endl;
  cout << "Net total: $" << totalIncome - totalExpenses <<endl;

  if (totalIncome == totalExpenses) {
    cout << "\nIncome matched the required expenses!" << endl;
  }

  else if (totalIncome > totalExpenses) {
    cout << "\nIncome exceeded the required expenses by $" << totalIncome - totalExpenses << "!" << endl;
  }

  else {
    cout << "\nOh no! Expenses exceeded the required income by $" << totalExpenses - totalIncome << "." << endl;
  }


  goodByeMessage();

  return 0;
}

void welcomeMessage() {
  cout << "Welcome to my budgeting program." << endl;
}

void goodByeMessage() {
  cout << "\nThank you for using my program." << endl;
}

void doubleInputValidation(double &userDouble, string prompt) {
    cout << prompt;
    cin >> userDouble;
  
  while (!cin || userDouble < 0) {
    cout << "Invalid input, please try again!" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    cin >> userDouble;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void monthlyIncomeSources(double &income) {
  double socialSecurity = 0.0;
  double pensions =  0.0;
  double retirementSavings = 0.0;
  
  doubleInputValidation(socialSecurity, "Please enter the monthly income amount from social security: ");
  doubleInputValidation(pensions, "Please enter the monthly income amount from pensions: ");
  doubleInputValidation(retirementSavings,"Please enter the monthly income amount from retirement savings: ");

  income = socialSecurity + pensions + retirementSavings;
}

void monthlyExpenses(double &expenses) {
  double food = 0.0;
  double housing =  0.0;
  double entertainment = 0.0;
  
  doubleInputValidation(food, "Please enter the monthly expenses for food: ");
  doubleInputValidation(housing, "Please enter the monthly expenses for housing: ");
  doubleInputValidation(entertainment,"Please enter the monthly expenses for entertainment: ");

  expenses = food + housing + entertainment;
}