//Exemplo de Entrada	Exemplo de Saída
//4
//1 / 2 + 3 / 4
//1 / 2 - 3 / 4
//2 / 3 * 6 / 6
//1 / 2 / 3 / 4
//
//10/8 = 5/4
//-2/8 = -1/4
//12/18 = 2/3
//4/6 = 2/3

//Soma: (N1*D2 + N2*D1) / (D1*D2)
//Subtração: (N1*D2 - N2*D1) / (D1*D2)
//Multiplicação: (N1*N2) / (D1*D2)
//Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)

#include <stdio.h>
#include <stdlib.h>

int menor(int n1, int n2){
	if(n1<=n2)
		return n1;
	else
		return n2;
}

int mdc(int num1,int num2){
	int men, mdc = 1;
	men = menor(num1,num2);
	for(int i=1; i <= men;i++){
		if(num1%i == 0 && num2%i == 0)
			mdc = i;
	}
	
	return mdc;
}


int main(){
    int n1, n2, d1, d2, result_num, result_den, my_mdc = 1;
	char c1, op, c2;
	
	scanf("%d %c %d %c %d %c %d",&n1, &c1, &d1, &op, &n2, &c2, &d2);
	
	switch(op){
		
		case '+':
			result_num = n1*d2 + n2*d1;
			result_den = d1*d2;
			break;
		case '-':
			result_num = n1*d2 - n2*d1;
			result_den = d1*d2;
			break;
		case '*':
			result_num = n1*n2;
			result_den = d1*d2;
			break;
		case '/':
			result_num = n1*d2;
			result_den = n2*d1;
			break;
	}
	my_mdc = mdc(result_num,result_den); 
	
	printf("%d/%d = %d/%d",result_num,result_den,(result_num/my_mdc),(result_den/my_mdc));
	
    return 0;
}