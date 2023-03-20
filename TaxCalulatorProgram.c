#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#include <stdlib.h>


//Function to calculate tax.
float calculate_tax(float amount) {
	//tax rate changes depending on how much money they make
	if ((amount >= 23571) && (amount <= 50270)) {
		return amount * 0.2f;
	}
	else if ((amount >= 50271) && (amount <= 150000)) {
		return amount * 0.4f;
	}
	else if (amount > 150001) {
		return amount * 0.45f;
	}
	else {
		return amount;
	}
}

//function to calculate net pay.
float calculate_netpay(float amount, float tax) {
	return amount - tax;
}

//function to increment the salary.
float increment_salary(float amount, float increment_rate) {
	float newTax;
	printf("\nIncrement is: %f\n", increment_rate);
	//will repeat this 5 times.
	for (int years = 1; years < 6; years = years + 1) {
		printf("\nYear %d:\n", years);
		amount = amount + (amount * increment_rate);
		newTax = calculate_tax(amount);
		printf("Tax is: %f\n", newTax);
		printf("Net pay is: %f\n", amount);
	}
	return 0;
}


int main() {
	//define the variables
	bool roleCheck = true;
	bool salaryCheck = true;
	bool whileCheck = false;

	float grossSalary;
	float increment = 0;

	int salaryRange[2];

	char continueVal;
	char grade;
	char employee[3][10] = { "0001", "cto", "test" };
	
	//loops when the user wants to retry
	while (whileCheck == false) {
		bool continueCheck = false;
		bool gradeCheck = false;

		printf("\nPlease input an employee ID ");
		scanf_s(" %s", &employee[0], 10);

		//checks to make sure the user has inputted the correct role
		while (roleCheck) {
			printf("\nPlease input the employee role ");
			scanf_s(" %s", &employee[1], 10);
			//will change the salary range depending on the role entered
			if (strcmp(employee[1], "cto") == 0) {
				
				salaryRange[0] = 70000;
				salaryRange[1] = 80000;
			}
			else if (strcmp(employee[1], "pm") == 0) {
				
				salaryRange[0] = 55000;
				salaryRange[1] = 65000;
			}
			else if (strcmp(employee[1], "pa") == 0) {
				
				salaryRange[0] = 33000;
				salaryRange[1] = 50000;
			}
			else {
				printf("Please enter a correct role.");
				continue;
			}
			break;
		}

		//checks to make sure the user has put in the correct salary for the role
		while (salaryCheck) {
			printf("\nPlease input the employee salary ");
			scanf_s(" %s", employee[2], 10);
			//Casting the string into an int so it can be used in calculations.
			grossSalary = atoi(employee[2]);
			if ((grossSalary > salaryRange[1]) || (grossSalary < salaryRange[0])) {
				printf("please enter a salary between %d and %d", salaryRange[0], salaryRange[1]);
				continue;
			}
			else {
				break;
			}
		}

		//saves all the info into a salary slip
		float salarySlip[4] = { atoi(employee[0]), grossSalary, calculate_tax(grossSalary), calculate_netpay(grossSalary, calculate_tax(grossSalary)) };

		//Nicely layed out payslip.
		printf("\n--------Salary Slip--------");
		printf("\n\nEmployee ID: %f", salarySlip[0]);
		printf("\nGross Salary: %f", salarySlip[1]);
		printf("\nTax: %f", salarySlip[2]);
		printf("\nNet Pay: %f", salarySlip[3]);
		printf("\n\n------------------------\n\n");

		//error trapping to make sure only A B or C can be entered.
		while (gradeCheck == false) {

			printf("Please enter a grade: ");
			scanf_s(" %c", &grade, 5);
			//each case changes the grade increment value.
			switch (grade) {
			case 'a':
			case 'A':
				increment = 0.025;
				gradeCheck = true;
				break;
			case 'b':
			case 'B':
				increment = 0.015;
				gradeCheck = true;
				break;
			case 'c':
			case 'C':
				increment = 0;
				gradeCheck = true;
				break;
			default:
				printf("\nPlease enter a correct grade!\n\n");
			}
		}

		//calls the funtion to increment the pay over 5 years.
		increment_salary(calculate_netpay(grossSalary, calculate_tax(grossSalary)), increment);


		while (continueCheck == false) {
			printf("\nRetry?(y/n) ");
			scanf_s(" %c", &continueVal, 5);
			switch (continueVal) {
				//if user doesnt want to continue end the loop
			case 'n':
			case 'N':
				whileCheck = true;
				continueCheck = true;
				break;
			case 'y':
			case 'Y':
				continueCheck = true;
				printf("\n\n------------------------------------------------\n\n");
				break;
			default:
				printf("\nPlease enter a correct value.\n");
				break;
			}
		}
	}

}