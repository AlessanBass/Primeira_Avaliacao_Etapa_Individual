#include <iostream>
#include <vector>

using namespace std;


class Data {
    private:
    int dia;
    int mes;
    int ano;

    public:

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

    //Vou passar um vector como refencia para que seja adicionado nele
    void incluir(vector<Paciente> &pacientes){

    }

    void excluir(){

    }

    void alterar(){

    }

    void listar(){

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

    cout << "Hello World";
    return 0;
}