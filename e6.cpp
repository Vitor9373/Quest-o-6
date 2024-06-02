// Implemente a classe Funcionario com nome, salario e os métodos
// addAumento(double valor), ganhoAnual() e exibeDados() - imprime os valores do
// funcionário.
// a. crie a classe Assistente, que também é um funcionário, e que possui um
// número de matrícula (faça os métodos GET e SET). Sobrescreva o método
// exibeDados().
// b. sabendo que os Assistentes Técnicos possuem um bônus salarial e que os
// Assistentes Administrativos possuem um turno (dia ou noite) e um adicional
// noturno, crie as classes Tecnico e Administrativo e sobrescreva o método
// ganhoAnual() de ambas as classes (Administrativo e Tecnico).

#include <iostream>

class Funcionario{

    public:
        Funcionario(){}
        ~Funcionario(){}

        void setSalario(float _salario){
            salario = _salario;
        }

        void setNome(std::string _nome){
            nome = _nome;
        }

        float getSalario(){
            return salario;
        }

        float addAumento(float salario){
            float aumento;
            std::cout << "Digite o valor do aumento: ";
            std::cin >> aumento;
            salario += aumento;
            setSalario(salario);
            return salario;
        }

        void ganhoAnual(float salario){
            std::cout << "Seu salário anual é " << salario * 12 << " reais.\n";
        }

        void exiDados(std::string nome, float salario){
            std::cout << "Seu nome é " << nome << ", tendo um salário de " << salario << " reais, ganhando " << salario * 12 << " reais anualmente.\n";
        }

    private:
        std::string nome;
        float salario;
};

int main(){
    Funcionario funcionario;
    std::string nome;
    float salario;
    int i = 1;
    std::cout << "Digite seu nome: ";
    std::cin >> nome;
    std::cout << "Digite seu salário: ";
    std::cin >> salario;
    funcionario.setSalario(salario);
    funcionario.setNome(nome);
    while(i == 1){
        int n;
        std::cout << "Digite o que deseja realizar:\n1 para adicionar um aumento;\n2 para ver seu ganho anual;\n3 para ver seus dados.\n:";
        std::cin >> n;
        switch(n){
            case 1:
                salario = funcionario.addAumento(salario);
                std::cout << "Seu salário agora é " << funcionario.getSalario() << " reais.\n";
                break;
            case 2:
                funcionario.ganhoAnual(salario);
                break;
            case 3:
                funcionario.exiDados(nome,salario);
                break;
        }
        std::cout << "Deseja realizar mais algo? Digite 1 para sim e 0 para não:";
        std::cin >> i;
    }
    std::cout << "Operação finalizada. Obrigado por utilizar o programa.";
    return 0;
}