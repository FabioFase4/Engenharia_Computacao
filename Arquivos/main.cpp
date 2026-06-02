#include <iostream>
#include <windows.h>
#include <cstdint>
#include <string>
#include <iomanip>

using namespace std;

// Simulação de um registrador de hardware através de um ponteiro
volatile int* REGISTRADOR_PORTA = new int(0);

void imprimirBinario(int valor) {
    for (int i = 7; i >= 0; --i) {
    	Sleep(50);
        std::cout << ((valor >> i) & 1);
    }
    std::cout << "\n";
}

void aguardar ()
{
	Sleep(1000);
	std::cout << "\n";
}

void mostrar_caracteres (std::string frase)
{
	for (int i = 0; i < frase.length(); i++)
	{
		Sleep(50);
		std::cout << frase[i];
	}
}

void inicio ()
{
	mostrar_caracteres(">> Bem Vindo a um Pequeno Programa em C++ <<\n");
	aguardar();
	mostrar_caracteres(">> Aqui, Buscamos uma Analise Rapida <<\n");
	aguardar();
	mostrar_caracteres(">> Sobre as Interacoes entre Hardware e Software <<\n");
	
	for (int i = 0; i < 3; i++)
		aguardar();
}

void fim ()
{
	aguardar();
	std::cout << "\n\n\n";
	
	mostrar_caracteres (">> Obrigado pela Atencao!");
}

int main() {
	inicio();
	
	//0. Saudacoes
	mostrar_caracteres(">> Saudacoes, Viajante!\n");
	mostrar_caracteres(">> Meu nome e Gilbert\n");
	mostrar_caracteres(">> Serei seu Orientador nessa Aventura\n");
	mostrar_caracteres(">> Atencao!\n\n");
	mostrar_caracteres(">> Vamos Entrar no Registrador\n");
	mostrar_caracteres(">> Manipular a Memória\n");
	mostrar_caracteres(">> E Demonstrar um Pouco sobre a Engenharia da Computação\n");
	mostrar_caracteres(">> Divirta-se!\n\n");
	
    // 1. Configuração inicial (Estado do Registrador)
    *REGISTRADOR_PORTA = 0b00000000;
    mostrar_caracteres(">> Registrador inicial: \t");
    imprimirBinario(*REGISTRADOR_PORTA);
    aguardar();

    // 2. Ligar o Pino 3 (Mascara: 00001000)
    // Usamos o operador OR (|) para alterar apenas o bit desejado sem afetar os outros
    *REGISTRADOR_PORTA |= (1 << 3);
    mostrar_caracteres(">> Apos ligar o Pino 3: \t");
    imprimirBinario(*REGISTRADOR_PORTA);
    aguardar();

    // 3. Ligar os Pinos 0 e 5 (Mascara: 00100001)
    *REGISTRADOR_PORTA |= (1 << 0) | (1 << 5);
    mostrar_caracteres(">> Apos ligar Pino 0 e 5: \t");
    imprimirBinario(*REGISTRADOR_PORTA);
    aguardar();

    // 4. Desligar o Pino 3
    // Usamos o AND (&) com o inverso (~) da mascara para limpar o bit
    *REGISTRADOR_PORTA &= ~(1 << 3);
    mostrar_caracteres(">> Apos desligar Pino 3: \t");
    imprimirBinario(*REGISTRADOR_PORTA);
    aguardar();

    // 5. Inverter o estado de todos os pinos
    // Usamos o XOR (^) para inverter bits específicos
    *REGISTRADOR_PORTA ^= 0xFF;
    mostrar_caracteres(">> Apos inverter estado: \t");
    imprimirBinario(*REGISTRADOR_PORTA);
	
	fim();
    return 0;
}

