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

        float getSalario(float salario){
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
            std::cout << "Seu nome é " << nome << ", tendo um salário de " << getSalario(salario) << " reais, ganhando " << salario * 12 << " reais anualmente.\n";
        }

    protected:
        std::string nome;
        float salario;
};

class Assistente : public Funcionario{

    public:
        Assistente(){}
        ~Assistente(){}

        void setMatricula(int _matricula){
            matricula = _matricula;
        }

        int getMatricula(int matricula){
            return matricula;
        }

        void exiDados(int matricula,std::string nome, float salario){
            Funcionario::exiDados(nome,salario);
            std::cout << "Sua matrícula é " << getMatricula(matricula) << ".\n";
        }

    protected:
        int matricula;

};

class Tecnico : public Assistente{
    public:
        Tecnico(){}
        ~Tecnico(){}

        void setBonus(float _bonus){
            bonus = _bonus;
        }

        float adicionarBonus(){
            std::cout << "Digite seu bônus salarial: ";
            std::cin >> bonus;
            salario += bonus;
            setBonus(bonus);
            Funcionario::setSalario(salario);
        }

        void ganhoAnual(float salario){
            Funcionario::ganhoAnual(salario);
            std::cout << "Já que você é assistente técnico.";
        }

        void exiDados(std::string nome, float salario, int matricula){
            Assistente::exiDados(matricula,nome,salario);
            std::cout << "Você é assistente técnico, por isso ganha um bônus salarial de " << bonus << "reais.";
        }



    private:
        float bonus;

};

class Administrativo : public Assistente{

    public:
        Administrativo(){}
        ~Administrativo(){}

        void setTurno(char _turno){
            turno = _turno;
        }

        void setBonusN(float _bonusN){
            bonusN = _bonusN;
        }

        void ganhoAnual(float salario){
            Funcionario::ganhoAnual(salario);
            std::cout << "Já que você é assistente administrativo.";
        }

        void bonusNoturno(){
            std::cout << "Digite o seu bônus salarial: ";
            std::cin >> bonusN;
            setBonusN(bonusN);
            salario += bonusN;
            Funcionario::setSalario(salario);
        }

        void exiDados(std::string nome,float salario,int matricula,char turno){
            std::string arrumarTurno;
            Assistente::exiDados(matricula,nome,salario);
            std::cout << "Você é assistente administrativo.";
             if(turno == 'n'){
                arrumarTurno = 'noite';
                std::cout << "Trabalhando no turno da noite, por isso ganha um bônus salarial de " << bonusN << " reais.";
            }
               else{
                 arrumarTurno = 'dia';
                 std::cout << "Trabalhando no turno do dia";
            }
        }

    private:
        char turno;
        float bonusN;
};

int main(){
    Funcionario funcionario;
    Assistente assistente;
    Administrativo administrativo;
    Tecnico tecnico;
    std::string nome;
    char turno;
    float salario;
    int matricula;
    int i = 1, a, b;
    std::cout << "Digite seu nome: ";
    std::cin >> nome;
    std::cout << "Digite seu salário: ";
    std::cin >> salario;
    funcionario.setSalario(salario);
    funcionario.setNome(nome);
    std::cout << "\nÉ um Assistente? 1 (sim), 0 (não): ";
    std::cin >> a;

    if(a == 1){
        std::cout << "Digite sua matrícula: ";
        std::cin >> matricula;
        assistente.setMatricula(matricula);
        std::cout << "É um assistente administrativo ou técnico? 1(Administrativo), 2(Técnico): ";
        std::cin >> b;
        if(b == 1){
            std::cout << "Trabalha em que turno? Dia(d) ou Noite(n): ";
            std::cin >> turno;
            administrativo.setTurno(turno);
            if(turno == 'n'){
                administrativo.bonusNoturno();
            }
        }
        else{
            tecnico.adicionarBonus();
        }
    }

   do{
        int n;
        std::cout << "\nDigite o que deseja realizar:\n1 para adicionar um aumento;\n2 para ver seu ganho anual;\n3 para ver seus dados.\n:";
        std::cin >> n;
        switch(n){
            case 1:
                funcionario.addAumento(salario);
                std::cout << "Seu salário agora é " << funcionario.getSalario(salario) << " reais.\n";
                break;
            case 2:
                if(a == 1){
                    if(b == 1){
                        administrativo.ganhoAnual(salario);
                    }
                    else{
                        tecnico.ganhoAnual(salario);
                    }
                }
                else{
                    funcionario.ganhoAnual(salario);
                }
                break;
            case 3:
                if(a == 1){
                   if(b == 1){
                        administrativo.exiDados(nome,salario,matricula,turno);
                   }
                   else{
                        tecnico.exiDados(nome,salario,matricula);
                   }
                }
                else{
                    funcionario.exiDados(nome,salario);
                }
                break;
        }
        std::cout << "\nDeseja realizar algo mais? Digite 1 para sim e 0 para não:";
        std::cin >> i;
   }while(i == 1);

    std::cout << "Operação finalizada. Obrigado por utilizar o programa.";
    return 0;
}