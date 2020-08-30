#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

long long int soma_primos =0;			// pra somar os primos
int para = 0;

void TestaPrimo4 (int n, int fim) {	//TestaPrimo4 irá testar se vai ou não ser primo.

	for(int i = n; i>fim;i--){
		int EhPrimo, 
		    d=3;
		if (n <= 1 || (n != 2 && n % 2 == 0 ) || (n % 6 != 1 && n % 6 != 5))
		    EhPrimo = 0;    
		else
		    EhPrimo = 1;
		while (EhPrimo  && d <= n / 2) {
		    if (n % d == 0)
		        EhPrimo = 0;
		    d = d + 2;
		    }
		
		if(EhPrimo != 0){ //se for diferente de 0 vou somar e printar as somas dos primos
    	  soma_primos = soma_primos + n;
    	  printf("\n%d - %d",para+1 ,n);
    	  para++;
		}	
		else if(para>=221){
			i=0;
      printf("\n\tSoma dos primos: %lld\n", soma_primos);
		}
		
		n--;
		
	}
	
}

// RA: 221170640

int main(int argc, char *argv[]) {
	
	int aaa = 170; // valor de aaa
  	int bbb = 640; // valor de bbb
  	int p = aaa*bbb; //108800
	
	auto comeco = std::chrono::steady_clock::now(); 	
	
	std::thread primeira_metade(TestaPrimo4,p,(p/2)); //abre primeira thread pois vou dividir em 2 threads.

	primeira_metade.join();
	std::thread segunda_metade(TestaPrimo4,((p/2)-1),0); // chamada da segunda thread
	segunda_metade.join();
	
	auto termina = std::chrono::steady_clock::now();							

	milliseconds tempoexec = duration_cast<milliseconds>(termina - comeco);

  return 0;
}