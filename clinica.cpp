#include <iostream>
#include <vector>
#include <string>
#include <cctype>

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
     Paciente(string _nomePaciente, string _cpf,  Data _dtNascimento)
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
        cout << "Em construcao... " << endl;
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

class VerificaDados{
    private:
    int verificaTamanhoCpf;
    int verificaDigito;
    int verificaCpfCadastrado;
    int verificaData;

    public:
    int getVerificaTamanhoCpf(){
        return this->verificaTamanhoCpf;
    }

    int getVerificaData(){
        return this->verificaData;
    }

    int getVerificaDigito(){
        return this->verificaDigito;
    }

    int getVerificaCpfCadastrado(){
        return this->verificaCpfCadastrado;
    }

    VerificaDados(){

    }

    int verificacaoCpf(vector<Paciente> pacientes, string cpf){
        // 1 - Verifica o tamanho do CPF
        if(cpf.length() == 11){
            this->verificaTamanhoCpf = 1;
        }else{
            this->verificaTamanhoCpf = 0;
        }

        // 2 - Verifica se so foram passados numeros
        for(int i = 0; i < cpf.length(); i++){
            if(isdigit(cpf[i])){
                this->verificaDigito = 1;
            }else{
                this->verificaDigito = 0;
                break;
            }
        }

        //3 - Verifica se já possui cpf cadastrado
        for(int i = 0; i < pacientes.size() ; i++){
            if(pacientes[i].getCpf() == cpf){
                this->verificaCpfCadastrado = 0;
                break;
            }else{
                this->verificaCpfCadastrado = 1;
            }
        }

        //Retorna um feedback se tá tudo certo
        if(this->verificaTamanhoCpf && this->verificaDigito && this->verificaCpfCadastrado){
            return 1;
        }
        return 0;
       
    }

    int verificacaoData(int dia, int mes, int ano){
    if (ano >= 1900 && ano <= 2023) {
        if (mes >= 1 && mes <= 12) {
            if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia >= 1 && dia <= 31)) {
             this->verificaData = 1;
            } else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia >= 1 && dia <= 30)) {
                this->verificaData = 1;
            } else if (mes == 2) {
                if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
                    if (dia >= 1 && dia <= 29) {
                        this->verificaData = 1;
                    } else {
                        this->verificaData = 0;
                    }
                } else {
                    if (dia >= 1 && dia <= 28) {
                        this->verificaData = 1;
                    } else {
                        this->verificaData = 0;
                    }
                }
            } else {
                this->verificaData = 0;
            }
        } else {
            this->verificaData = 0;
        }
    } else {
        this->verificaData = 0;
    }

        //Retorna o feedback
        if(this->verificaData){
            return 1;
        }

        return 0;
    }


};

int localizarPorCpf(vector<Paciente> pacientes, string cpfProcurado){
    for(int i = 0; i<pacientes.size(); i++){
        if(pacientes[i].getCpf() == cpfProcurado){
            return i;
        }
    }
    return -1;
}

int main(){
    
    int opcao;
    int opcaoSubMenu;
    vector <Paciente> pacientes;
    vector <Medico> medicos;
    VerificaDados verificacao;
    

    do{
        cout << ">>> BEM-VINDO(A) A CLINICA SEM DODOI <<<" << endl;
        cout << "[1] PACIENTES " << endl;
        cout << "[2] MEDICOS " << endl;
        cout << "[0] SAIR " << endl;
        cin >> opcao;
        cin.ignore();

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
                cin.ignore();

                switch(opcaoSubMenu){
                    case 0:
                    break;

                    case 1:
                        {   system("cls");
                            string nome, cpf;
                            int dia, mes, ano;

                            cout << "------- INSERIR PACIENTE -------" << endl;
                            cout << "Informe o nome do paciente: " << endl;
                            getline(cin,nome);
                            cout << "Informe o CPF do paciente (apenas digitos): " << endl;
                            getline(cin,cpf);
                            /*
                                Verificação do CPF:
                                1 - Verificar se o CPF tem 11 digitos, considerando
                                    que seja passando apenas números.
                                2 - Verificar se foram passandos apenas digitos.
                                3 - Verificar se o passando já está inserido.
                            */

                            if(verificacao.verificacaoCpf(pacientes, cpf)){
                                cout << "Informe o dia do seu nascimento: " << endl;
                                cin >> dia;
                                cout << "Informe o mes do seu nascimento: " << endl;
                                cin >> mes;
                                cout << "Informe o ano do seu nascimento: " << endl;
                                cin >> ano;

                                if(verificacao.verificacaoData(dia, mes, ano)){
                                    Data data(dia, mes, ano);
                                    Paciente paciente(nome, cpf, data);
                                    paciente.incluir(pacientes, paciente);
                                    system("cls");
                                    cout << "Paciente inserido com sucesso!" << endl;
                                }else{
                                    cout << "Data invalida..." << endl;
                                }

                            }else{
                                //Mostra um feedback do que foi preenchido errado
                                if(!verificacao.getVerificaTamanhoCpf()){
                                    cout << "1 - CPF com digitos a mais ou a menos" << endl;
                                }

                                if(!verificacao.getVerificaDigito()){
                                    cout << "2 - CPF com digitos invalidos" << endl;
                                }

                                if(!verificacao.getVerificaCpfCadastrado()){
                                    cout << "3 - CPF ja cadastrado" << endl;
                                }
                            }
                            cout << "----------------------------------" << endl;
                            
                        }
                    break;

                    case 2:
                        {
                            system("cls");
                            string cpfProcurado;
                            int indice;

                            cout << "------- EXCLUIR PACIENTE -------" << endl;
                            cout << "Informe o CPF do paciente: " << endl;
                            getline(cin, cpfProcurado);
                            indice = localizarPorCpf(pacientes, cpfProcurado);

                            if(indice != -1){
                                cout << "Paciente de nome: " << pacientes[indice].getNomePaciente() << " excluido." << endl;
                                pacientes.erase(pacientes.begin() + indice);
                            }else{
                                cout << "Paciente nao encontrado..." << endl;
                            }
                             cout << "----------------------------------" << endl;

                        }
                    break;

                    case 3:
                        { //Implementação aqui

                        }
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
                        {
                        system("cls");
                        string cpfProcurado;
                        int indice;

                        //usar o metodo da própria classe 

                        cout << "------- LOCALIZAR PACIENTE -------" << endl;
                        cout << "Informe o CPF do paciente: " << endl;
                        getline(cin, cpfProcurado);
                        indice = localizarPorCpf(pacientes, cpfProcurado);
                        if(indice != -1){
                            cout << "Nome: " << pacientes[indice].getNomePaciente() << endl;
                            cout << "CPF: " << pacientes[indice].getCpf() << endl;
                            cout << "Data de Nascimento: " << pacientes[indice].getDtNascimento().getDia();
                            cout << " / " << pacientes[indice].getDtNascimento().getMes();
                            cout << " / " << pacientes[indice].getDtNascimento().getAno() << endl;
                        }else{
                            cout << "Paciente nao encontrado..." << endl;
                        }
                        cout << "----------------------------------" << endl;

                        }
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