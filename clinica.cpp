#include <iostream>
#include <vector>

using namespace std;


class Data {
    private:
    int dia;
    int mes;
    int ano;

    public:
    //Construtor
     Data(int _dia, int _mes, int _ano) 
        : dia(_dia), mes(_mes), ano(_ano) {}

    //Setters
    void setDia(int _dia){
        this->dia = _dia;
    }

    void setMes(int _mes){
        this->mes = _mes;
    }

    void setAno(int _ano){
        this->ano = _ano;
    }

    //Getters
    int getDia(){
        return this->dia;
    }

    int getMes(){
        return this->mes;
    }

    int getAno(){
        return this->ano;
    }

    
    
};

class Paciente {
    private:
    string cpf;
    string nomePaciente;
    Data dtNascimento;

    public:
    //Construtor
     Paciente(string _cpf, string _nomePaciente, Data _dtNascimento)
        : cpf(_cpf), nomePaciente(_nomePaciente), dtNascimento(_dtNascimento) {}

    //Setters
    void setCpf(string _cpf){
        this->cpf = _cpf;
    }

    void setNomePaciente(string _nomePaciente){
        this->nomePaciente = _nomePaciente;
    }

    //Getters
    string getCpf(){
        return this->cpf;
    }

    string getNomePaciente(){
        return this->nomePaciente;
    }

    Data getDtNascimento(){
        return this->dtNascimento;
    }

    //Vou passar um vector como refencia para que seja adicionado nele
    void incluir(vector<Paciente> &pacientes, Paciente p){
        pacientes.push_back(p);
    }

    void excluir(){

    }

    void alterar(){

    }

    void listar(vector<Paciente> pacientes){
        for(auto paciente : pacientes){
           /*  cout << "-----------------------" << endl;
            cout << "Nome: " << paciente.getNomePaciente() << endl;
            cout << "CPF: " << paciente.getCpf() << endl;
            cout << "Data de Nascimento: " << paciente.getDtNascimento().getDia();
            cout <<" / " paciente.getDtNascimento().getMes();
            cout << " / " paciente.getDtNascimento().getAno() << endl;; */

        }
    }

    void localizarPorCpf(){

    }


};


class Medico {
    private:
    string crm;
    string nomeMedico;
    string especialidade;

    public:

    //Setters
    void setCrm(string _crm){
        this->crm = _crm;
    }

    void setNomeMedico(string _nomeMedico){
        this->nomeMedico = _nomeMedico;
    }

    void setEspecialidade(string _especialidade){
        this->especialidade = _especialidade;
    }

    //Getters
    string getCrm(){
        return this->crm;
    }

    string getNomeMedico(){
        return this->nomeMedico;
    }

    string getEspecialidade(){
        return this->especialidade;
    }
    
};

int main(){
    
    int opcao;
    int opcaoSubMenu;
    vector <Paciente> pacientes;
    vector <Medico> medicos;
    

    //cout << "Tamanaho de pacientes: " << pacientes.size() << endl;

    do{
        cout << ">>> BEM-VINDO(A) A CLINICA SEM DODOI <<<" << endl;
        cout << "[1] PACIENTES " << endl;
        cout << "[2] MEDICOS " << endl;
        cout << "[0] SAIR " << endl;
        cin >> opcao;

        switch(opcao){
            case 0:
            break;
            //REFATORAR ESSE MENU 
            case 1:
            do{
                cout << ">>> PACIENTES <<<" << endl;
                cout << "[1] INCLUIR" << endl;
                cout << "[2] EXCLUIR" << endl;
                cout << "[3] ALTERAR" << endl;
                cout << "[4] LISTAR" << endl;
                cout << "[5] LOCALIZAR" << endl;
                cout << "[0] SAIR" << endl;
                cin >> opcaoSubMenu;

                switch(opcaoSubMenu){
                    case 0:
                    break;

                    case 1:
                        {   system("cls");
                            Data d(10,02,1999);
                            Paciente paciente("0000", "0000", d);
                            paciente.incluir(pacientes, paciente);
                            cout << "Tamanaho de pacientes: " << pacientes.size() << endl;
                        }
                    break;

                    case 2:
                    break;

                    case 3:
                    break;

                    case 4:
                        system("cls");
                        cout << "------- LISTANDO PACIENTES -------" << endl;
                        for(auto paciente : pacientes){
                            cout << "----------------------------------" << endl;
                            cout << "Nome: " << paciente.getNomePaciente() << endl;
                            cout << "CPF: " << paciente.getCpf() << endl;
                            cout << "Data de Nascimento: " << paciente.getDtNascimento().getDia();
                            cout << " / " << paciente.getDtNascimento().getMes();
                            cout << " / " << paciente.getDtNascimento().getAno() << endl;
                        }
                        cout << "----------------------------------" << endl;
                    break;

                    case 5:
                    break;

                    default:
                        system("cls");
                        cout << "Opcao invalida! " << endl;
                    break;
                }


            }while(opcaoSubMenu != 0);
            break;

            case 2:
            do{
                cout << ">>> MEDICOS <<<" << endl;
                cout << "[1] INCLUIR" << endl;
                cout << "[2] EXCLUIR" << endl;
                cout << "[3] ALTERAR" << endl;
                cout << "[4] LISTAR" << endl;
                cout << "[5] LOCALIZAR" << endl;
                cout << "[0] SAIR" << endl;
                cin >> opcaoSubMenu;

                switch(opcaoSubMenu){
                    case 0:
                    break;

                    case 1:
                    break;

                    case 2:
                    break;

                    case 3:
                    break;

                    case 4:
                    break;

                    case 5:
                    break;

                    default:
                        cout << "Opcao invalida! " << endl;
                    break;
                }


            }while(opcaoSubMenu != 0);
            break;

            default:
                cout << "Opcao invalida! " << endl;
            break;
        }

    }while(opcao !=  0);

    return 0;
}