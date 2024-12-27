
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void main(){
	
	printf("welcom!\ncommands:(for usage type them)\nman(manual page)\nlist\nconst\nabout\nclear\nexit\n\n");

	// defined constant
	char Exit[4] = "exit" , Clear[5] = "clear"  , Manual[3] = "man" ;
	char funclist[4] = "list" , about[5] = "about" , constant[5] = "const";
	char Sin[3] = "sin" , Cos[3] = "cos" , Tan[3] = "tan" , Cot[3] = "cot";
	char ASin[3] = "asn" , ACos[3] = "acs" , ATan[3] = "atn" ;
	char Log[3] = "lgE" , Log10[3] = "lgT" , Factorial[3] = "FCT" , Sqrt[3] = "sqr";

	while(1 > 0){
		// defined variable
		char string[100] , strcp[100], stropr[100] , strnum1[20] , strnum2[20] ;
		char lenexit = 0 , lenclear = 0 , lenman = 0 , lenlist = 0 , lenabout = 0 , lenconst = 0;
		char i , len , opr   , counter = 0 , advance = 0 , oprcount = 0 , lensin = 0 , lencos = 0 , lentan = 0;
		char lencot = 0 , lensqrt = 0 , lenatan = 0 , lenasin = 0 , lenacos = 0 , lenlog = 0 , lenlog10 = 0, lenfct = 0;
		double num1 , num2 , result = 0 , resultadv = 0;
		long long int num1int , num2int ;
		
		// filling strings wiht 0
		for(i = 0 ; i < 100 ; i++){
			string[i] = 0;
			strcp[i] = 0;
			stropr[i] = 0;
		}
		
		// receiving input
		gets(string);

		// filling strnums with 0
		for(i = 0 ; i < 20 ; i++){
			strnum1[i] = 0;
			strnum2[i] = 0;
		}
		
		// exit commnad
		for(i = 0 ; i < 4 ; i++){
			if(Exit[i] == string[i]){
				lenexit++;
			}
			if(i == 3 && lenexit == 4){
				exit(0);
			}
		}

		// clear command
		for(i = 0 ; i < 5 ; i++){
			if(Clear[i] == string[i]){
				lenclear++;
			}
			if(i == 4 && lenclear == 5){
				// in case using linux or macos uncomment system("clear");
				system("clear");
				//system("cls");
			}
		}

		// manual - map page command
		for(i = 0 ; i < 3 ; i++){
			if(Manual[i] == string[i]){
				lenman++;
			}
			if(i == 2 && lenman == 3){
				printf("\n\n\nMANUAL PAGE : \n\n\n");
				printf("ADVANCE MODE : \n");
				printf("for using functions enter strings based on following examples :\nnumbers in following manual are example and can be changed.\n\n");
				printf("sin --> sin90\ncos --> cos90\ntan --> tan45\ncot --> cot45\narcsin --> asn1\narccos --> acs1\narctan --> atn1\n\n");
				printf("SQRT --> sqr16\nFactorial --> FCT5\n\n");
				printf("logarithm in base 10 -- > lgT10\nnatural logarithm --> lgE2.718\n\n");
				printf("***WARNING*** ENTERING OTHER OPERATORS ARE NOT SUPPORTED IN THIS MODE(no problem in entering posetive and negetive numbers)\n\n\n");
				printf("NORMAL MODE :\n");
				printf("in this mode you can enter strings based on followin examples :\n");
				printf("13*13 = 169\n1jksdf3aw*ad1lk3 = 169\n1.jkj3*lk1lk.3kj = 1.69\n");
				printf("-12+-12 = -24\n");
				printf("***WARNING*** ENTERING MORE THAN TWO OPERAND AND THREE OPERATORS WONT WORK!\n");
				printf("only example that will not work with 3 operator is 12---12  or other examples like this with triple operator next eachother\n\n");
			}
		}

		// list command
		for(i = 0 ; i < 4 ;i++){
			if(funclist[i] == string[i]){
				lenlist++;
			}
			if(i == 3 && lenlist == 4){
				printf("\n\n\nLIST OF AVAILABLE FUNCTIONS : \n\n\n");
				printf("sin --> sin(degree)\ncos --> cos(degree)\ntan --> tan(degree)\ncot --> cot(degree)\n");
				printf("asn --> arc sin(-1 <= x <= 1)\nacs --> arc cos(-1 <= x <= 1)\natn --> arc tan\n\n");
				printf("sqr --> second root of number(sqrt)\nFCT --> factorial of number(x!)\n\n");
				printf("lgT --> logarithm of number in base 10\nlgE --> logarithm of number in base e(2.718)\n\n\n");
			}
		}

		// about command 
		for(i = 0 ; i < 5 ; i++){
			if(about[i] == string[i]){
				lenabout++;
			}
			if(i == 4 && lenabout == 5){
				printf("simple calculator - version 0.0.1 - in C\n");
			
			}
		}

		// const command
		for(i = 0 ; i < 5 ; i++){
			if(constant[i] == string[i]){
				lenconst++;
			}
			if(i == 4 && lenconst == 5){
				printf("\n\npi = 3.1415926535897932384626433832795028841971693993751\ne = 2.718281828459045235360287471352\n");
				printf("golden ratio = 1.61803398874989484820\n");
			}
		}

		len = strlen(string);
		
		// filtering out characters
		for(i = 0 ; i < len ; i++){
			if((string[i]>=48&&string[i]<=57)||string[i]==45||string[i]== 43||string[i]==42||string[i]==47||string[i]==37||string[i]==94||string[i]==46||string[i]==32){
				// strcp string containing only numbers and operators
				strcp[i - counter] = string[i];
			}
			else{
				// stropr string that save filtered characters for checking 
				stropr[i] = string[i];
				string[i] = 0;
				counter++;
			}
		}
		
		len = strlen(stropr);
		// checking stropr for finding any key words for function usage
		for(i = 0 ; i < len ; i++){
			if(stropr[i] == Sin[i]){
				lensin++;
			}
			if(stropr[i] == Cos[i]){
				lencos++;
			}
			if(stropr[i] == Tan[i]){
				lentan++;
			}
			if(stropr[i] == Cot[i]){
				lencot++;
			}
			if(stropr[i]== Sqrt[i]){
				lensqrt++;
			}
			if(stropr[i]== ASin[i]){
				lenasin++;
			}
			if(stropr[i]== ACos[i]){
				lenacos++;
			}
			if(stropr[i]== ATan[i]){
				lenatan++;
			}
			if(stropr[i] == Log[i]){
				lenlog++;
			}
			if(stropr[i]==Log10[i]){
				lenlog10++;
			}
			if(stropr[i] == Factorial[i]){
				lenfct++;
			}
		}
		
		// advance mode - defining functions
		if(lensin == len || lencos == len || lentan == len || lencot == len || lensqrt == len || lenasin == len || lenacos == len || lenatan == len || lenlog == len || lenlog10 == len || lenfct == len){
			// converting degree to radians
			num1 = atof(strcp) * 3.1415926535 / 180;
			num1int = atof(strcp);
			
			// sin function
			if(lensin == 3){
				resultadv = sin(num1);
				advance++;
			}

			// cos function
			if(lencos == 3){
				result = cos(num1);
				advance++;
			}

			// tan function
			if(lentan == 3){
				if(num1int % 360 != 90 && num1int % 360 != 270){
					resultadv = tan(num1);
				}
				else{
					printf("undefined!\n");
				}
				advance++;
			}

			// cot function
			if(lencot == 3){
				if(num1int % 360 != 0 && num1int % 360 != 180 ){
					resultadv = 1.0 / tan(num1);
				}
				else{
					printf("undefined!\n");
				}
				advance++;
			}

			// SQRT function
			if(lensqrt == 3){
				if(atof(strcp) > 0){
					resultadv = sqrt(atof(strcp));
				}
				else{
					printf("undefined!\n");
				}
				advance++;
			}

			// arc sin function
			if(lenasin == 3){
				if(atof(strcp) >= -1 && atof(strcp) <= 1){
					//converting radians to degree
					resultadv = asin(atof(strcp)) * 180 / 3.1415926535;
				}
				else{
					printf("undefined!\n");
				}
				advance++;
			}

			// arc cos function
			if(lenacos == 3){
				if(atof(strcp) >= -1 && atof(strcp) <= 1){
					// converting radians to degree
					resultadv = acos(atof(strcp)) * 180 / 3.1415926535;
				}
				else{
					printf("undefined!\n");
				}
				advance++;

			}

			// arc tan function
			if(lenatan == 3){
				// converting radians to degree
				resultadv = atan(atof(strcp)) * 180 / 3.1415926535;
				advance++;
			}

			// log in base e function
			if(lenlog == 3 ){
				resultadv = log(atof(strcp));
				advance++;
			}

			// log in base 10 function
			if(lenlog10 == 3){
				resultadv = log10(atof(strcp));
				advance++;
			}

			// factorial function
			if(lenfct == 3 ){
				double sum = 1 , value = atof(strcp);
				advance++;
				if(floor(atof(strcp)) == atof(strcp) && atof(strcp) > 0){
					while( value > 0){
						sum *= value;
						value--;
					}
					resultadv = sum ;
				}	
				
				else{
					printf("undefined!\n");
				}
			}
		}
	

		// normal mode
		if(advance == 0){
			len = strlen(strcp);
			// slicing strcp and finding strnum1 and strnum2 and operator
			// all character except operators are filtered out before (line 136)
			for(i = 0 ; i < len ; i++){
				if(i != 0){
					if(strcp[i]==45||strcp[i]== 43||strcp[i]== 42||strcp[i]==47||strcp[i]==37||strcp[i]==94){
						opr = strcp[i];
						oprcount++;
						break;
					}
					else{
						strnum1[i] = strcp[i];
						// operator counter
						if(strcp[i]==45||strcp[i]== 43||strcp[i]== 42||strcp[i]==47||strcp[i]==37||strcp[i]==94){
							oprcount++;
						}
					}
				}
				else{
					strnum1[i] = strcp[i];
					// operator counter
					if(strcp[i]==45||strcp[i]== 43||strcp[i]== 42||strcp[i]==47||strcp[i]==37||strcp[i]==94){
						oprcount++;
					}
				}
			}
			
			// finding strnum2
			for(i = strlen(strnum1) + 1 ; i < len ; i++){
				strnum2[i - strlen(strnum1) - 1 ] = strcp[i];
				// operator counter
				if(strcp[i]==45||strcp[i]== 43||strcp[i]== 42||strcp[i]==47||strcp[i]==37||strcp[i]==94){
						oprcount++;
				}
			}
			
			// converting strnum1 & strnum2 to num1 & num2
			num1 = atof(strnum1);
			num2 = atof(strnum2);
		}

		// operator count limit
		if(oprcount > 3){
			printf("MORE THAN 3 OPERATOR!");
			exit(0);
		}
		
		// normal operation
		switch(opr){
			case 45 :
				result = num1 - num2 ;
				break ;
			case 43 :
				result = num1 + num2 ;
				break ;
			case 42 :
				result = num1 * num2 ;
				break ;
			case 47 :
				result = num1 / num2 ;
				break ;
			case 37 :
				if(floor(num1) == num1 && floor(num2) == num2){
					num1int = num1;
					num2int = num2;
					result = num1int % num2int;
				}
				else{
					printf("ERROR!\n");
					exit(0);
				}
				break ;
			case 94 :
				result = pow(num1 , num2) ;
				break ;
			default :
				break;
		}
		
		
		//printing ans
		if(advance != 0){
			printf("%f" , resultadv);
		}
		else{
			if(strlen(strnum1)>=8 && strlen(strnum2)>=8 || strlen(strnum2)>=7 && strlen(strnum2)>=9 || strlen(strnum1)>=9 && strlen(strnum2)>=7 ){
				printf("%.10g" , result);
			}
			else{
				printf("%f" , result);
			}
		}
		printf("\n----------------------------------------\nexit / clear / man / list / const / about \n----------------------------------------\n\n");
	}
}
