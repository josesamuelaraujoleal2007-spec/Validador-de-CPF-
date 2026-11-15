#include <stdio.h>
#include <ctype.h>

 
 int limparCPF (const char * entrada, int cpf[]) {
 	int n = 0, i;
 	for (i =0; entrada[i] != '\0'; i++) {
 		if (isdigit((unsigned char)entrada[i])) {
 			if (n < 11) cpf [n] = entrada [i] - '0';
 			n++;
		 }
	 }
	 return n; 
 }
 
 int todosIguais(const int cpf[]) {
 	int i;
 	for (i =1; i < 11; i++)
 	if (cpf[i] != cpf [0]) return 0;
 	return 1;
 }
 
 int calcularDigito(const int cpf[], int tam) {
 	int i, soma = 0, resto; 
 	for (i = 0; i < tam; i++)
 	    soma += cpf[i] * (tam + 1 - i);
	resto = (soma * 10) % 11;
	return (resto ==10) ? 0 : resto; 
 }
 
 int validarCPF (const char * entrada) {
 	int cpf[11];
 	if (limparCPF(entrada, cpf) !=11) return 0;
 	if (todosIguais(cpf)) return 0;
 	return calcularDigito(cpf, 9) == cpf[9] &&
 	       calcularDigito(cpf, 10) == cpf[10];
  }
  
  int main () {
  	char entrada[50];
  	
  	printf("Validador de CPF\n");
  	printf("Digite um CPF (ou sair): ");
  	
  	while (fgets(entrada, sizeof(entrada), stdin) != NULL) {
  		if (entrada [0] == 's' || entrada [0] == 'S') break;
  		
  		if (validarCPF(entrada))
  		   printf("CPF valido\n");
  		else 
  		   printf("CPF invalido!\n");
  		   
  		   printf("\nDigite outro CPF (ou 'sair'): ");
	  }
	  printf("Encerrando...\n");
	  return 0;
  }
  
  
